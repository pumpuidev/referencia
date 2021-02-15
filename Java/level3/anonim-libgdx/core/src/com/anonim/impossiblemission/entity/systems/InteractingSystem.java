package com.anonim.impossiblemission.entity.systems;

import com.anonim.impossiblemission.controller.KeyboardController;
import com.anonim.impossiblemission.entity.components.BodyComponent;
import com.anonim.impossiblemission.entity.components.CollisionComponent;
import com.anonim.impossiblemission.views.GameScreen;
import com.badlogic.ashley.core.ComponentMapper;
import com.badlogic.ashley.core.Entity;
import com.badlogic.ashley.core.Family;
import com.badlogic.ashley.systems.IteratingSystem;

/**
 * Engine system to handle player interactions
 */
public class InteractingSystem extends IteratingSystem {
    /**
     * {@link GameScreen} for method access
     */
    GameScreen gameScreen;
    /**
     * {@link KeyboardController} for button presses
     */
    KeyboardController controller;
    /**
     * {@link ComponentMapper}s for faster {@link com.badlogic.ashley.core.Component} access
     */
    ComponentMapper<BodyComponent> bm;
    ComponentMapper<CollisionComponent> cm;


    @SuppressWarnings("unchecked")
    public InteractingSystem(GameScreen gameScreen, KeyboardController controller) {
        super(Family.all(BodyComponent.class, CollisionComponent.class).get());

        this.gameScreen = gameScreen;
        this.controller = controller;

        bm = ComponentMapper.getFor(BodyComponent.class);
        cm = ComponentMapper.getFor(CollisionComponent.class);
    }

    @Override
    protected void processEntity(Entity entity, float deltaTime) {
        Entity collidingEntity = cm.get(entity).collisionEntity;
        if(controller.interact && !gameScreen.windowIsUp && isInteractable(entity)) {
            gameScreen.interactWindow(gameScreen.giveRandomLetter());
            bm.get(collidingEntity).interactable = false;
        }

    }

    /**
     * Method to check if colliding {@link Entity} is interactable
     * @param entity Player {@link Entity}
     * @return Whether the colliding {@link Entity} is interactable or not
     */
    private boolean isInteractable(Entity entity) {
        Entity collidingEntity = cm.get(entity).collisionEntity;

        if(collidingEntity == null) return false;

        BodyComponent entityBody = bm.get(entity);
        BodyComponent collidingBody = bm.get(collidingEntity);
        return collidingBody.interactable && entityBody.bounds.overlaps(collidingBody.bounds);
    }
}
