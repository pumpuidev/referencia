package Attores;

public class Board {
    byte size;
    Player[][] tile;
    int fromX;
    int fromY;
    int toX;
    int[] toY;
    
    public Board(byte size) {
        this.size = size;
        toY = new int[3];
        for (int i = 0; i < 3; ++i) {
            toY[i] = -1;
        }
        toX = -1;
        fromX = -1;
        fromY = -1;
        tile = new Player[size][size];
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i < 2) {
                    tile[i][j] = Player.BLACK;
                } else if (i > size - 3) {
                    tile[i][j] = Player.WHITE;
                } else {
                tile[i][j] = Player.NONE;
            }
            }
        }
    }
    
    void pressed(int x, int y) {
        fromX = x;
        fromY = y;
    }
    
    boolean canMoveTo(int i, int j) {
        return (toX == i) && (toY[0] == j || toY[1] == j || toY[2] == j);
    }
    
    void moveTo(int x, int y) {
        if (tile[fromX][fromY] == Player.WHITE) tile[x][y] =  Player.WHITE;
        else if (tile[fromX][fromY] == Player.BLACK) tile[x][y] = Player.BLACK;
        tile[fromX][fromY] = Player.NONE;
    }
    
    void reset() {
        toX = -1;
        for (int i = 0; i < 3; ++i) {
            toY[i] = -1;
        }
        fromX = -1;
        fromY = -1;
    }

    void calcMoves(int x, int y) {
        fromX = x;
        fromY = y;
        if (tile[x][y] == Player.BLACK) {
            toX = x + 1;
        } else {
            toX = x -1 ;
        }
        if (y - 1 >= 0) if(tile[toX][y - 1] != Player.NONE && tile[toX][y - 1] != tile[fromX][fromY]) toY[0] = y - 1;
        if (tile[toX][y] == Player.NONE) toY[1] = y;
        if (y + 1 < size) if(tile[toX][y + 1] != Player.NONE && tile[toX][y + 1] != tile[fromX][fromY]) toY[2] = y + 1;
    }
}
