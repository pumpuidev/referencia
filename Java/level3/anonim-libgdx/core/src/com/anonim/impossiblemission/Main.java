package com.anonim.impossiblemission;

import com.anonim.impossiblemission.loader.GameAssetManager;
import com.anonim.impossiblemission.views.*;
import com.badlogic.gdx.Game;
import com.badlogic.gdx.Screen;

// TODO class diagram, userdoc, testcases

/**
 * 	Main orchestrator class of the game
 * 	@author anonim
 *	@version 1.0
 */
public class Main extends Game {
	/** These represent the applications different screens
	 */
	private MenuScreen menuScreen;
	private SettingsScreen settingsScreen;
	private HighscoreScreen highscoreScreen;
	private DifficultyScreen difficultyScreen;
	private GameScreen gameScreen;
	private EndScreen endScreen;

	/**
	 * Represents game settings
	 */
	private AppPreferences appPreferences;
	/**
	 * Game asset manager
	 */
	public GameAssetManager assetManager = new GameAssetManager();

	@Override
	public void create() {
		Screen loadingScreen = new LoadingScreen(this);
		setScreen(loadingScreen);
		appPreferences = new AppPreferences();
	}

	/**
	 * Changes the screen to the actual game screen, overload of changeScreen(Screen screen)
	 * @param data Satellite data, used to determine game difficulty
	 */
	public void changeScreen(int data) {
		if(gameScreen == null) gameScreen = new GameScreen(this, data);
		this.setScreen(gameScreen);
	}

	/**
	 * Used to change screens
	 * @param screen Actual screen to switch to
	 */
	public void changeScreen(Screens screen) {
		switch (screen) {
			case MENU:
				if(menuScreen == null) menuScreen = new MenuScreen(this);
				this.setScreen(menuScreen);
				break;
			case SETTINGS:
				if(settingsScreen == null) settingsScreen = new SettingsScreen(this);
				this.setScreen(settingsScreen);
				break;
			case HS:
				if(highscoreScreen == null) highscoreScreen = new HighscoreScreen(this);
				this.setScreen(highscoreScreen);
				break;
			case DIFFICULITY:
				if(difficultyScreen == null) difficultyScreen = new DifficultyScreen(this);
				this.setScreen(difficultyScreen);
				break;
		}
	}

	/**
	 * Changes the screen to the endgame screen, overload of changeScreen(Screen screen)
	 * @param conclusion Conclusion of the game, true if lost, false if won
	 * @param time Remaining game time
	 * @param difficulty Game difficulty
	 */
	public void changeScreen(boolean conclusion, int time, int difficulty) {
		if(endScreen == null) endScreen = new EndScreen(this, conclusion, time, difficulty);
		this.setScreen(endScreen);
	}

	/**
	 * Used to get the game settings
	 * @return Saved settings data
	 */
	public AppPreferences getPreferences() {
		return this.appPreferences;
	}

	/**
	 * Method to get the gameScreen from other classes
	 * @return The main GameScreen
	 */
	public GameScreen getGameScreen() {
		return gameScreen;
	}
}
