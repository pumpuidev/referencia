package com.anonim.impossiblemission.entity.components;

import com.badlogic.ashley.core.Component;

/**
 * Used to store data about {@link com.badlogic.ashley.core.Entity} states
 */
public class StateComponent implements Component {
    /**
     * Static final variables
     */
    public static final int STATE_NORMAL = 0;
    public static final int STATE_JUMPING = 1;
    public static final int STATE_FALLING = 2;
    public static final int STATE_MOVING = 3;

    /**
     * Current state
     */
    public int state = 0;
    /**
     * Time spent alive by {@link com.badlogic.ashley.core.Entity}
     */
    public float time = 0.0f;

    /**
     * Method to check if {@link com.badlogic.ashley.core.Entity} is in specific state or not
     * @param other Other state to check against
     * @return Whether or not they are equal
     */
    public boolean equals(int other) {
        return this.state == other;
    }
}