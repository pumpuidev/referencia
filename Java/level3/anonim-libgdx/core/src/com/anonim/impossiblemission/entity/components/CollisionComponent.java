package com.anonim.impossiblemission.entity.components;

import com.badlogic.ashley.core.Component;
import com.badlogic.ashley.core.Entity;

/**
 * Used to store data about {@link Entity} collisions
 */
public class CollisionComponent implements Component {
    /**
     * Colliding {@link Entity}
     */
    public Entity collisionEntity;
    /**
     * Whether or not the collision event has been processed
     */
    public boolean processed = false;
}