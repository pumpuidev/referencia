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
import com.badlogic.gdx.scenes.scene2d.InputEvent;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.*;
import com.badlogic.gdx.scenes.scene2d.utils.ChangeListener;
import com.badlogic.gdx.scenes.scene2d.utils.ClickListener;

/**
 * Represents the ending {@link Screen} GUI
 */
public class EndScreen implements Screen {

    private Main main;

    private Stage stage;
    private SpriteBatch spriteBatch;

    private TextureAtlas textureAtlas;
    private Skin skin;

    private Database database;

    private boolean isLost;
    private int time, difficulty;

    public EndScreen(Main main, boolean conclusion, int time, int difficulty) {
        this.main = main;

        stage = new Stage();
        spriteBatch = new SpriteBatch();

        textureAtlas = main.assetManager.getGameAtlas();
        skin = main.assetManager.getSkin();

        database = Database.getInstance();

        isLost = conclusion;
        this.time = time;
        this.difficulty = difficulty;
    }

    @Override
    public void show() {

        Gdx.input.setInputProcessor(stage);

        Table table = new Table();
        table.setFillParent(true);

        Label greetingLabel = new Label("", skin), textLabel = new Label("", skin);
        // TextButton menu = new TextButton("MENU", skin);
        TextButton exit = new TextButton("EXIT", skin);

        final TextField name = new TextField("Input initials...", skin);
        name.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                name.setText("AAA");
            }
        });
        name.setMaxLength(3);

        final TextButton submit = new TextButton("Submit", skin);
        submit.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                String text = name.getText();
                if(text.equals("Input initials...")) text = "AAA";
                database.add(new HighScore(text.toUpperCase(),
                        time,
                        difficulty), true);
                name.setVisible(false);
                submit.setVisible(false);
            }
        });


        /*menu.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                main.changeScreen(Screens.MENU, 0);
            }
        });*/

        exit.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                Gdx.app.exit();
            }
        });

        greetingLabel.setFontScale(2);

        if(isLost) {
            greetingLabel.setText("YOU LOSE");
            textLabel.setText("Better luck next time!");
        }
        else {
            greetingLabel.setText("YOU WIN");
            textLabel.setText("Congratulations!");

        }

        table.add(greetingLabel).pad(0, 0, 30, 0);
        table.row();
        table.add(textLabel).pad(0, 0, 20, 0);
        table.row();
        // table.add(menu).fillX().uniformX().pad(0, 0, 0, 10);
        table.add(exit).fillX().uniformX();
        table.row().pad(10);
        table.add(name).fillX().uniformX();
        table.row().pad(10);
        table.add(submit).fillX().uniformX();

        stage.addActor(table);
    }

    @Override
    public void render(float delta) {
        Gdx.gl.glClearColor(0,0,0,1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

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
        stage.dispose();
    }
}
