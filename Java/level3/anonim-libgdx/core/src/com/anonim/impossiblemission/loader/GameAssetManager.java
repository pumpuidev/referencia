package com.anonim.impossiblemission.loader;

import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.assets.loaders.SkinLoader.SkinParameter;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.TextureAtlas;
import com.badlogic.gdx.scenes.scene2d.ui.Skin;

/**
 * Simple asset manager class for the game
 */
public class GameAssetManager {
    /**
     * Engine asset manager
     */
    public final AssetManager manager = new AssetManager();

    /**
     * {@link TextureAtlas} file locations
     */
    public final String loading = "images/loading.pack";
    public final String game = "images/game.pack";

    /**
     * {@link Skin} file location
     */
    public final String uiSkin = "skin/uiskin.json";

    /**
     * Method to add {@link Skin} to manager
     */
    public void queueAddSkin(){
        SkinParameter params = new SkinParameter("skin/uiskin.atlas");
        manager.load(uiSkin, Skin.class, params);
    }

    /**
     * Method to add game {@link TextureAtlas} to the manager
     */
    public void queueAddImages(){
        manager.load(game, TextureAtlas.class);
    }

    /**
     * Method to add loading {@link TextureAtlas} to the manager
     */
    public void queueAddLoadingImages(){
        manager.load(loading, TextureAtlas.class);
    }

    /**
     * Getters
     */

    public TextureAtlas getLoadingAtlas() {
        return manager.get(loading);
    }

    public TextureAtlas getGameAtlas() {
        return manager.get(game);
    }

    public Skin getSkin() {
        return manager.get(uiSkin);
    }
}
