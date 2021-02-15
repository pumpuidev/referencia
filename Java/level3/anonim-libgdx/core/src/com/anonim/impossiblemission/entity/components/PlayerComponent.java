package com.anonim.impossiblemission.entity.components;

import com.badlogic.ashley.core.Component;
import com.badlogic.gdx.graphics.OrthographicCamera;

/**
 * Used to store data about the player {@link com.badlogic.ashley.core.Entity}
 */
public class PlayerComponent implements Component {
    /**
     * Player {@link com.badlogic.gdx.graphics.Camera}
     */
    public OrthographicCamera camera;
    /**
     * Current level the player is on
     */
    public int currentLevel = 1;
    /**
     * Whether the player is standing on a platform or not
     */
    public boolean onPlatform = false;
    /**
     * Whether the player is at a teleporter or not
     */
    public boolean atTeleporter = false;
}
