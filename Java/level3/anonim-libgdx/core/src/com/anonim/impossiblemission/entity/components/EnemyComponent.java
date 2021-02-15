package com.anonim.impossiblemission.entity.components;

import com.badlogic.ashley.core.Component;

/**
 * Used to store data about enemy {@link com.badlogic.ashley.core.Entity}s
 */
public class EnemyComponent implements Component {
    /**
     * Point where the Enemy was spawned
     */
    public float xPosCenter = -1;
    /**
     * Whether the enemy is going left or not
     */
    public boolean isGoingLeft = false;
    /**
     * Range of enemies movement
     */
    public float range = 0;
}