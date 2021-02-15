package snake; //azonosito

public class GameID {

    public final int score;
    public final String name;

    public GameID( int score, String name) {
        this.score = score;
        this.name = name;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 29 * hash + this.score;
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
        final GameID other = (GameID) obj;
        if (this.name != other.name) {
            return false;
        }
        return true;
    }

}
