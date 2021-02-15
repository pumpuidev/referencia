package com.anonim.impossiblemission.views;

import com.anonim.impossiblemission.Main;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.g2d.TextureAtlas;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.scenes.scene2d.Actor;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.Skin;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.scenes.scene2d.ui.TextButton;
import com.badlogic.gdx.scenes.scene2d.utils.ChangeListener;
import com.badlogic.gdx.utils.viewport.ScreenViewport;

/**
 * Represents the menu screen GUI
 */
public class MenuScreen implements Screen {
    private Main main;

    private Stage stage;

    private TextureRegion background;

    private Skin skin;

    private SpriteBatch spriteBatch;

    public MenuScreen(final Main main) {
        this.main = main;
        main.assetManager.queueAddImages();
        main.assetManager.queueAddSkin();
        main.assetManager.manager.finishLoading();

        TextureAtlas textureAtlas = main.assetManager.getLoadingAtlas();
        background = textureAtlas.findRegion("menuBG");

        skin = main.assetManager.getSkin();

        spriteBatch = new SpriteBatch();

        stage = new Stage(new ScreenViewport());
    }

    @Override
    public void show() {
        stage.clear();
        Gdx.input.setInputProcessor(stage);

        Table table = new Table();
        table.setFillParent(true);
        // table.setDebug(true);
        stage.addActor(table);

        TextButton newGame = new TextButton("New game", skin);
        TextButton settings = new TextButton("Settings", skin);
        TextButton highScores = new TextButton("High Scores", skin);
        TextButton exit = new TextButton("Exit", skin);

        table.add(newGame).fillX().uniformX().pad(300, 0, 0, 20);
        table.add(settings).fillX().uniformX().pad(300, 0, 0, 20);
        table.row();
        table.add(highScores).fillX().uniformX().pad(10, 0, 0, 20);
        table.add(exit).fillX().uniformX().pad(10, 0, 0, 20);


        newGame.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                main.changeScreen(Screens.DIFFICULITY);
            }
        });
        settings.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                main.changeScreen(Screens.SETTINGS);
            }
        });
        highScores.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                main.changeScreen(Screens.HS);
            }
        });
        exit.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                Gdx.app.exit();
            }
        });
    }

    @Override
    public void render(float delta) {
        Gdx.gl.glClearColor(0f, 0f, 0f, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

        spriteBatch.begin();
        spriteBatch.draw(background, 0, 0, stage.getWidth(), stage.getHeight());
        spriteBatch.end();

        stage.act();
        stage.draw();
    }

    @Override
    public void resize(int width, int height) {
        stage.getViewport().update(width, height, true);
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
        stage.dispose();
    }
}
