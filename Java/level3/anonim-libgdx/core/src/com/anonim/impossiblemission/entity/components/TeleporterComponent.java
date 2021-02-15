package com.anonim.impossiblemission.entity.components;

import com.badlogic.ashley.core.Component;

/**
 * Used to store data about teleporter {@link com.badlogic.ashley.core.Entity}s
 */
public class TeleporterComponent implements Component {
    /**
     * Destination x coordinate
     */
    public float x;
    /**
     * Destination y coordinate
     */
    public float y;
    /**
     * Whether to change the level to the next or not
     */
    public boolean levelChanger = false;
}
