package com.anonim.impossiblemission;

import com.badlogic.gdx.utils.Timer;

/**
 * A simple timer class to handle the game time countdown.
 * @see Timer
 */
public class GameTimer {

    private Main main;
    private int startingTime, currentTime;
    private final Timer timer = new Timer();


    public GameTimer(final Main main, int minutes) {
        this.main = main;
        this.startingTime = minutes * 60 * 1000;
        this.currentTime = startingTime;

        timer.start();
        timer.scheduleTask(new Timer.Task() {
            @Override
            public void run() {
                currentTime -= 1000;
                if(currentTime <= 0) {
                    timer.stop();
                    main.getGameScreen().lose();
                }
            }
        }, 0, 1);
    }

    /**
     * Method used for time penalty
     * Used when player collides with enemy and when they input a wrong codeword
     * @param seconds Amount of time to subsctract from timer
     */
    public void penalty(int seconds) {
        currentTime -= seconds * 1000;
    }

    /**
     * Returns current time remaining in millisecons
     * @return Cureent time remaining
     */
    public int getCurrentTime() {
        return currentTime;
    }

    /**
     * Formats milliseconds to readable format
     * @return time in "[MM] min, [SS] sec" format
     */
    @Override
    public String toString() {
        if(currentTime <= 0) currentTime = 0;
        return GameUtils.timerFormatter(currentTime);
    }
}