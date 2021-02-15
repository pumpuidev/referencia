package com.anonim.impossiblemission.entity.systems;

import com.anonim.impossiblemission.entity.components.*;

import com.anonim.impossiblemission.views.GameScreen;
import com.badlogic.ashley.core.ComponentMapper;
import com.badlogic.ashley.core.Entity;
import com.badlogic.ashley.core.Family;
import com.badlogic.ashley.systems.IteratingSystem;

/**
 * Engine system to handle collisions
 */
public class CollisionSystem  extends IteratingSystem {
    /**
     * {@link GameScreen} to access its methods
     */
    private GameScreen gameScreen;

    /**
     * {@link ComponentMapper}s for faster {@link com.badlogic.ashley.core.Component} access
     */
    private ComponentMapper<CollisionComponent> cm;
    private ComponentMapper<PlayerComponent> pm;
    private ComponentMapper<TeleporterComponent> tm;
    private ComponentMapper<BodyComponent> bm;

    @SuppressWarnings("unchecked")
    public CollisionSystem(GameScreen gameScreen) {
        super(Family.all(CollisionComponent.class, PlayerComponent.class).get());

        this.gameScreen = gameScreen;

        cm = ComponentMapper.getFor(CollisionComponent.class);
        pm = ComponentMapper.getFor(PlayerComponent.class);
        tm = ComponentMapper.getFor(TeleporterComponent.class);
        bm = ComponentMapper.getFor(BodyComponent.class);
    }

    @Override
    protected void processEntity(Entity entity, float deltaTime) {
        CollisionComponent cc = cm.get(entity);

        Entity collidedEntity = cc.collisionEntity;
        if(collidedEntity != null){
            TypeComponent type = collidedEntity.getComponent(TypeComponent.class);
            if(type != null && !cc.processed){
                switch(type.type){
                    case TypeComponent.ENEMY:
                        gameScreen.gameTimer.penalty(60);
                        gameScreen.death();
                        cc.processed = true;
                        break;
                    case TypeComponent.SCENERY:
                        pm.get(entity).onPlatform = true;
                        cc.processed = true;
                        break;
                    case TypeComponent.FURNITURE:
                        break;
                    case TypeComponent.TELEPORTER:
                        pm.get(entity).atTeleporter = true;
                        TeleporterComponent tc = tm.get(collidedEntity);
                        teleport(entity, tc.x, tc.y, tc.levelChanger);
                        cc.processed = true;
                        break;
                }
            }
        }
    }

    /**
     * Method to teleport player when they walk through a teleporter
     * @param entity Player {@link Entity}
     * @param x Destination x coordinate
     * @param y Destination y coordinate
     * @param levelChanger Whether or not to change to next level
     */
    private void teleport(Entity entity, float x, float y, boolean levelChanger) {
        bm.get(entity).body.setTransform(x + 0.5f, y + 3, bm.get(entity).body.getAngle());
        if(levelChanger) {
            pm.get(entity).currentLevel++;

            switch(pm.get(entity).currentLevel) {
                case 2:
                    gameScreen.worldLoader.generateLevel2();
                    break;
                case 3:
                    gameScreen.worldLoader.generateLevel3();
                    break;
            }
        }
    }
}