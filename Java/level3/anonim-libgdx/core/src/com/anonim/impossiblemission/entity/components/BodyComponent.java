package com.anonim.impossiblemission.entity.components;

import com.badlogic.ashley.core.Component;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.physics.box2d.Body;

/**
 * Used to store data about the {@link Body}s associated with the game {@link com.badlogic.ashley.core.Entity}s
 */
public class BodyComponent implements Component {
    /**
     * {@link Body} instance
     */
    public Body body;
    /**
     * Bounds used for interaction detection
     */
    public Rectangle bounds = new Rectangle();
    /**
     * Whether or not the {@link Body} can be interacted with
     */
    public boolean interactable = false;
}
