package com.anonim.impossiblemission.entity.components;

import com.badlogic.ashley.core.Component;
import com.badlogic.gdx.graphics.g2d.TextureRegion;

/**
 * Used to store data about {@link com.badlogic.ashley.core.Entity} textures
 */
public class TextureComponent implements Component {
    /**
     * Texture used by {@link com.badlogic.ashley.core.Entity}
     */
    public TextureRegion region = null;
    /**
     * Texture width
     * (in pixels)
     */
    public float width = 0;
    /**
     * Texture height
     * (in pixels)
     */
    public float height = 0;
}
