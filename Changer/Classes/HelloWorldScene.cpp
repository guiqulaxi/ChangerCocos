#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "Component/ComList.h"
#include "System/MoveSystem.h"
#include "System/RenderSystem.h"

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
    
    this->scheduleUpdate();
    this->initEntity();
    
    return true;
}

void HelloWorld::initEntity()
{
    Eid id = Entity::create();
    Entity::addComponent(id, new MoveCom(Vec2(100, 100), Vec2(50, 20)));
    Entity::addComponent(id, new RenderCom("CloseNormal.png", this));
}

void HelloWorld::update(float dt)
{
    MoveSystem::tick(dt);
    RenderSystem::tick(dt);
}
