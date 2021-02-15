package com.anonim.impossiblemission.database;

import com.anonim.impossiblemission.views.DifficultyScreen;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.files.FileHandle;
import com.badlogic.gdx.utils.Json;

import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * This singleton class handles database operations for the game.
 * It writes/reads highscore data to/from a file in the assets folder.
 * @author anonim
 * @version 1.0
 */
public class Database {
    /**
     * {@link Json} utility field
     */
    private Json database;
    /**
     * {@link HighScore} queues
     */
    private PriorityQueue<HighScore> easy, medium, hard, all;
    /**
     * Database file handle
     */
    private FileHandle f;
    /**
     * Singleton class instance
     */
    private static Database ourInstance = new Database();

    public static Database getInstance() {
        return ourInstance;
    }

    private Database() {
        easy = new PriorityQueue<HighScore>();
        medium = new PriorityQueue<HighScore>();
        hard = new PriorityQueue<HighScore>();
        all = new PriorityQueue<HighScore>();

        database = new Json();
        f = Gdx.files.local("database.db");
        if(f.length() == 0) return;

        Scanner sc = new Scanner(f.reader());

        int n = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < n; i++) {
            String jsonString = sc.nextLine();
            // System.out.println(jsonString);
            add(database.fromJson(HighScore.class, jsonString), false);
        }
        sc.close();

        // System.out.println("Loaded these:\n" + all);
    }

    /**
     * Method for adding {@link HighScore} instances to the queues
     * @param hs {@link HighScore} instance to add
     * @param saveIt whether or not to save the stored data to the database file
     */
    public void add(HighScore hs, boolean saveIt) {
        if(hs == null) return;

        switch(hs.difficulty) {
            case DifficultyScreen.EASY:
                easy.add(hs);
                break;
            case DifficultyScreen.MEDIUM:
                medium.add(hs);
                break;
            case DifficultyScreen.HARD:
                hard.add(hs);
                break;
        }
        all.add(hs);
        if(saveIt) save();
    }

    /**
     * Method to wipe database
     */
    public void clear() {
        easy.clear();
        medium.clear();
        hard.clear();
        all.clear();
        save();
    }

    /**
     * Method to save cached data to file
     */
    private void save() {
        // System.out.println("Saving these:\n" + all.toString());
        PrintWriter pw = new PrintWriter(f.writer(false));
        pw.println(all.size());

        for(HighScore hs : all) {
            String jsonString = database.toJson(hs);
            pw.println(jsonString);
        }

        pw.flush();
        pw.close();
    }

    /**
     * Getter for easy difficulty {@link HighScore}s
     * @return A {@link PriorityQueue} storing all the highscores with easy difficulty
     */
    public PriorityQueue<HighScore> getEasy() {
        return easy;
    }

    /**
     * Getter for medium difficulty {@link HighScore}s
     * @return A {@link PriorityQueue} storing all the highscores with medium difficulty
     */
    public PriorityQueue<HighScore> getMedium() {
        return medium;
    }

    /**
     * Getter for hard difficulty {@link HighScore}s
     * @return A {@link PriorityQueue} storing all the highscores with hard difficulty
     */
    public PriorityQueue<HighScore> getHard() {
        return hard;
    }
}
