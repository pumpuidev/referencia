package Attores;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.Color;
import java.net.URL;
import javax.swing.AbstractAction;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JLabel;
import static javax.swing.WindowConstants.DO_NOTHING_ON_CLOSE;

public class Window extends JFrame {
    Player currentPlayer = Player.WHITE;
    JLabel playerLabel = new JLabel("Current Player: WHITE");
    JPanel playerPanel = new JPanel();
    Board board;
    ImageIcon black, white;
    byte size;
    JPanel p = new JPanel();
    JMenuBar menubar = new JMenuBar();
    JMenuItem item;
    JButton[][] tiles;
    
    public Window(byte size) {
        super("Chess With Pawns");
        black = new ImageIcon(this.getClass().getResource("black.png"));
        white = new ImageIcon(this.getClass().getResource("white.png"));
        this.size = size;
        setSize(70*size, 70*size);
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        addWindowListener(new WindowAdapter() {

            @Override
            public void windowClosing(WindowEvent e) {
                showExitConfirmation();
            }

        });
        setResizable(false);
        
        board = new Board(size);
        tiles = new JButton[size][size];
        p.setLayout(new GridLayout(size, size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                addButton(p, i, j);
            }
        }
        getContentPane().setLayout(new BorderLayout());
        getContentPane().add(p, BorderLayout.CENTER);
        URL url = Window.class.getResource("icon.png");
        setIconImage(Toolkit.getDefaultToolkit().getImage(url));
        
        item = new JMenuItem(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showNewGameConfirmation();
            }
        });
        item.setText("New Game");
        menubar.add(item);
        setJMenuBar(menubar);
        playerPanel.add(playerLabel);
        getContentPane().add(playerPanel, BorderLayout.SOUTH);
        add(p);
        setVisible(true);
    }
    
    private void addButton(JPanel p, int i, int j) {
        tiles[i][j] = new JButton();
        if (i < 2) {
            tiles[i][j].setIcon(black);
        } else if (i > size - 3) {
            tiles[i][j].setIcon(white);
        }
        
        p.add(tiles[i][j]);

        tiles[i][j].addMouseListener(new MouseAdapter() {

            @Override
            public void mouseClicked(MouseEvent e) {
                if (board == null) {
                    return;
                }
                
                if (e.getButton() == MouseEvent.BUTTON1) {
                    if (tiles[i][j].getBackground() == Color.ORANGE) {
                        if (board.tile[board.fromX][board.fromY] == Player.WHITE && i == 0) {
                            doUponExit();
                            new GameOver(true);
                        }
                        else if (board.tile[board.fromX][board.fromY] == Player.BLACK && i == size - 1) {
                            doUponExit();
                            new GameOver(false);
                        }
                        board.moveTo(i, j);
                        updateBoard(i, j, board.fromX, board.fromY);
                        nextPlayer();
                    } else if (currentPlayer == board.tile[i][j]) {
                        resetHighlight();
                        board.fromX = i;
                        board.fromY = j;
                        board.calcMoves(i, j);
                        if (board.tile[i][j] != Player.NONE) highlight();
                    }
                }
            }

        });

    }
    
    void nextPlayer() {
        if (currentPlayer == Player.WHITE) {
            playerLabel.setText("Current Player: BLACK");
            currentPlayer = Player.BLACK;
        }
        else {
            playerLabel.setText("Current Player: WHITE");
            currentPlayer = Player.WHITE;
        }
    }
    
    void resetHighlight() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board.canMoveTo(i, j)) tiles[i][j].setBackground(null);
            }
        }
    }
    
    void highlight() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board.canMoveTo(i, j)) tiles[i][j].setBackground(Color.ORANGE);
            }
        }
    }
    
    void updateBoard(int toX, int toY, int fromX, int fromY) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board.tile[i][j] == Player.NONE) tiles[i][j].setIcon(null);
                else if (board.tile[i][j] == Player.WHITE) tiles[i][j].setIcon(white);
                else if (board.tile[i][j] == Player.BLACK) tiles[i][j].setIcon(black);
            }
        }
        resetHighlight();
        board.reset();
    }
    
    protected void showExitConfirmation() {
        int n = JOptionPane.showConfirmDialog(this, "Are you sure?",
            "Exit", JOptionPane.YES_NO_OPTION);
        if (n == JOptionPane.YES_OPTION) {
            doUponExit();
        }
    }
    
    private void showNewGameConfirmation() {
        int n = JOptionPane.showConfirmDialog(this, "Are you sure?",
            "New Game", JOptionPane.YES_NO_OPTION);
        if (n == JOptionPane.YES_OPTION) {
            doUponExit();
            new AskSize();
        }
    }
    
    protected void doUponExit() {
        this.dispose();
    }   
}
