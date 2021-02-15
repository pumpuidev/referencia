package com.anonim.impossiblemission.database;

import com.anonim.impossiblemission.GameUtils;

/**
 * A class representing a players highscore
 */
public class HighScore implements Comparable<HighScore> {
    /**
     * Player name
     * (usually 3 uppercase characters)
     */
    private String name;
    /**
     * Remaining time
     */
    private int time;
    /**
     * Date of creation
     */
    private long date;
    /**
     * Game difficulity
     */
    int difficulty;

    public HighScore(String name, int time, int difficulty) {
        this.name = name;
        this.time = time;
        this.date = System.currentTimeMillis();
        this.difficulty = difficulty;
    }

    public HighScore() {
        this.name = "";
        this.time = -1;
        this.date = -1;
        this.difficulty = -1;
    }

    /**
     * Comparing method to use for storing in {@link java.util.PriorityQueue}.
     * Sorts by remaining time first, then date of creation, then name
     * @param o Object to compare
     * @return 1 if higher, 0 if equal, -1 if lower
     */
    @Override
    public int compareTo(HighScore o) {
        if(this.time > o.time) return 1;
        else if(this.time < o.time) return -1;
            else if(this.date < o.date) return 1;
            else if(this.date > o.date) return -1;
                return this.name.compareTo(o.name);
    }

    /**
     * Formatted toString(), for display in GUI
     * @return Higyhscore in "[name] - [MM] min, [SS] sec" format
     */
    @Override
    public String toString() {
        return name + " - " + GameUtils.timerFormatter(time);
    }
}
