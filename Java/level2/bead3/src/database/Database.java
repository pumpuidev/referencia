package database; //adatbazis megirasa

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.HashMap;
import snake.GameID;

public class Database {

    private final String tableName = "top10";
    private final Connection conn;
    private final HashMap<GameID, Integer> highScores;

    public Database() {
        Connection c = null;
        try {
            c = ConnectionFactory.getConnection();
        } catch (Exception ex) {
            System.out.println("No connection");
        }
        this.conn = c;
        highScores = new HashMap<>();
        loadHighScores();
    }

    public boolean storeHighScore(GameID id, int newScore) {
        return mergeHighScores(id, newScore, newScore > 0);
    }

    public ArrayList<HighScore> getHighScores() {

        ArrayList<HighScore> scores = new ArrayList<>();
        for (GameID id : highScores.keySet()) {
            HighScore h = new HighScore(id, highScores.get(id), id.name);

            scores.add(h);

        }
        return scores;
    }

    private void loadHighScores() {

        try (Statement stmt = conn.createStatement()) {
            ResultSet rs = stmt.executeQuery("SELECT * FROM " + tableName);

            while (rs.next()) {
                String name = rs.getString("NAME");
                int score = rs.getInt("SCORE");
                GameID id = new GameID(score, name);
                mergeHighScores(id, score, false);
            }
        } catch (Exception e) {
            System.out.println("loadHighScores error" + e + " + " + e.getClass());
        }

    }

    private boolean mergeHighScores(GameID id, int score, boolean store) {

        boolean doUpdate = true;
        if (highScores.containsKey(id)) {
            int oldScore = highScores.get(id);
            doUpdate = ((score < oldScore && score != 0) || oldScore == 0);
        }
        if (doUpdate) {
            highScores.remove(id);
            highScores.put(id, score);
            if (store) {
                return storeToDatabase(id, score, "Asd") > 0;
            }
            return true;
        }
        return false;
    }

    public int storeToDatabase(GameID id, int score, String name) {

        try (Statement stmt = conn.createStatement()) {
            String s = "INSERT INTO " + tableName
                    + " (NAME, SCORE) "
                    + "VALUES('" + name
                    + "'," + score
                    + ") ON DUPLICATE KEY UPDATE Score=" + score;
            highScores.put(id, score);
            return stmt.executeUpdate(s);
        } catch (Exception e) {
            System.out.println(e + " " + e.getClass());
            System.out.println("storeToDatabase error");
        }
        return 0;
    }

}
