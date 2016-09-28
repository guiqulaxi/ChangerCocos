//
//  CollisionSystem.hpp
//  Changer
//
//  Created by WilhanTian on 16/9/23.
//
//

#ifndef CollisionSystem_h
#define CollisionSystem_h

#include "cocos2d.h"
#include "ECS/EntityFu.h"

/// 碰撞系统
/// 检测一切碰撞
class CollisionSystem : public System
{
public:
    static void tick(float dt);
    
    /// 获取碰撞实体
    static std::vector<Eid> getCollisionEntities(Eid id);
    static Eid getCollisionEntity(Eid id);
};

#endif /* CollisionSystem_h */
