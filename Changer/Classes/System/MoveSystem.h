//
//  MoveSystem.hpp
//  Changer
//
//  Created by WilhanTian on 16/9/22.
//
//

#ifndef MoveSystem_h
#define MoveSystem_h

#include "ECS/EntityFu.h"

class MoveSystem : public System
{
public:
    static void tick(float dt);
};

#endif /* MoveSystem_hpp */
