package com.anonim.impossiblemission.entity;

import com.badlogic.gdx.physics.box2d.*;
import com.badlogic.gdx.physics.box2d.BodyDef.BodyType;

/**
 * Singleton class to create {@link Body}s
 */
public class BodyFactory {
    /**
     * Singleton instance
     */
    private static BodyFactory thisInstance;
    private World world;

    private BodyFactory(World world){
        this.world = world;
    }

    public static BodyFactory getInstance(World world){
        if(thisInstance == null){
            thisInstance = new BodyFactory(world);
        }
        return thisInstance;
    }

    /**
     * Creates fixtures to hold material properities
     * @param material Fixtures material from {@link Materials}
     * @param shape Fixture {@link Shape}
     * @return The new {@link FixtureDef}
     */
    static private FixtureDef makeFixture(Materials material, Shape shape){
        FixtureDef fixtureDef = new FixtureDef();
        fixtureDef.shape = shape;

        switch(material){
            case STEEL:
                fixtureDef.density = 1f;
                fixtureDef.friction = 0.3f;
                fixtureDef.restitution = 0.1f;
                break;
            case WOOD:
                fixtureDef.density = 0.5f;
                fixtureDef.friction = 0.7f;
                fixtureDef.restitution = 0.3f;
                break;
            case SKIN:
                fixtureDef.density = 1f;
                fixtureDef.friction = 0.1f;
                fixtureDef.restitution = 0.0f;
                break;
            case STONE:
                fixtureDef.density = 1f;
                fixtureDef.friction = 0.9f;
                fixtureDef.restitution = 0.01f;
            case RUBBER:
                fixtureDef.density = 1f;
                fixtureDef.friction = 0f;
                fixtureDef.restitution = 1f;
            default:
                fixtureDef.density = 7f;
                fixtureDef.friction = 0.5f;
                fixtureDef.restitution = 0.3f;
        }
        return fixtureDef;
    }

    /**
     * Creates a rectangular {@link Body}
     * @param posx {@link Body} x coordinate
     * @param posy {@link Body} y coordinate
     * @param width {@link Body} width
     * @param height {@link Body} height
     * @param material {@link Body} material
     * @param bodyType bodyType {@link Body} type
     * @return The new {@link Body} object
     */
    public Body makeBoxPolyBody(float posx, float posy, float width, float height, Materials material, BodyType bodyType){
        return makeBoxPolyBody(posx, posy, width, height, material, bodyType, false);
    }

    /**
     * Creates a rectangular {@link Body}
     * @param posx {@link Body} x coordinate
     * @param posy {@link Body} y coordinate
     * @param width {@link Body} width
     * @param height {@link Body} height
     * @param material {@link Body} material
     * @param bodyType bodyType {@link Body} type
     * @param fixedRotation Whether or not the body should be able to rotate on the Z axis
     * @return  The new {@link Body} object with rotation
     */
    public Body makeBoxPolyBody(float posx, float posy, float width, float height, Materials material, BodyType bodyType, boolean fixedRotation){
        BodyDef boxBodyDef = new BodyDef();
        boxBodyDef.type = bodyType;
        boxBodyDef.position.x = posx;
        boxBodyDef.position.y = posy;
        boxBodyDef.fixedRotation = fixedRotation;

        Body boxBody = world.createBody(boxBodyDef);
        PolygonShape poly = new PolygonShape();
        poly.setAsBox(width/2, height/2);
        boxBody.createFixture(makeFixture(material,poly));
        poly.dispose();

        return boxBody;
    }

    /**
     * Method to turn {@link Body}s into sensors, so {@link com.badlogic.ashley.core.Entity}s can pass through them and interact with them
     * @param body {@link Body} to change
     */
    public void makeAllFixturesSensors(Body body){
        for(Fixture f : body.getFixtureList()) f.setSensor(true);
    }
}
