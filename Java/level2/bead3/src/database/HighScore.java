package database;

import snake.GameID;

public class HighScore {

    
    public final int score;
    public final String name;
    
    public HighScore(GameID gameID, int score) {
        this.score = score;
        this.name = gameID.name;
        System.out.println("name: " + name);
    }    
    
    public HighScore(GameID gameID, int score, String name) {
        this.score = score;
        this.name = name;
    }


    @Override
    public int hashCode() {
        int hash = 5;
        hash = 89 * hash + this.score;
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final HighScore other = (HighScore) obj;
        if (this.score != other.score) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "Name: " + name + " Score: " + score;
    }
}
