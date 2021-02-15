package com.anonim.impossiblemission.loader;

import com.anonim.impossiblemission.entity.BodyContactListener;
import com.anonim.impossiblemission.entity.BodyFactory;
import com.anonim.impossiblemission.entity.Materials;
import com.anonim.impossiblemission.entity.components.*;
import com.anonim.impossiblemission.entity.systems.RenderingSystem;
import com.badlogic.ashley.core.Entity;
import com.badlogic.ashley.core.Family;
import com.badlogic.ashley.core.PooledEngine;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.TextureAtlas;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.Body;
import com.badlogic.gdx.physics.box2d.BodyDef;
import com.badlogic.gdx.physics.box2d.World;
import com.badlogic.gdx.utils.Array;

import java.util.HashSet;
import java.util.Random;

/**
 * Class used to create the levels and {@link Entity}s
 */
public class WorldLoader {
    public static final int PLAYER_SPAWN_X = 1;
    public static final int PLAYER_SPAWN_Y = 3;
    private static final float DEFAULT_PLATFORM_WIDTH = 3f;
    private static final float DEFAULT_PLATFORM_HEIGHT = 0.5f;
    private static final float WORLD_WIDTH = Gdx.graphics.getWidth();
    private static final float WORLD_HEIGHT = Gdx.graphics.getHeight();
    private static final float WORLD_WIDTH_M = RenderingSystem.PixelsToMeters(Gdx.graphics.getWidth());
    private static final float WORLD_HEIGHT_M = RenderingSystem.PixelsToMeters(Gdx.graphics.getHeight());

    private BodyFactory bodyFactory;
    public World world;
    private PooledEngine engine;
    private TextureAtlas textureAtlas;
    private HashSet<TextureComponent> furnitureTextures;
    private OrthographicCamera camera;
    public Entity player;
    public int currentLvl;

    public WorldLoader(PooledEngine engine, TextureAtlas textureAtlas, OrthographicCamera camera) {
        this.engine = engine;
        this.textureAtlas = textureAtlas;
        furnitureTextures = new HashSet<TextureComponent>();
        this.camera = camera;

        loadtFurnitreTextures();

        world = new World(new Vector2(0,-10f), true);
        world.setContactListener(new BodyContactListener());
        bodyFactory = BodyFactory.getInstance(world);
    }

    /**
     * Generates the first level when game is started
     */
    public void startWorld() {
        generateLevel1();
    }

    /**
     * Loads the textures for the furniture {@link Entity}s
     */
    private void loadtFurnitreTextures() {
        TextureComponent[] furnitureComponents = new TextureComponent[5];

        for(int i = 0; i < furnitureComponents.length; i++) furnitureComponents[i] = this.engine.createComponent(TextureComponent.class);

        furnitureComponents[0].region = textureAtlas.findRegion("desk");
        furnitureComponents[0].width = RenderingSystem.MetersToPixels(2);
        furnitureComponents[0].height = RenderingSystem.MetersToPixels(1);
        furnitureTextures.add(furnitureComponents[0]);

        furnitureComponents[1].region = textureAtlas.findRegion("vending");
        furnitureComponents[1].width = RenderingSystem.MetersToPixels(1);
        furnitureComponents[1].height = RenderingSystem.MetersToPixels(2);
        furnitureTextures.add(furnitureComponents[1]);

        furnitureComponents[2].region = textureAtlas.findRegion("computer");
        furnitureComponents[2].width = RenderingSystem.MetersToPixels(1);
        furnitureComponents[2].height = RenderingSystem.MetersToPixels(1);
        furnitureTextures.add(furnitureComponents[2]);

        furnitureComponents[3].region = textureAtlas.findRegion("typewriter");
        furnitureComponents[3].width = RenderingSystem.MetersToPixels(1);
        furnitureComponents[3].height = RenderingSystem.MetersToPixels(1);
        furnitureTextures.add(furnitureComponents[3]);

        furnitureComponents[4].region = textureAtlas.findRegion("cabinet");
        furnitureComponents[4].width = RenderingSystem.MetersToPixels(1);
        furnitureComponents[4].height = RenderingSystem.MetersToPixels(1);
        furnitureTextures.add(furnitureComponents[4]);
    }

    /**
     * Creates platform with default width and height
     * @param x Platform bottom-left corner x coordinate
     * @param y Platform bottom-left corner y coordinate
     */
    private void createPlatform(float x, float y) {
        createPlatform(x, y, DEFAULT_PLATFORM_WIDTH, DEFAULT_PLATFORM_HEIGHT);
    }

    /**
     * Creates the level box
     */
    private void createBox() {
        createFloor();
        createWallLeft();
        createWallRight();
        createCeiling();
    }

    /**
     * Creates left wall
     */
    private void createWallLeft() {
        Entity entity = engine.createEntity();
        BodyComponent b2dbody = engine.createComponent(BodyComponent.class);
        b2dbody.body = bodyFactory.makeBoxPolyBody(0, 2 + (WORLD_HEIGHT_M / 2), 0.2f, WORLD_HEIGHT_M, Materials.STONE, BodyDef.BodyType.StaticBody);

        TextureComponent texture = engine.createComponent(TextureComponent.class);
        texture.region = textureAtlas.findRegion("platformFull");
        texture.width = 0.2f;
        texture.height = WORLD_HEIGHT;

        TransformComponent position = engine.createComponent(TransformComponent.class);
        position.position.set(0, 2, 0);

        TypeComponent type = engine.createComponent(TypeComponent.class);
        type.type = TypeComponent.SCENERY;

        b2dbody.body.setUserData(entity);

        entity.add(b2dbody);
        entity.add(texture);
        entity.add(position);
        entity.add(type);

        engine.addEntity(entity);
    }

    /**
     * Creates Right wall
     */
    private void createWallRight() {
        Entity entity = engine.createEntity();
        BodyComponent b2dbody = engine.createComponent(BodyComponent.class);
        b2dbody.body = bodyFactory.makeBoxPolyBody(WORLD_WIDTH_M, 2 + (WORLD_HEIGHT_M / 2), 0.2f, WORLD_HEIGHT_M, Materials.STONE, BodyDef.BodyType.StaticBody);

        TextureComponent texture = engine.createComponent(TextureComponent.class);
        texture.region = textureAtlas.findRegion("platformFull");
        texture.width = RenderingSystem.MetersToPixels(0.2f);
        texture.height = WORLD_HEIGHT;

        TransformComponent position = engine.createComponent(TransformComponent.class);
        position.position.set(WORLD_WIDTH_M, 2 + (WORLD_HEIGHT_M / 2), 0);

        TypeComponent type = engine.createComponent(TypeComponent.class);
        type.type = TypeComponent.SCENERY;

        b2dbody.body.setUserData(entity);

        entity.add(b2dbody);
        entity.add(texture);
        entity.add(position);
        entity.add(type);

        engine.addEntity(entity);
    }

    /**
     * Creates ceiling
     */
    private void createCeiling() {
        Entity entity = engine.createEntity();
        BodyComponent b2dbody = engine.createComponent(BodyComponent.class);
        b2dbody.body = bodyFactory.makeBoxPolyBody(WORLD_WIDTH_M / 2, WORLD_HEIGHT_M, WORLD_WIDTH_M, 0.2f, Materials.STONE, BodyDef.BodyType.StaticBody);

        TextureComponent texture = engine.createComponent(TextureComponent.class);
        texture.region = textureAtlas.findRegion("platformFull");
        texture.width = WORLD_WIDTH;
        texture.height = RenderingSystem.MetersToPixels(0.2f);

        TransformComponent position = engine.createComponent(TransformComponent.class);
        position.position.set(WORLD_WIDTH_M / 2, WORLD_HEIGHT_M, 0);

        TypeComponent type = engine.createComponent(TypeComponent.class);
        type.type = TypeComponent.SCENERY;

        b2dbody.body.setUserData(entity);

        entity.add(b2dbody);
        entity.add(texture);
        entity.add(position);
        entity.add(type);

        engine.addEntity(entity);
    }

    /**
     * Creates floor
     */
    private void createFloor(){
        Entity entity = engine.createEntity();
        BodyComponent b2dbody = engine.createComponent(BodyComponent.class);
        b2dbody.body = bodyFactory.makeBoxPolyBody(WORLD_WIDTH_M / 2, 2, WORLD_WIDTH_M, 0.2f, Materials.STONE, BodyDef.BodyType.StaticBody);

        TextureComponent texture = engine.createComponent(TextureComponent.class);
        texture.region = textureAtlas.findRegion("platformFull");
        texture.width = WORLD_WIDTH;
        texture.height = RenderingSystem.MetersToPixels(0.2f);

        TransformComponent position = engine.createComponent(TransformComponent.class);
        position.position.set(WORLD_WIDTH_M / 2, 2, 0);

        TypeComponent type = engine.createComponent(TypeComponent.class);
        type.type = TypeComponent.SCENERY;

        b2dbody.body.setUserData(entity);

        entity.add(b2dbody);
        entity.add(texture);
        entity.add(position);
        entity.add(type);

        engine.addEntity(entity);
    }

    /**
     * Method used to create the player {@link Entity}
     * @param cam Player camera
     */
    private void createPlayer(OrthographicCamera cam){

        Entity entity = engine.createEntity();
        BodyComponent body = engine.createComponent(BodyComponent.class);
        TransformComponent position = engine.createComponent(TransformComponent.class);
        TextureComponent texture = engine.createComponent(TextureComponent.class);
        PlayerComponent player = engine.createComponent(PlayerComponent.class);
        CollisionComponent colComp = engine.createComponent(CollisionComponent.class);
        TypeComponent type = engine.createComponent(TypeComponent.class);
        StateComponent stateCom = engine.createComponent(StateComponent.class);


        player.camera = cam;
        body.body = bodyFactory.makeBoxPolyBody(PLAYER_SPAWN_X,PLAYER_SPAWN_Y,1, 2, Materials.SKIN, BodyDef.BodyType.DynamicBody,true);
        body.bounds = new Rectangle().setPosition(body.body.getPosition());
        body.bounds.setSize(1, 2);

        position.position.set(PLAYER_SPAWN_X,PLAYER_SPAWN_Y,10);

        texture.region = textureAtlas.findRegion("playerStillRight");
        texture.width = RenderingSystem.MetersToPixels(1);
        texture.height = RenderingSystem.MetersToPixels(2);

        type.type = TypeComponent.PLAYER;
        stateCom.state = StateComponent.STATE_NORMAL;
        body.body.setUserData(entity);

        entity.add(body);
        entity.add(position);
        entity.add(texture);
        entity.add(player);
        entity.add(colComp);
        entity.add(type);
        entity.add(stateCom);

        engine.addEntity(entity);
        this.player = entity;
    }

    /**
     * Method used to create enemy {@link Entity}s
     * @param x Enemies bottom-left corner x coordinate
     * @param y Enemies bottom-left corner x coordinate
     * @param range Enemy movement range
     */
    private void createEnemy(float x, float y, float range) {
        float xCorrected = x + 0.5f;
        float yCorrected = 2 + y + 1;

        Entity entity = engine.createEntity();
        BodyComponent b2dbody = engine.createComponent(BodyComponent.class);
        TransformComponent position = engine.createComponent(TransformComponent.class);
        TextureComponent texture = engine.createComponent(TextureComponent.class);
        EnemyComponent enemy = engine.createComponent(EnemyComponent.class);
        TypeComponent type = engine.createComponent(TypeComponent.class);

        b2dbody.body = bodyFactory.makeBoxPolyBody(xCorrected,yCorrected,1, 2,  Materials.STEEL, BodyDef.BodyType.KinematicBody,true);
        position.position.set(xCorrected,yCorrected,0);

        texture.region = textureAtlas.findRegion("robotStillRight");
        texture.width = RenderingSystem.MetersToPixels(1);
        texture.height = RenderingSystem.MetersToPixels(2);

        enemy.xPosCenter = xCorrected;
        enemy.range = range;
        type.type = TypeComponent.ENEMY;
        b2dbody.body.setUserData(entity);

        entity.add(b2dbody);
        entity.add(position);
        entity.add(texture);
        entity.add(enemy);
        entity.add(type);

        engine.addEntity(entity);
    }

    /**
     * Method used to create custom sized platforms
     * @param x platform bottom-left corner x coordinate
     * @param y platform bottom-left corner x coordinate
     * @param width platform width in meters
     * @param height platform height in meters
     */
    private void createPlatform(float x, float y, float width, float height) {
        float xCorrected = x + width / 2;
        float yCorrected = 2 + y + height / 2;

        Entity entity = engine.createEntity();

        BodyComponent b2dbody = engine.createComponent(BodyComponent.class);
        b2dbody.body = bodyFactory.makeBoxPolyBody(xCorrected, yCorrected, width, height, Materials.STONE, BodyDef.BodyType.StaticBody);

        TextureComponent texture = engine.createComponent(TextureComponent.class);
        texture.region = textureAtlas.findRegion("platformFull");
        texture.width = RenderingSystem.MetersToPixels(width);
        texture.height = RenderingSystem.MetersToPixels(height);

        TransformComponent position = engine.createComponent(TransformComponent.class);
        position.position.set(xCorrected, yCorrected, 0);

        TypeComponent type = engine.createComponent(TypeComponent.class);
        type.type = TypeComponent.SCENERY;
        b2dbody.body.setUserData(entity);
        entity.add(b2dbody);
        entity.add(texture);
        entity.add(position);
        entity.add(type);
        engine.addEntity(entity);
    }

    /**
     * Method used to create teleporter {@link Entity}s
     * @param x teleporter bottom-left corner x coordinate
     * @param y teleporter bottom-left corner y coordinate
     * @param teleportX teleporter destination x coordinate
     * @param teleportY teleporter destination y coordinate
     * @param levelChanger Whether or not the teleporter changes the level
     */
    private void createTeleporter(float x, float y, float teleportX, float teleportY, boolean levelChanger) {
        float xCorrected = x + 0.5f;
        float yCorrected = y + 3;

        Entity entity = engine.createEntity();

        BodyComponent body = engine.createComponent(BodyComponent.class);
        body.body = bodyFactory.makeBoxPolyBody(xCorrected, yCorrected, 1, 2, Materials.STONE, BodyDef.BodyType.StaticBody);

        bodyFactory.makeAllFixturesSensors(body.body);

        TextureComponent texture = engine.createComponent(TextureComponent.class);
        texture.region = textureAtlas.findRegion("teleporter");
        texture.width = RenderingSystem.MetersToPixels(1);
        texture.height = RenderingSystem.MetersToPixels(2);

        TransformComponent position = engine.createComponent(TransformComponent.class);
        position.position.set(xCorrected, yCorrected, 0);

        TypeComponent type = engine.createComponent(TypeComponent.class);
        type.type = TypeComponent.TELEPORTER;

        TeleporterComponent teleporterComponent = engine.createComponent(TeleporterComponent.class);
        teleporterComponent.x = teleportX;
        teleporterComponent.y = teleportY;
        teleporterComponent.levelChanger = levelChanger;

        body.body.setUserData(entity);
        entity.add(body);
        entity.add(texture);
        entity.add(position);
        entity.add(type);
        entity.add(teleporterComponent);

        engine.addEntity(entity);
    }

    /**
     * Method used to create furniture {@link Entity}s
     * @param x Furniture bottom-left corner x coordinate
     * @param y Furniture bottom-left corner y coordinate
     * @param interactable Whether or not the player can interact with this {@link Entity}
     */
    private void createFurniture(float x, float y, boolean interactable) {
        float widthInM = 1, heightInM = 1;

        TextureComponent textureComponent = engine.createComponent(TextureComponent.class);

        int size = furnitureTextures.size();
        int item = new Random().nextInt(size);
        int i = 0;
        for(TextureComponent tc : furnitureTextures)
        {
            if (i == item) {
                textureComponent = tc;
                widthInM = RenderingSystem.PixelsToMeters(tc.width);
                heightInM = RenderingSystem.PixelsToMeters(tc.height);
            }
            i++;
        }

        float xCorrected = x + widthInM / 2;
        float yCorrected = 2 + y + heightInM / 2;

        Entity entity = engine.createEntity();

        TransformComponent position = engine.createComponent(TransformComponent.class);
        position.position.set(xCorrected, yCorrected, 0);


        BodyComponent body = engine.createComponent(BodyComponent.class);
        body.body = bodyFactory.makeBoxPolyBody(xCorrected, yCorrected, widthInM, heightInM, Materials.WOOD, BodyDef.BodyType.KinematicBody);
        body.bounds.setPosition(body.body.getPosition());
        body.bounds.setSize(widthInM, heightInM);
        body.interactable = interactable;

        TypeComponent type = engine.createComponent(TypeComponent.class);
        type.type = TypeComponent.FURNITURE;

        body.body.setUserData(entity);
        bodyFactory.makeAllFixturesSensors(body.body);

        CollisionComponent colCom = engine.createComponent(CollisionComponent.class);

        entity.add(body);
        entity.add(position);
        entity.add(textureComponent);
        entity.add(type);
        entity.add(colCom);

        engine.addEntity(entity);
    }

    /*
        max(x) = 20;
        max(y) = 13;
     */

    /**
     * Method used to clear the level before generating the next one
     */
    public void clearLevel() {
        Family playerFamily = Family.all(PlayerComponent.class).get();
        Array<Body> bodies = new Array<Body>();
        world.getBodies(bodies);

        for(Entity e :engine.getEntities()) {
            if(!playerFamily.matches(e)) {
                // System.out.println(e);
                engine.removeEntity(e);
            }
        }

        for(Body b : bodies) {
            if(!b.equals(player.getComponent(BodyComponent.class).body)) world.destroyBody(b);
        }
        engine.clearPools();
    }

    /**
     * Generates the first level
     */
    public void generateLevel1() {
        currentLvl = 1;
        createBox();
        createPlayer(camera);

        createPlatform(0, 4, 4, 0.5f);
        createPlatform(0, 9.5f, 4, 0.5f);
        createPlatform(7.5f, 0, 0.5f, 2.5f);
        createPlatform(6, 2.5f, 3.5f, 0.5f);
        createPlatform(6.5f, 8, 3.5f, 0.5f);
        createPlatform(11, 4, 1, 0.5f);
        createPlatform(13.5f, 6.5f, 6.5f, 0.5f);
        createPlatform(16, 9.5f, 4, 0.5f);

        createFurniture(1, 10, true);
        createFurniture(7.5f, 8.5f, true);
        createFurniture(8.5f, 0, true);
        createFurniture(17.5f, 7, true);

        createEnemy(1.5f, 4.5f, 1.5f);
        createEnemy(13.5f, 0, 5.5f);
        createEnemy(16.25f, 7, 2.75f);

        createTeleporter(18, 10, 1, 10, true);
    }

    /**
     * Generates the second level
     */
    public void generateLevel2() {
        clearLevel();
        createBox();

        createPlatform(0, 9.5f, 13, 0.5f);
        createPlatform(12.5f, 6.5f, 0.5f, 3);
        createPlatform(12.5f, 6, 6, 0.5f);
        createPlatform(14.5f, 11.5f, 0.5f, 1.5f);
        createPlatform(15, 10.5f, 0.5f, 1.5f);
        createPlatform(14.5f, 9.5f, 0.5f, 1.5f);
        createPlatform(15, 9, 0.5f, 1.5f);
        createPlatform(17, 6.5f, 0.5f, 3);
        createPlatform(17, 9.5f, 1.5f, 0.5f);
        createPlatform(18, 6.5f, 0.5f, 3);
        createPlatform(0, 6.5f, 2.5f, 0.5f); // 10
        createPlatform(5, 6.5f, 3, 0.5f);
        createPlatform(8.5f, 4.5f, 1, 1);
        createPlatform(9, 4, 1, 1);
        createPlatform(9.5f, 3.5f, 1, 1);
        createPlatform(10, 3, 1, 1);
        createPlatform(10.5f, 3, 9.5f, 0.5f);
        createPlatform(0, 0, 4, 2.5f);
        createPlatform(4, 0, 4, 1);

        createFurniture(0, 7, true);
        createFurniture(14, 6.5f,true);
        createFurniture(8, 10, true);
        createFurniture(0.5f, 2.5f,true);
        createFurniture(12, 0,true);

        createEnemy(6, 1,2);

        createTeleporter(17.5f, 0, 10, 10, true);
    }

    /**
     * Generates the third level
     */
    public void generateLevel3() {
        clearLevel();
        createBox();

        createPlatform(8.5f, 9.5f);
    }
}
