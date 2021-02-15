package snake; //fo resz

import database.Database;
import java.awt.BorderLayout;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Random;
import javax.swing.AbstractAction;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.Timer;

public class SnakeGame extends JFrame {

    private static final long FRAME_TIME = 100L / 50L;

    private static final int MIN_SNAKE_LENGTH = 1;

    private BoardPanel board;

    private Random random;
    
    private Timer timer;

    private Clock logicTimer;

    private boolean isNewGame;

    private boolean isGameOver;

    private boolean isPaused;

    private LinkedList<Point> snake;

    private LinkedList<Direction> directions;

    private int score = 0;
    
    private int time = 0;
    
    JLabel label = new JLabel("Score: " + score + " | Time: 0");
    
    private Database database = new Database();

    private SnakeGame() throws IOException { //menu letrehozasa
        super("Snake");
        setLayout(new BorderLayout());

        JMenuBar menuBar = new JMenuBar();
        JMenu menuGame = new JMenu("Game");
        JMenuItem newGame = new JMenuItem(new AbstractAction("New Game") {
            @Override
            public void actionPerformed(ActionEvent e) {
                resetGame();
            }
        });

        JMenuItem highScores = new JMenuItem(new AbstractAction("Scores") {
            @Override
            public void actionPerformed(ActionEvent e) {
                new HighScoreWindow(database.getHighScores(), SnakeGame.this);   
            }
        });

        JMenuItem menuGameExit = new JMenuItem(new AbstractAction("Exit") {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        menuGame.add(newGame);
        menuGame.add(highScores);
        menuGame.add(menuGameExit);
        menuBar.add(menuGame);
        
        timer = new Timer(1000, new ActionListener(){   //idot szamol
            @Override
            public void actionPerformed(ActionEvent e) {
                ++time;
                label.setText("Score: " + score + " | Time: " + time); //ido+pont frissit
            }
        });

        add(menuBar, BorderLayout.NORTH);       //elhelyez
        add(label, BorderLayout.SOUTH);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setResizable(false);

        this.board = new BoardPanel(this);
        this.logicTimer = new Clock(9.0f);
        add(board, BorderLayout.CENTER);

        addKeyListener(new KeyAdapter() {       //gombok funkcioja

            @Override
            public void keyPressed(KeyEvent e) {
                switch (e.getKeyCode()) {

                case KeyEvent.VK_W:     //w fel
                case KeyEvent.VK_UP:    //fel nyil
                    if (!isPaused) {
                        Direction last = directions.peekLast();
                        if (last != Direction.South && last != Direction.North) {
                            directions.addLast(Direction.North);
                        }
                    }
                    break;

                case KeyEvent.VK_S:
                case KeyEvent.VK_DOWN:
                    if (!isPaused) {
                        Direction last = directions.peekLast();
                        if (last != Direction.North && last != Direction.South) {
                            directions.addLast(Direction.South);
                        }
                    }
                    break;

                case KeyEvent.VK_A:
                case KeyEvent.VK_LEFT:
                    if (!isPaused) {
                        Direction last = directions.peekLast();
                        if (last != Direction.East && last != Direction.West) {
                            directions.addLast(Direction.West);
                        }
                    }
                    break;

                case KeyEvent.VK_D:
                case KeyEvent.VK_RIGHT:
                    if (!isPaused) {
                        Direction last = directions.peekLast();
                        if (last != Direction.West && last != Direction.East) {
                            directions.addLast(Direction.East);
                        }
                    }
                    break;

                case KeyEvent.VK_ENTER:         //jatek indit
                    if (isNewGame || isGameOver) {
                        resetGame();
                    }
                    break;
                }
            }

        });

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void startGame() {
        
        this.random = new Random();
        this.snake = new LinkedList<>();
        this.directions = new LinkedList<>();
        this.isNewGame = true;

        logicTimer.setPaused(true);

        while (true) {

            long start = System.nanoTime();

            logicTimer.update();

            if (logicTimer.hasElapsedCycle()) {
                updateGame();
            }

            board.repaint();

            long delta = (System.nanoTime() - start) / 1000000L;    //ido szamlalo
            if (delta < FRAME_TIME) {
                try {
                    Thread.sleep(FRAME_TIME - delta);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private void updateGame() {

        TileType collision = updateSnake();

        if (collision == TileType.Fruit) {
            score++;
            label.setText("Score: " + score + " | Time: " + time);
            spawnFruit();                           //uj gyumolcs
            spawnBrick();                           //uj ko
        } else if (collision == TileType.SnakeBody || collision == TileType.Brick) {
            isGameOver = true;                  //utkozes jatek vege
            logicTimer.setPaused(true);
            timer.stop();
            
            PopUpWindow pW = new PopUpWindow(); //ablak felugrik
            GameID id = new GameID(score, pW.getName());
            database.storeToDatabase(id, score, pW.getName());
        }
    }

    private TileType updateSnake() {        //kigyo teste frissit

        Direction direction = directions.peekFirst();

        Point head = new Point(snake.peekFirst());
        switch (direction) {
        case North:
            --head.y;
            break;

        case South:
            ++head.y;
            break;

        case West:
            --head.x;
            break;

        case East:
            ++head.x;
            break;
        }

        if (head.x < 0 || head.x >= BoardPanel.COL_COUNT || head.y < 0 || head.y >= BoardPanel.ROW_COUNT) {
            return TileType.SnakeBody;
        }

        TileType old = board.getTile(head.x, head.y);
        if (old != TileType.Fruit && snake.size() > MIN_SNAKE_LENGTH) {
            Point tail = snake.removeLast();
            board.setTile(tail, null);
            old = board.getTile(head.x, head.y);
        }

        if (old != TileType.SnakeBody) {
            board.setTile(snake.peekFirst(), TileType.SnakeBody);
            snake.push(head);
            board.setTile(head, TileType.SnakeHead);
            if (directions.size() > 1) {
                directions.poll();
            }
        }

        return old;
    }

    private void resetGame() {
        time = 0;
        label.setText("Score: 0" + " | Time: 0");
        timer.restart();

        this.score = 0;

        this.isNewGame = false;
        this.isGameOver = false;

        Point head = new Point(BoardPanel.COL_COUNT / 2, BoardPanel.ROW_COUNT / 2);

        snake.clear();
        snake.add(head);

        board.clearBoard();
        board.setTile(head, TileType.SnakeHead);

        directions.clear();
        Random random = new Random();
        int r = random.nextInt(4);
        directions.add(Direction.values()[r]);
        logicTimer.reset();

        spawnFruit();
        spawnBrick();
    }

    public boolean isNewGame() {
        return isNewGame;
    }

    public boolean isGameOver() {
        return isGameOver;
    }

    private void spawnFruit() {

        int index = random.nextInt(BoardPanel.COL_COUNT * BoardPanel.ROW_COUNT - snake.size());

        int freeFound = -1;
        for (int x = 0; x < BoardPanel.COL_COUNT; x++) {
            for (int y = 0; y < BoardPanel.ROW_COUNT; y++) {
                TileType type = board.getTile(x, y);
                if (type == null || type == TileType.Fruit) {
                    if (++freeFound == index) {
                        board.setTile(x, y, TileType.Fruit);
                        break;
                    }
                }
            }
        }
    }

    private void spawnBrick() {

        int index = random.nextInt(BoardPanel.COL_COUNT * BoardPanel.ROW_COUNT - snake.size());

        int freeFound = -1;
        for (int x = 0; x < BoardPanel.COL_COUNT; x++) {
            for (int y = 0; y < BoardPanel.ROW_COUNT; y++) {
                TileType type = board.getTile(x, y);
                if (type == null || type == TileType.Brick) {
                    if (++freeFound == index) {
                        board.setTile(x, y, TileType.Brick);
                        break;
                    }
                }
            }
        }
    }

    public int getFruitsEaten() {
        return score;
    }

    public Direction getDirection() {
        return directions.peek();
    }

    public static void main(String[] args) throws IOException {
        SnakeGame snake = new SnakeGame();
        snake.startGame();
    }
}
