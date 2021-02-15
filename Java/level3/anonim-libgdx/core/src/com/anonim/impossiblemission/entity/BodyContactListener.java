package com.anonim.impossiblemission.entity;

import com.anonim.impossiblemission.entity.components.CollisionComponent;
import com.badlogic.ashley.core.ComponentMapper;
import com.badlogic.ashley.core.Entity;
import com.badlogic.gdx.physics.box2d.Contact;
import com.badlogic.gdx.physics.box2d.ContactImpulse;
import com.badlogic.gdx.physics.box2d.ContactListener;
import com.badlogic.gdx.physics.box2d.Fixture;
import com.badlogic.gdx.physics.box2d.Manifold;

/**
 * {@link ContactListener} class, to handle {@link com.badlogic.gdx.physics.box2d.Body} collision events
 */
public class BodyContactListener implements ContactListener {
    ComponentMapper<CollisionComponent> cm;

    public BodyContactListener(){
        cm = ComponentMapper.getFor(CollisionComponent.class);
    }

    /**
     * Fires when two {@link com.badlogic.gdx.physics.box2d.Body}s collide
     * @param contact {@link Contact} event
     */
    @Override
    public void beginContact(Contact contact) {
        // System.out.println("Contact");
        Fixture fa = contact.getFixtureA();
        Fixture fb = contact.getFixtureB();
        // System.out.println(fa.getBody().getType()+" has hit "+ fb.getBody().getType());

        if(fa.getBody().getUserData() instanceof Entity) {
            Entity ent = (Entity) fa.getBody().getUserData();
            entityCollision(ent, fb);
        }
        else if(fb.getBody().getUserData() instanceof Entity) {
            Entity ent = (Entity) fb.getBody().getUserData();
            entityCollision(ent, fa);
        }
    }

    /**
     * Method to handle player collision
     * @param entity Player {@link Entity}
     * @param fb Colliding {@link Fixture}
     */
    private void entityCollision(Entity entity, Fixture fb) {
        if(fb.getBody().getUserData() instanceof Entity) {
            Entity collidingEntity = (Entity) fb.getBody().getUserData();

            CollisionComponent body = cm.get(entity);
            CollisionComponent collidingBody = cm.get(collidingEntity);

            if(body != null) {
                body.collisionEntity = collidingEntity;
                body.processed = false;
            }
            else if(collidingBody != null) {
                collidingBody.collisionEntity = entity;
                collidingBody.processed = false;
            }
        }
    }

    /**
     * Fires when the {@link Contact} ends
     * @param contact {@link Contact} event
     */
    @Override
    public void endContact(Contact contact) {
        Fixture fa = contact.getFixtureA();
        Fixture fb = contact.getFixtureB();

        if(fa.getBody().getUserData() instanceof Entity) {
            Entity entity = (Entity) fa.getBody().getUserData();

            if(cm.get(entity) == null) return;

            cm.get(entity).collisionEntity = null;
        }
        else if(fb.getBody().getUserData() instanceof Entity) {
            Entity entity = (Entity) fb.getBody().getUserData();

            if(cm.get(entity) == null) return;

            cm.get(entity).collisionEntity = null;
        }
    }
    @Override
    public void preSolve(Contact contact, Manifold oldManifold) {
    }
    @Override
    public void postSolve(Contact contact, ContactImpulse impulse) {
    }

}