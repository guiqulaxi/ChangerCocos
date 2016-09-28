//
//  CollisionCom.hpp
//  Changer
//
//  Created by WilhanTian on 16/9/23.
//
//

#ifndef CollisionCom_h
#define CollisionCom_h

#include "cocos2d.h"
#include "ECS/EntityFu.h"
#include "Core/common.h"

/// 碰撞组件
/// 内部拥有一个碰撞包围盒(AABB)
struct CollisionCom : Entity::Component
{
    CREATE_CID;
    
    cocos2d::Vec2 pos;//offset position
    cocos2d::Size size;
    
    kCollisionType collisionType;

    CollisionCom(cocos2d::Vec2 pos, cocos2d::Size size, kCollisionType collisionType);
    CollisionCom();
    
    virtual bool empty() const;
};


#endif /* CollisionCom_h */
