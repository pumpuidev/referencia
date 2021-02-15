package com.anonim.impossiblemission.views;

import com.anonim.impossiblemission.Main;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.g2d.TextureAtlas;
import com.badlogic.gdx.scenes.scene2d.Actor;
import com.badlogic.gdx.scenes.scene2d.Event;
import com.badlogic.gdx.scenes.scene2d.EventListener;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.*;
import com.badlogic.gdx.scenes.scene2d.utils.ChangeListener;
import com.badlogic.gdx.scenes.scene2d.utils.TextureRegionDrawable;
import com.badlogic.gdx.utils.viewport.ScreenViewport;

/**
 * Represents the settings screen GUI
 */
public class SettingsScreen implements Screen {
    Main main;

    Stage stage;

    TextureAtlas textureAtlas;

    private Label titleLabel, volumeMusicLabel, volumeSoundLabel, musicOnOffLabel, soundOnOffLabel;
    // private Label fullscreenEnabledLabel;

    public SettingsScreen(Main main) {
        this.main = main;

        this.stage = new Stage(new ScreenViewport());
    }

    @Override
    public void show() {
        textureAtlas = main.assetManager.getGameAtlas();

        stage.clear();
        Gdx.input.setInputProcessor(stage);

        Table table = new Table();
        table.setFillParent(true);
        // table.setDebug(true);
        table.setBackground(new TextureRegionDrawable(textureAtlas.findRegion("settingsBG")));
        stage.addActor(table);

        Skin skin = main.assetManager.getSkin();
        /*
        final CheckBox fullscreenCheckbox = new CheckBox(null, skin);
        fullscreenCheckbox.setChecked(main.getPreferences().isFullscreenEnabled());
        fullscreenCheckbox.addListener(new EventListener() {
            @Override
            public boolean handle(Event event) {
                boolean enabled = fullscreenCheckbox.isChecked();
                main.getPreferences().setFullscreenEnabled(enabled);
                return false;
            }
        });
        */
        final Slider volumeMusicSlider = new Slider(0f, 1f, 0.1f,false, skin);
        volumeMusicSlider.setValue(main.getPreferences().getMusicVolume());
        volumeMusicSlider.addListener(new EventListener() {
            @Override
            public boolean handle(Event event) {
                main.getPreferences().setMusicVolume(volumeMusicSlider.getValue());
                return false;
            }
        });

        final Slider soundMusicSlider = new Slider(0f, 1f, 0.1f,false, skin);
        soundMusicSlider.setValue(main.getPreferences().getSoundVolume());
        soundMusicSlider.addListener(new EventListener() {
            @Override
            public boolean handle(Event event) {
                main.getPreferences().setSoundVolume(soundMusicSlider.getValue());
                return false;
            }
        });

        final CheckBox musicCheckbox = new CheckBox(null, skin);
        musicCheckbox.setChecked(main.getPreferences().isMusicEnabled());
        musicCheckbox.addListener(new EventListener() {
            @Override
            public boolean handle(Event event) {
                boolean enabled = musicCheckbox.isChecked();
                main.getPreferences().setMusicEnabled(enabled);
                return false;
            }
        });

        final CheckBox soundEffectsCheckbox = new CheckBox(null, skin);
        soundEffectsCheckbox.setChecked(main.getPreferences().isSoundEffectsEnabled());
        soundEffectsCheckbox.addListener(new EventListener() {
            @Override
            public boolean handle(Event event) {
                boolean enabled = soundEffectsCheckbox.isChecked();
                main.getPreferences().setSoundEffectsEnabled(enabled);
                return false;
            }
        });

        final TextButton backButton = new TextButton("Back", skin); // the extra argument here "small" is used to set the button to the smaller version instead of the big default version
        backButton.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                main.changeScreen(Screens.MENU);
            }
        });

        titleLabel = new Label("Preferences", skin);
        // fullscreenEnabledLabel = new Label("Fullscreen", skin);
        volumeMusicLabel = new Label("Music Volume", skin);
        volumeSoundLabel = new Label("Sound Volume", skin);
        musicOnOffLabel = new Label("Music On/Off", skin);
        soundOnOffLabel = new Label("Sound On/Off", skin);

        table.add(titleLabel).colspan(2);
        table.row().pad(10, 0, 0, 10);
        /*
        table.add(fullscreenEnabledLabel).left();
        table.add(fullscreenCheckbox);
        table.row().pad(10, 0, 0, 10);
        */
        table.add(volumeMusicLabel).left();
        table.add(volumeMusicSlider);
        table.row().pad(10, 0, 0, 10);

        table.add(musicOnOffLabel).left();
        table.add(musicCheckbox);
        table.row().pad(10, 0, 0, 10);

        table.add(volumeSoundLabel).left();
        table.add(soundMusicSlider);
        table.row().pad(10, 0, 0, 10);

        table.add(soundOnOffLabel).left();
        table.add(soundEffectsCheckbox);
        table.row().pad(10, 0, 0, 10);

        table.add(backButton).colspan(2);
    }

    @Override
    public void render(float delta) {
        Gdx.gl.glClearColor(0f, 0f, 0f, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

        stage.act(Math.min(Gdx.graphics.getDeltaTime(), 1 / 30f));
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
