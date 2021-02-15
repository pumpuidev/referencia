package com.anonim.impossiblemission.entity.systems;


import com.anonim.impossiblemission.entity.components.BodyComponent;
import com.anonim.impossiblemission.entity.components.EnemyComponent;
import com.badlogic.ashley.core.ComponentMapper;
import com.badlogic.ashley.core.Entity;
import com.badlogic.ashley.core.Family;
import com.badlogic.ashley.systems.IteratingSystem;

/**
 * Engine system to handle enemies
 */
public class EnemySystem extends IteratingSystem {
    /**
     * {@link ComponentMapper}s for faster {@link com.badlogic.ashley.core.Component} access
     */
    private ComponentMapper<EnemyComponent> em;
    private ComponentMapper<BodyComponent> bm;

    @SuppressWarnings("unchecked")
    public EnemySystem(){
        super(Family.all(EnemyComponent.class).get());
        em = ComponentMapper.getFor(EnemyComponent.class);
        bm = ComponentMapper.getFor(BodyComponent.class);
    }

    protected void processEntity(Entity entity, float deltaTime) {
        EnemyComponent enemyCom = em.get(entity);
        BodyComponent bodyCom = bm.get(entity);

        float distFromOrig = Math.abs(enemyCom.xPosCenter - bodyCom.body.getPosition().x);

        enemyCom.isGoingLeft = (distFromOrig > enemyCom.range) != enemyCom.isGoingLeft;

        float speed = enemyCom.isGoingLeft ? -0.02f : 0.02f;

        bodyCom.body.setTransform(bodyCom.body.getPosition().x + speed,
                bodyCom.body.getPosition().y,
                bodyCom.body.getAngle());
    }
}