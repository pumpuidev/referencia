package com.anonim.impossiblemission.entity.systems;

import com.anonim.impossiblemission.controller.KeyboardController;
import com.anonim.impossiblemission.entity.components.BodyComponent;
import com.anonim.impossiblemission.entity.components.PlayerComponent;
import com.anonim.impossiblemission.entity.components.StateComponent;

import com.anonim.impossiblemission.views.GameScreen;
import com.badlogic.ashley.core.ComponentMapper;
import com.badlogic.ashley.core.Entity;
import com.badlogic.ashley.core.Family;
import com.badlogic.ashley.systems.IteratingSystem;
import com.badlogic.gdx.math.MathUtils;

/**
 * Engine system to handle player control
 */
public class PlayerControlSystem extends IteratingSystem{
    /**
     * {@link GameScreen} for methods access
     */
    private GameScreen gameScreen;
    /**
     * {@link KeyboardController} for access to key presses
     */
    private KeyboardController controller;
    /**
     * {@link ComponentMapper}s for faster {@link com.badlogic.ashley.core.Component} access
     */
    private ComponentMapper<BodyComponent> bodm;
    private ComponentMapper<StateComponent> sm;


    @SuppressWarnings("unchecked")
    public PlayerControlSystem(KeyboardController keyCon, GameScreen gameScreen) {
        super(Family.all(PlayerComponent.class).get());
        this.gameScreen = gameScreen;

        controller = keyCon;
        bodm = ComponentMapper.getFor(BodyComponent.class);
        sm = ComponentMapper.getFor(StateComponent.class);
    }

    @Override
    protected void processEntity(Entity entity, float deltaTime) {
        BodyComponent b2body = bodm.get(entity);
        StateComponent state = sm.get(entity);

        if(b2body.body.getLinearVelocity().y > 0) {
            state.state = StateComponent.STATE_FALLING;
        }

        if(b2body.body.getLinearVelocity().y == 0) {
            if(state.equals(StateComponent.STATE_FALLING)) {
                state.state = StateComponent.STATE_NORMAL;
            }
            if(b2body.body.getLinearVelocity().x != 0) {
                state.state = StateComponent.STATE_MOVING;
            }
            else state.state = StateComponent.STATE_NORMAL;
        }

        if(controller.left) {
            b2body.body.setLinearVelocity(MathUtils.lerp(b2body.body.getLinearVelocity().x, -5f, 0.2f),b2body.body.getLinearVelocity().y);
        }
        if(controller.right) {
            b2body.body.setLinearVelocity(MathUtils.lerp(b2body.body.getLinearVelocity().x, 5f, 0.2f),b2body.body.getLinearVelocity().y);
        }

        if(!controller.left && !controller.right) {
            b2body.body.setLinearVelocity(MathUtils.lerp(b2body.body.getLinearVelocity().x, 0, 0.1f),b2body.body.getLinearVelocity().y);
        }

        if(controller.up && (state.equals(StateComponent.STATE_NORMAL) || state.equals(StateComponent.STATE_MOVING))){
            b2body.body.applyLinearImpulse(0, 15f, b2body.body.getWorldCenter().x, b2body.body.getWorldCenter().y, true);
            state.state = StateComponent.STATE_JUMPING;
        }

        if(controller.inventory) {
            gameScreen.renderInventory();
        }
    }
}