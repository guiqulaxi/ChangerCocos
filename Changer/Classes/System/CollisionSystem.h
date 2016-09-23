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

class CollisionSystem : public System
{
public:
    static void tick(float dt);
};

#endif /* CollisionSystem_h */
