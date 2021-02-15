package com.anonim.impossiblemission.views;

import com.anonim.impossiblemission.Main;
import com.anonim.impossiblemission.database.Database;
import com.anonim.impossiblemission.database.HighScore;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.g2d.TextureAtlas;
import com.badlogic.gdx.scenes.scene2d.Actor;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.*;
import com.badlogic.gdx.scenes.scene2d.utils.ChangeListener;

import java.util.PriorityQueue;

/**
 * Represents the highscore screen GUI
 */
public class HighscoreScreen implements Screen {
    private final static int EASY = 0;
    private final static int MEDIUM = 1;
    private final static int HARD = 2;

    Main main;

    Stage stage;
    SpriteBatch spriteBatch;

    TextureAtlas textureAtlas;
    Skin skin;

    Database database;
    PriorityQueue<HighScore> scoreList;

    Label label;
    TextButton left, right, back, clear;
    List<HighScore> scoreBoard;
    ScrollPane pane;

    int currentDifficulty;

    public HighscoreScreen(Main main) {
        this.main = main;

        stage = new Stage();

        spriteBatch = new SpriteBatch();
        textureAtlas = main.assetManager.getGameAtlas();
        skin = main.assetManager.getSkin();

        database = Database.getInstance();
        scoreList = database.getEasy();
        currentDifficulty = EASY;
    }

    @Override
    public void show() {
        Gdx.input.setInputProcessor(stage);
        stage.setDebugUnderMouse(true);

        label = new Label("Easy", skin);
        label.setPosition(stage.getWidth() * 0.08f, stage.getHeight() * 0.95f);

        left = new TextButton("<", skin);
        left.setPosition(stage.getWidth() * 0.08f, stage.getHeight() * 0.5f);
        left.setVisible(false);
        left.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                switch (currentDifficulty) {
                    case MEDIUM:
                        scoreList = database.getEasy();
                        scoreBoard.setItems(scoreList.toArray(new HighScore[0]));
                        currentDifficulty = EASY;
                        label.setText("Easy");
                        left.setVisible(false);
                        break;
                    case HARD:
                        scoreList = database.getMedium();
                        scoreBoard.setItems(scoreList.toArray(new HighScore[0]));
                        currentDifficulty = MEDIUM;
                        label.setText("Medium");
                        right.setVisible(true);
                        break;
                }
            }
        });



        right = new TextButton(">", skin);
        right.setPosition(stage.getWidth() * 0.811f, stage.getHeight() * 0.5f);
        right.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                switch (currentDifficulty) {
                    case EASY:
                        scoreList = database.getMedium();
                        scoreBoard.setItems(scoreList.toArray(new HighScore[0]));
                        currentDifficulty = MEDIUM;
                        label.setText("Medium");
                        left.setVisible(true);
                        break;
                    case MEDIUM:
                        scoreList = database.getHard();
                        scoreBoard.setItems(scoreList.toArray(new HighScore[0]));
                        currentDifficulty = HARD;
                        label.setText("Hard");
                        right.setVisible(false);
                        break;
                }
            }
        });


        back = new TextButton("Back", skin);
        back.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                main.changeScreen(Screens.MENU);
            }
        });
        back.setPosition(stage.getWidth() * 0.08f, stage.getHeight() * 0.105f);
        back.setSize(stage.getWidth() * 0.8f, stage.getHeight() * 0.06f);

        clear = new TextButton("Clear Highscores", skin);
        clear.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                database.clear();
            }
        });


        scoreBoard = new List<HighScore>(skin);
        scoreBoard.setItems(scoreList.toArray(new HighScore[0]));

        pane = new ScrollPane(scoreBoard, skin);
        pane.setPosition(left.getX() + left.getWidth() + 10, back.getY() + back.getHeight() + 20);
        pane.setSize(stage.getWidth() * 0.64f, stage.getHeight() * 0.729f);

        stage.addActor(label);
        stage.addActor(left);
        stage.addActor(right);
        stage.addActor(pane);
        stage.addActor(back);
    }

    @Override
    public void render(float delta) {
        Gdx.gl.glClearColor(0, 0, 0, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT | GL20.GL_DEPTH_BUFFER_BIT);

        spriteBatch.begin();
        spriteBatch.draw(textureAtlas.findRegion("settingsBG"), 0, 0, stage.getWidth(), stage.getHeight());
        spriteBatch.end();

        stage.act();
        stage.draw();
    }

    @Override
    public void resize(int width, int height) {

    }

    @Override
    public void pause() {

    }

    @Override
    public void resume() {

    }

    @Override
    public void hide() {

    }

    @Override
    public void dispose() {

    }

}
