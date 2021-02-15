package com.anonim.impossiblemission.entity.components;

import com.badlogic.ashley.core.Component;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.math.Vector3;

/**
 * used to store data about {@link com.badlogic.ashley.core.Entity} movement
 */
public class TransformComponent implements Component {
    /**
     * {@link com.badlogic.ashley.core.Entity} position
     */
    public final Vector3 position = new Vector3();
    /**
     * {@link com.badlogic.ashley.core.Entity} scale
     */
    public final Vector2 scale = new Vector2(1.0f, 1.0f);
    /**
     * {@link com.badlogic.ashley.core.Entity} rotation
     */
    public float rotation = 0.0f;
    /**
     * Whether or not it is hidden
     */
    public boolean isHidden = false;
}
