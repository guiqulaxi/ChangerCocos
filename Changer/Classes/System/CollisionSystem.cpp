//
//  CollisionSystem.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/23.
//
//

#include "CollisionSystem.h"

#include "Core/common.h"
#include "Component/ComList.h"

USING_NS_CC;

void CollisionSystem::tick(float dt)
{
    auto all = Entity::getAll<CollisionCom>();
    for(Eid id : all)
    {
        Ent e(id);
        CollisionCom& collision = e.collision;
        PositionCom& position = e.position;
        
        if(collision.empty()) continue;
        if(position.empty()) continue;
        
        auto oId = CollisionSystem::getCollisionEntity(id);
        CollisionCom& oColl = Entity::get<CollisionCom>(oId);
        
        // 如果发生碰撞 立即向当前组件填入(被)击飞组件
        if(collision.collisionType == kCollisionType::kPlayer
            && oColl.collisionType == kCollisionType::kMonster)
        {
            Vec2 distance;
            if(!e.move.empty())
            {
                distance = e.move.speed;
                distance.normalize();
                distance *= -1000;
            }

            Entity::addComponent(id, new BlowFlyCom(distance, 100, 1));
        }
        
        
        
        // FIXME
        if(kCollisionDebug)
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

std::vector<Eid> CollisionSystem::getCollisionEntities(Eid _id)
{
    std::vector<Eid> ids;
    
    Ent _e(_id);
    CollisionCom& _collision = _e.collision;
    PositionCom& _position = _e.position;
    
    if(_collision.empty()) return ids;
    if(_position.empty()) return ids;
    
    Rect _rect = Rect(_position.pos, _collision.size);
    
    auto all = Entity::getAll<CollisionCom>();
    for(Eid id : all)
    {
        Ent e(id);
        CollisionCom& collision = e.collision;
        PositionCom& position = e.position;
        
        if(id == _id) continue;
        if(collision.empty()) continue;
        if(position.empty()) continue;
        
        Rect rect = Rect(position.pos, collision.size);
        if(_rect.intersectsRect(rect))// 检测包围盒碰撞
        {
            ids.push_back(id);
        }
    }
    
    return ids;
}

Eid CollisionSystem::getCollisionEntity(Eid _id)
{
    Ent _e(_id);
    CollisionCom& _collision = _e.collision;
    PositionCom& _position = _e.position;
    
    if(_collision.empty()) return _id;
    if(_position.empty()) return _id;
    
    Rect _rect = Rect(_position.pos, _collision.size);
    
    auto all = Entity::getAll<CollisionCom>();
    for(Eid id : all)
    {
        Ent e(id);
        CollisionCom& collision = e.collision;
        PositionCom& position = e.position;
        
        if(id == _id) continue;
        if(collision.empty()) continue;
        if(position.empty()) continue;
        
        Rect rect = Rect(position.pos, collision.size);
        if(_rect.intersectsRect(rect))// 检测包围盒碰撞
        {
            return id;
        }
    }
    
    return -1;
}
