//
//  InputSystem.h
//  Changer
//
//  Created by WilhanTian on 16/9/23.
//
//

#ifndef InputSystem_h
#define InputSystem_h

#include "ECS/EntityFu.h"

class InputSystem : public Entity::Component
{
public:
    static void tick(float dt);
};

#endif /* InputSystem_hpp */
