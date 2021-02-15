package com.anonim.impossiblemission.views;

import com.anonim.impossiblemission.Main;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.g2d.TextureAtlas;
import com.badlogic.gdx.scenes.scene2d.Actor;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.Skin;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.scenes.scene2d.ui.TextButton;
import com.badlogic.gdx.scenes.scene2d.utils.ChangeListener;
import com.badlogic.gdx.scenes.scene2d.utils.TextureRegionDrawable;

/**
 * Represents the difficulty {@link Screen} GUI
 */
public class DifficultyScreen implements Screen {
    public static final int EASY = 0;
    public static final int MEDIUM = 1;
    public static final int HARD = 2;

    private Main main;

    private Stage stage;
    private SpriteBatch spriteBatch;

    private TextureAtlas textureAtlas;
    private Skin skin;

    public DifficultyScreen(Main main) {
        this.main = main;

        stage = new Stage();
        spriteBatch = new SpriteBatch();

        textureAtlas = main.assetManager.getLoadingAtlas();
        skin = main.assetManager.getSkin();
    }

    @Override
    public void show() {
        Gdx.input.setInputProcessor(stage);

        Table table = new Table();
        table.setFillParent(true);
        table.setBackground(new TextureRegionDrawable(textureAtlas.findRegion("menuBG")));

        TextButton easy, medium, hard, back;

        easy = new TextButton("Easy", skin);
        medium = new TextButton("Medium", skin);
        hard = new TextButton("Hard", skin);

        back = new TextButton("Back", skin);

        easy.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                main.changeScreen(EASY);
            }
        });

        medium.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                main.changeScreen(MEDIUM);
            }
        });

        hard.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                main.changeScreen(HARD);
            }
        });

        back.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                main.changeScreen(Screens.MENU);
            }
        });

        table.add(easy).fillX().uniformX().pad(300, 0, 0, 20);
        table.add(medium).fillX().uniformX().pad(300, 0, 0, 20);
        table.add(hard).fillX().uniformX().pad(300, 0, 0, 20);
        table.row();
        table.add(back).pad(5).colspan(3);

        stage.addActor(table);
    }

    @Override
    public void render(float delta) {
        Gdx.gl.glClearColor(0f, 0f, 0f, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

        spriteBatch.begin();
        spriteBatch.draw(textureAtlas.findRegion("menuBG"), 0, 0, stage.getWidth(), stage.getHeight());
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
        stage.dispose();
    }
}
