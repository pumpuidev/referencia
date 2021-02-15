package snake; //palya elmentese

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Point;
import java.io.IOException;
import javax.swing.*;
import res.ResourceLoader;

public class BoardPanel extends JPanel {

    private final Image img;
    private final Image apple;
    private final Image brick;

    public static final int COL_COUNT = 30;

    public static final int ROW_COUNT = 30;

    public static final int TILE_SIZE = 20;

    private static final int EYE_LARGE_INSET = TILE_SIZE / 3;

    private static final int EYE_SMALL_INSET = TILE_SIZE / 6;

    private static final int EYE_LENGTH = TILE_SIZE / 5;

    private static final Font FONT = new Font("Tahoma", Font.BOLD, 25);

    private SnakeGame game;

    private TileType[] tiles;

    public BoardPanel(SnakeGame game) throws IOException {      //konstruktor
        this.game = game;
        this.tiles = new TileType[ROW_COUNT * COL_COUNT];
        img = ResourceLoader.loadImage("res/background.png");
        apple = ResourceLoader.loadImage("res/apple.png");
        brick = ResourceLoader.loadImage("res/brick.jpeg");
        setPreferredSize(new Dimension(COL_COUNT * TILE_SIZE, ROW_COUNT * TILE_SIZE));
    }

    public void clearBoard() {                              //kocka lenullaz
        for (int i = 0; i < tiles.length; i++) {
            tiles[i] = null;
        }
    }

    public void setTile(Point point, TileType type) {       //kocka tipusa pontba
        setTile(point.x, point.y, type);
    }

    public void setTile(int x, int y, TileType type) {      //koordinata
        tiles[y * ROW_COUNT + x] = type;
    }

    public TileType getTile(int x, int y) {
        return tiles[y * ROW_COUNT + x];
    }

    @Override
    public void paintComponent(Graphics g) {            //palya kirajzolas
        super.paintComponent(g);
        Graphics2D gr = (Graphics2D) g;

        gr.drawImage(img, 0, 0, COL_COUNT * TILE_SIZE, COL_COUNT * TILE_SIZE, null);
        
        for (int x = 0; x < COL_COUNT; x++) {
            for (int y = 0; y < ROW_COUNT; y++) {
                TileType type = getTile(x, y);
                if (type != null) {
                    drawTile(x * TILE_SIZE, y * TILE_SIZE, type, g);
                }
            }
        }

        if (game.isGameOver() || game.isNewGame()) {        //uj jatek 
            g.setColor(Color.BLACK);

            int centerX = getWidth() / 2;
            int centerY = getHeight() / 2;

            String largeMessage = null;
            String smallMessage = null;
            if (game.isNewGame()) {
                largeMessage = "New Game";
                smallMessage = "Press ENTER to start!";     //kiir
            } else if (game.isGameOver()) {
                largeMessage = "Game Over";
                smallMessage = "Press ENTER to start!";
            }

            g.setFont(FONT);
            g.drawString(largeMessage, centerX - g.getFontMetrics().stringWidth(largeMessage) / 2, centerY - 50);
            g.drawString(smallMessage, centerX - g.getFontMetrics().stringWidth(smallMessage) / 2, centerY + 50);
        }
    }

    private void drawTile(int x, int y, TileType type, Graphics g) {    //ikon beallit

        switch (type) {

        case Fruit:
            g.drawImage(apple, x + 2, y + 2, TILE_SIZE - 4, TILE_SIZE - 4, null);
            break;
        case Brick:
            g.drawImage(brick, x + 2, y + 2, TILE_SIZE - 3, TILE_SIZE - 3, null);
            break;

        case SnakeBody:                         //zold kocka
            g.setColor(Color.GREEN);
            g.fillRect(x, y, TILE_SIZE, TILE_SIZE);
            break;

        case SnakeHead:                         //csik a szemeknek
            g.setColor(Color.GREEN);
            g.fillRect(x, y, TILE_SIZE, TILE_SIZE);

            g.setColor(Color.BLACK);

            switch (game.getDirection()) {
            case North: {                       //fej pozicionalas
                int baseY = y + EYE_SMALL_INSET;
                g.drawLine(x + EYE_LARGE_INSET, baseY, x + EYE_LARGE_INSET, baseY + EYE_LENGTH);
                g.drawLine(x + TILE_SIZE - EYE_LARGE_INSET, baseY, x + TILE_SIZE - EYE_LARGE_INSET, baseY + EYE_LENGTH);
                break;
            }

            case South: {                       //fej pozicio
                int baseY = y + TILE_SIZE - EYE_SMALL_INSET;
                g.drawLine(x + EYE_LARGE_INSET, baseY, x + EYE_LARGE_INSET, baseY - EYE_LENGTH);
                g.drawLine(x + TILE_SIZE - EYE_LARGE_INSET, baseY, x + TILE_SIZE - EYE_LARGE_INSET, baseY - EYE_LENGTH);
                break;
            }

            case West: {        //fej pozicio
                int baseX = x + EYE_SMALL_INSET;
                g.drawLine(baseX, y + EYE_LARGE_INSET, baseX + EYE_LENGTH, y + EYE_LARGE_INSET);
                g.drawLine(baseX, y + TILE_SIZE - EYE_LARGE_INSET, baseX + EYE_LENGTH, y + TILE_SIZE - EYE_LARGE_INSET);
                break;
            }

            case East: {        //fej pozicio
                int baseX = x + TILE_SIZE - EYE_SMALL_INSET;
                g.drawLine(baseX, y + EYE_LARGE_INSET, baseX - EYE_LENGTH, y + EYE_LARGE_INSET);
                g.drawLine(baseX, y + TILE_SIZE - EYE_LARGE_INSET, baseX - EYE_LENGTH, y + TILE_SIZE - EYE_LARGE_INSET);
                break;
            }

            }
            break;
        }
    }
}
