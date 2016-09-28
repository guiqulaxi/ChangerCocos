#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "Core/InputManager.h"

#include "Component/ComList.h"
#include "System/MoveSystem.h"
#include "System/RenderSystem.h"
#include "System/InputSystem.h"
#include "System/CollisionSystem.h"
#include "System/BlowFlySystem.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->initEvent();
    this->scheduleUpdate();
    this->initEntity();
    
    return true;
}

void HelloWorld::initEvent()
{
    auto inputMgr = InputManager::getInstance();
    auto eventListener = EventListenerKeyboard::create();
    
    eventListener->onKeyPressed = [=](EventKeyboard::KeyCode code, Event* eve){
        inputMgr->addKeyState(code);
    };
    eventListener->onKeyReleased = [=](EventKeyboard::KeyCode code, Event* eve){
        inputMgr->removeKeyState(code);
    };
    
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
}

void HelloWorld::initEntity()
{
    // player
    Eid id = Entity::create();
    Entity::addComponent(id, new InputCom(1));
    Entity::addComponent(id, new PositionCom(Vec2(100, 100)));
    Entity::addComponent(id, new MoveCom(Vec2(0, 0)));
    Entity::addComponent(id, new RenderCom("player.png", this));
    Entity::addComponent(id, new CollisionCom(Vec2(19, 6), Size(40, 20), kCollisionType::kPlayer));
    
    // monster
    id = Entity::create();
    Entity::addComponent(id, new PositionCom(Vec2(300, 200)));
    Entity::addComponent(id, new MoveCom(Vec2(0, 0)));
    Entity::addComponent(id, new RenderCom("player.png", this));
    Entity::addComponent(id, new CollisionCom(Vec2(19, 6), Size(40, 20), kCollisionType::kMonster));
}

void HelloWorld::update(float dt)
{
    InputSystem::tick(dt);
    CollisionSystem::tick(dt);
    BlowFlySystem::tick(dt);
    MoveSystem::tick(dt);
    RenderSystem::tick(dt);
}
