package com.anonim.impossiblemission.controller;

import com.anonim.impossiblemission.Main;
import com.badlogic.gdx.Input.Keys;
import com.badlogic.gdx.InputProcessor;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.math.Vector3;
import com.badlogic.gdx.physics.box2d.Body;

/**
 * This class handles keyboard and mouse input
 * @author anonim
 * @version 1.0
 */
public class KeyboardController implements InputProcessor {
    private Main main;

    /**
     * Key and mouse variables
     */
    public boolean mouseLeft, mouseRight, mouseMiddle;
    public boolean isDragged;
    public boolean up, down, left, right, interact, inventory;
    public Vector2 mouseLocation;

    public KeyboardController(Main main) {
        this.main = main;
        mouseLocation = new Vector2();
    }

    /**
     * Handles keys being pushed down
     * @param keycode keycode of key being pressed
     * @return whether or not a key processed
     */
    @Override
    public boolean keyDown(int keycode) {
        boolean keyProcessed = false;
        switch(keycode) {
            case Keys.A:
                left = true;
                keyProcessed = true;
                break;
            case Keys.D:
                right = true;
                keyProcessed = true;
                break;
            case Keys.W:
                up = true;
                keyProcessed = true;
                break;
            case Keys.S:
                down = true;
                keyProcessed = true;
                break;
            case Keys.E:
                interact = true;
                keyProcessed = true;
                break;
            case Keys.Q:
                inventory = true;
                keyProcessed = true;
                break;
        }
        return keyProcessed;
    }

    /**
     * Handles keys being let up
     * @param keycode keycode of key being released
     * @return whether or not a key processed
     */
    @Override
    public boolean keyUp(int keycode) {
        boolean keyProcessed = false;
        switch(keycode) {
            case Keys.A:
                left = false;
                keyProcessed = true;
                break;
            case Keys.D:
                right = false;
                keyProcessed = true;
                break;
            case Keys.W:
                up = false;
                keyProcessed = true;
                break;
            case Keys.S:
                down = false;
                keyProcessed = true;
                break;
            case Keys.E:
                interact = false;
                keyProcessed = true;
                break;
            case Keys.Q:
                inventory = false;
                keyProcessed = true;
                break;
        }
        return keyProcessed;
    }

    /**
     * Overridden method
     * @param character character
     * @return false
     */
    @Override
    public boolean keyTyped(char character) {
        return false;
    }

    /**
     * Handles mouse button presses and pointer location
     * @param screenX Mouse pointer x coordinate
     * @param screenY Mouse pointer y coordinate
     * @param pointer Event pointer
     * @param button Mouse button code
     * @return false
     */
    @Override
    public boolean touchDown(int screenX, int screenY, int pointer, int button) {
        if(button == 0){
            mouseLeft = true;
        }else if(button == 1){
            mouseRight = true;
        }else if(button == 2){
            mouseMiddle = true;
        }
        mouseLocation.x = screenX;
        mouseLocation.y = screenY;
        return false;
    }

    /**
     * Handles mouse button releases
     * @param screenX Mouse pointer x coordinate
     * @param screenY Mouse pointer y coordinate
     * @param pointer Event pointer
     * @param button Mouse button code
     * @return false
     */
    @Override
    public boolean touchUp(int screenX, int screenY, int pointer, int button) {
        isDragged = false;
        if(button == 0){
            mouseLeft = false;
        }else if(button == 1){
            mouseRight = false;
        }else if(button == 2){
            mouseMiddle = false;
        }
        mouseLocation.x = screenX;
        mouseLocation.y = screenY;
        return false;
    }

    /**
     * Handles mouse drags
     * @param screenX Mouse pointer x coordinate
     * @param screenY Mouse pointer y coordinate
     * @param pointer Event pointer
     * @return false
     */
    @Override
    public boolean touchDragged(int screenX, int screenY, int pointer) {
        isDragged = true;
        mouseLocation.x = screenX;
        mouseLocation.y = screenY;
        return false;
    }

    /**
     * Handles mouse movement
     * @param screenX Mouse pointer x coordinate
     * @param screenY Mouse pointer y coordinate
     * @return false
     */
    @Override
    public boolean mouseMoved(int screenX, int screenY) {
        mouseLocation.x = screenX;
        mouseLocation.y = screenY;
        return false;
    }

    /**
     * Handles mouse pointer intersecting Bodys
     * @param body Body to check
     * @param mouseLocation Mouse pointer location
     * @return Whether or not pointer intersects body bounds
     */
    public boolean pointIntersectsBody(Body body, Vector2 mouseLocation){
        Vector3 mousePos = new Vector3(mouseLocation,0);
        main.getGameScreen().camera.unproject(mousePos);
        return body.getFixtureList().first().testPoint(mousePos.x, mousePos.y);
    }

    /**
     * Handles mouse scrolling
     * @param amount amount scrolled
     * @return false
     */
    @Override
    public boolean scrolled(int amount) {
        return false;
    }
}
