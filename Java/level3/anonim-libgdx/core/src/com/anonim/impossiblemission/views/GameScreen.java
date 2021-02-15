package com.anonim.impossiblemission.views;

import com.anonim.impossiblemission.GameTimer;
import com.anonim.impossiblemission.Main;
import com.anonim.impossiblemission.controller.KeyboardController;
import com.anonim.impossiblemission.entity.components.*;
import com.anonim.impossiblemission.entity.systems.*;
import com.anonim.impossiblemission.loader.WorldLoader;
import com.badlogic.ashley.core.PooledEngine;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.InputMultiplexer;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.g2d.TextureAtlas;
import com.badlogic.gdx.scenes.scene2d.Actor;
import com.badlogic.gdx.scenes.scene2d.InputEvent;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.*;
import com.badlogic.gdx.scenes.scene2d.utils.ChangeListener;
import com.badlogic.gdx.scenes.scene2d.utils.ClickListener;

import java.util.Collections;
import java.util.HashSet;
import java.util.Random;

/**
 * Represents the main game {@link Screen}
 * Most of the game logic happens here
 */
public class GameScreen implements Screen {
    /**
     * Static final fields
     */
    private static final String CODEWORD = "PROGTECH";
    private static final float GUI_HEIGHT = RenderingSystem.MetersToPixels(2);

    /**
     * Backend fields
     */
    private Main main;
    public OrthographicCamera camera;
    private InputMultiplexer inputMultiplexer;
    private PooledEngine engine;
    public WorldLoader worldLoader;
    private KeyboardController controller;
    public GameTimer gameTimer;


    /**
     * GUI and rendering fields
     */
    private SpriteBatch spriteBatch;
    private TextureAtlas textureAtlas;
    private Skin skin;
    private Stage stage, guiStage;
    private Window guiBar;
    private Label currentLettersLabel,  currentLetters, timerLabel, timer;

    /**
     * Container and misc data fields
     */
    private HashSet<String> letters = new HashSet<String>();
    private HashSet<String> foundLetters = new HashSet<String>();
    private int difficulty;
    public boolean windowIsUp = false;

    public GameScreen(Main main, int difficulty) {
        this.main = main;
        main.assetManager.manager.finishLoading();
        textureAtlas = main.assetManager.getGameAtlas();


        controller = new KeyboardController(main);
        engine = new PooledEngine();

        inputMultiplexer = new InputMultiplexer();
        inputMultiplexer.addProcessor(controller);

        spriteBatch = new SpriteBatch();
        RenderingSystem renderingSystem = new RenderingSystem(spriteBatch);
        camera = renderingSystem.getCamera();
        worldLoader = new WorldLoader(engine, textureAtlas, camera);
        spriteBatch.setProjectionMatrix(camera.combined);

        engine.addSystem(new PhysicsSystem(worldLoader.world));
        engine.addSystem(renderingSystem);
        engine.addSystem(new PhysicsDebugSystem(worldLoader.world, renderingSystem.getCamera()));

        engine.addSystem(new CollisionSystem(this));
        engine.addSystem(new InteractingSystem(this, controller));
        engine.addSystem(new PlayerControlSystem(controller, this));
        engine.addSystem(new EnemySystem());

        worldLoader.startWorld();

        stage = new Stage();
        guiStage = new Stage();
        inputMultiplexer.addProcessor(stage);
        inputMultiplexer.addProcessor(guiStage);

        skin = main.assetManager.getSkin();

        populateLetters();

        this.difficulty = difficulty;
    }

    /**
     * Method used to split the codeword and store it in a {@link java.util.Set}
     */
    private void populateLetters() {
        Collections.addAll(letters, CODEWORD.split(""));
    }

    @Override
    public void show() {
        Gdx.input.setInputProcessor(inputMultiplexer);

        switch(difficulty) {
            case DifficultyScreen.EASY:
                gameTimer = new GameTimer(main, 30);
                break;
            case DifficultyScreen.MEDIUM:
                gameTimer = new GameTimer(main, 20);
                break;
            case DifficultyScreen.HARD:
                gameTimer = new GameTimer(main, 10);
                break;
            default:
                gameTimer = new GameTimer(main, 31);
        }

        guiBar = new Window("", skin);
        currentLettersLabel = new Label("Letters:", skin);
        currentLettersLabel.setFontScale(1.5f);
        timerLabel = new Label("Time left:", skin);
        timerLabel.setFontScale(1.5f);
        currentLetters = new Label(foundLetters.toString(), skin);
        currentLetters.setFontScale(1.5f);
        timer = new Label(gameTimer.toString(), skin);
        timer.setFontScale(1.5f);

        renderHUD();
    }

    @Override
    public void render(float delta) {
        Gdx.gl.glClearColor(255f, 255f, 255f, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);
        spriteBatch.begin();
        spriteBatch.draw(textureAtlas.findRegion("gameBG"), 0, 0, RenderingSystem.PixelsToMeters(640), RenderingSystem.PixelsToMeters(480));
        spriteBatch.end();

        engine.update(delta);

        timer.setText(gameTimer.toString());
        currentLetters.setText(foundLetters.toString());

        guiStage.act();
        guiStage.draw();
        stage.act(Gdx.graphics.getDeltaTime());
        stage.draw();
    }

    /**
     * Method used to render in-game HUD
     */
    private void renderHUD() {
        // guiStage.setDebugUnderMouse(true);

        guiBar.scaleBy(-0.5f);
        guiBar.setWidth(stage.getWidth() * 2);
        guiBar.setHeight(GUI_HEIGHT * 2);
        guiBar.setPosition(0, 0);
        guiBar.center();


        Table leftTable = new Table();
        Table rightTable = new Table();

        leftTable.left();
        rightTable.right();

        leftTable.add(currentLettersLabel).padLeft(50).padRight(20);
        leftTable.add(currentLetters);
        rightTable.add(timerLabel);
        rightTable.add(timer).padLeft(20).padRight(50);


        guiBar.add(leftTable).width(guiBar.getWidth() / 2);
        guiBar.add(rightTable).width(guiBar.getWidth() / 2);

        guiStage.addActor(guiBar);
    }

    /**
     * Method used to render game inventory when opened
     */
    public void renderInventory() {
        if(windowIsUp) return;
        else windowIsUp = true;

        final Window window = new Window("Inventory", skin);
        window.setWidth(guiStage.getWidth() - 20);
        window.setHeight(guiStage.getHeight() - 20 - GUI_HEIGHT);
        window.setPosition(10, GUI_HEIGHT + 10);
        guiStage.addActor(window);

        Label codeInputLabel = new Label("Input the codeword here:", skin);

        final TextField codeInput = new TextField("PROGTECH", skin);
        TextButton inputCode = new TextButton("Input", skin);
        TextButton back = new TextButton("Back", skin);

        codeInput.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                codeInput.setText("");
            }
        });

        inputCode.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                checkWinning(codeInput.getText());
            }
        });

        back.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                window.remove();
                windowIsUp = false;
            }
        });

        window.add(codeInputLabel).colspan(2);
        window.row().pad(5);
        window.add(codeInput);
        window.add(inputCode);
        window.row().pad(100);
        window.add(back).colspan(2);
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

    /**
     * Method used when a code letter is found
     * @param letter The found letter
     */
    public void interactWindow(String letter) {
        windowIsUp = true;
        String windowTitle = "Letter Found!";
        if(letter == null) windowTitle = "All letters found!\nTry guessing codeword!";

        Window window = new Window(windowTitle, skin);
        Label titleLabel = window.getTitleLabel();
        Label letterLabel = new Label(letter, skin);
        TextButton okButton = new TextButton("OK", skin);

        float stageWidth = stage.getWidth(), stageHeight = stage.getHeight();

        window.setWidth((stageWidth / 3) * 2);
        window.setHeight((stageHeight / 3) * 2);
        window.setPosition(stageWidth / 6, stageHeight / 6);
        // window.setDebug(true);
        stage.addActor(window);

        okButton.addListener(new ChangeListener() {
            @Override
            public void changed(ChangeEvent event, Actor actor) {
                windowIsUp = false;
                stage.clear();
            }
        });

        letterLabel.setFontScale(3);
        window.add(titleLabel);
        window.row().pad(10, 0, 10, 0);
        window.add(letterLabel);
        window.row().pad(20, 0, 20, 0);
        window.add(okButton);
    }

    /**
     * Method used to give the random letter of the codeword
     * @return Random letter from codeword
     */
    public String giveRandomLetter() {
        if(letters.size() == 0) return null;
        Random rnd = new Random();
        Object[] lettersArray = letters.toArray();
        String letter = (String) lettersArray[rnd.nextInt(letters.size())];
        foundLetters.add(letter);
        letters.remove(letter);
        return letter;
    }

    /**
     * Method used to win the game
     */
    private void win() {
        main.changeScreen(false, gameTimer.getCurrentTime(), difficulty);
    }

    /**
     * Method used to check whether or not the correct codeword was entered
     * @param code Entered word
     */
    private void checkWinning(String code) {
        if(code.equals(CODEWORD)) win();
        else gameTimer.penalty(60 * 3);
    }

    /**
     * Method used to lose the game
     * (vesztettem)
     */
    public void lose() {
        main.changeScreen(true, -1, -1);
    }

    /**
     * Method used when player collides with enemy
     * Respawns player at the first level, loses all letters, and the whole game is reset
     */
    public void death() {
        worldLoader.clearLevel();
        engine.removeEntity(worldLoader.player);
        worldLoader.world.destroyBody(worldLoader.player.getComponent(BodyComponent.class).body);
        worldLoader.generateLevel1();
        foundLetters.clear();
        populateLetters();
        worldLoader.player.getComponent(BodyComponent.class).body.setTransform(WorldLoader.PLAYER_SPAWN_X, WorldLoader.PLAYER_SPAWN_Y, 0);
    }
}
