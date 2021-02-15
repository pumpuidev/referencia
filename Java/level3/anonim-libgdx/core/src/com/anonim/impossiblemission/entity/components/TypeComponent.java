package com.anonim.impossiblemission.entity.components;

import com.badlogic.ashley.core.Component;

/**
 * Used to store data about thy {@link com.badlogic.ashley.core.Entity}s type
 */
public class TypeComponent implements Component {
    /**
     * Static finals of types
     */
    public static final int PLAYER = 0;
    public static final int ENEMY = 1;
    public static final int FURNITURE = 2;
    public static final int SCENERY = 3;
    public static final int TELEPORTER = 4;
    public static final int OTHER = 5;

    /**
     * {@link com.badlogic.ashley.core.Entity} type
     */
    public int type = OTHER;
}
