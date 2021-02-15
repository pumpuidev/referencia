package com.anonim.impossiblemission.views;

import com.anonim.impossiblemission.Main;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.g2d.TextureAtlas;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.Label;
import com.badlogic.gdx.scenes.scene2d.ui.ProgressBar;
import com.badlogic.gdx.scenes.scene2d.ui.Skin;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.utils.viewport.ScreenViewport;

/**
 * Represents the loading screen GUI
 */
public class LoadingScreen implements Screen {
    private Main main;

    private Stage stage;


    private TextureRegion background;
    private Skin skin;
    private SpriteBatch spriteBatch;

    private Label loadingText;
    private ProgressBar progressBar;

    private int currentLoadingStage = 1;

    private float countDown = 0.5f;

    public LoadingScreen(Main main) {
        this.main = main;
        stage = new Stage(new ScreenViewport());

        loadAssets();

        // initiate queueing of images but don't start loading
        main.assetManager.queueAddImages();
        System.out.println("Loading images....");
    }

    @Override
    public void show() {
        stage.clear();

        Table table = new Table();
        table.setFillParent(true);

        loadingText = new Label("Loading...", skin);
        progressBar = new ProgressBar(0, 5, 1, false, skin);

        table.add(loadingText).fillX().uniformX().pad(300, 0, 0, 20);
        table.row();
        table.add(progressBar).pad(10, 0, 0, 20);

        stage.addActor(table);

        spriteBatch = new SpriteBatch();
        spriteBatch.setBlendFunction(GL20.GL_SRC_ALPHA, GL20.GL_ONE);

        // initiate queueing of images but don't start loading
        main.assetManager.queueAddImages();
        loadingText.setText("Loading images...");
        System.out.println("Loading images...");
    }

    @Override
    public void render(float delta) {
        Gdx.gl.glClearColor(0,0,0,1);
        Gdx.gl.glBlendFunc(GL20.GL_SRC_ALPHA, GL20.GL_ONE_MINUS_SRC_ALPHA);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

        // start SpriteBatch and draw the logo
        spriteBatch.begin();
        spriteBatch.draw(background, 0, 0, stage.getWidth(), stage.getHeight());
        spriteBatch.end();

        // check if the asset manager has finished loading
        if (main.assetManager.manager.update()) { // Load some, will return true if done loading
            progressBar.setValue(currentLoadingStage);
            switch(currentLoadingStage){
                case 1:
                    countDown -= delta;
                    if(countDown < 0) {
                        System.out.println("Loading fonts...");
                        loadingText.setText("Loading fonts...");
                        countDown = 0.2f;
                        currentLoadingStage++;
                    }
                    // main.assetManager.queueAddFonts(); // first load done, now start fonts
                    break;
                case 2:
                    countDown -= delta;
                    if(countDown < 0) {
                        System.out.println("Loading Particle Effects...");
                        loadingText.setText("Loading Particle Effects...");
                        countDown = 0.2f;
                        currentLoadingStage++;
                    }
                    // main.assetManager.queueAddParticleEffects(); // fonts are done now do party effects
                    break;
                case 3:
                    countDown -= delta;
                    if(countDown < 0) {
                        System.out.println("Loading Sounds...");
                        loadingText.setText("Loading Sounds...");
                        countDown = 0.2f;
                        currentLoadingStage++;
                    }
                    // main.assetManager.queueAddSounds();
                    break;
                case 4:
                    countDown -= delta;
                    if(countDown < 0) {
                        System.out.println("Loading music...");
                        loadingText.setText("Loading music...");
                        countDown = 0.2f;
                        currentLoadingStage++;
                    }
                    // main.assetManager.queueAddMusic();
                    break;
                case 5:
                    countDown -= delta;
                    if(countDown < 0) {
                        System.out.println("Finished");
                        loadingText.setText("Finished");
                        currentLoadingStage = 6;
                    }
                    break;
            }
            if (currentLoadingStage > 5){
                countDown -= delta;  // timer to stay on loading screen for short preiod once done loading
                currentLoadingStage = 5;  // cap loading stage to 5 as will use later to display progress bar anbd more than 5 would go off the screen
                if(countDown < 0){ // countdown is complete
                    main.changeScreen(Screens.MENU);  /// go to menu screen
                }
            }
            stage.act();
            stage.draw();
        }
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

    /**
     * Loads the game assets using the {@link com.anonim.impossiblemission.loader.GameAssetManager}
     * @see com.badlogic.gdx.assets.AssetManager
     */
    private void loadAssets() {
        // load loading images and wait until finished
        main.assetManager.queueAddLoadingImages();
        main.assetManager.queueAddSkin();
        main.assetManager.manager.finishLoading();

        // get images used to display loading progress
        TextureAtlas textureAtlas = main.assetManager.getLoadingAtlas();
        background = textureAtlas.findRegion("menuBG");
        skin = main.assetManager.getSkin();
    }
}
