//
//  CollisionSystem.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/23.
//
//

#include "CollisionSystem.h"

#include "common.h"
#include "Component/ComList.h"

USING_NS_CC;

void CollisionSystem::tick(float dt)
{
    auto all = Entity::getAll<CollisionCom>();
    for(Eid id : all)
    {
        Ent e(id);
        CollisionCom& collision = e.collision;
        MoveCom& move = e.move;
        
        if(collision.empty())
            continue;
        
        if(move.empty())
            continue;
        
        if(true)
        {
            RenderCom& render = e.render;
            if(!render.empty())
            {
                Sprite* debugSprite = (Sprite*)render.sprite->getChildByName("__collisionDebug");
                if(!debugSprite)
                {
                    debugSprite = Sprite::create("pix.png");
                    debugSprite->setPosition(collision.pos);
                    debugSprite->setScale(collision.size.width, collision.size.height);
                    debugSprite->setColor(Color3B(255, 0, 0));
                    debugSprite->setOpacity(255/2);
                    debugSprite->setName("__collisionDebug");
                    render.sprite->addChild(debugSprite);
                }
            }
        }
        
    }
}