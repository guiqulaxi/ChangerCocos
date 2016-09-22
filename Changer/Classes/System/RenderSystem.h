//
//  RenderSystem.h
//  Changer
//
//  Created by WilhanTian on 16/9/22.
//
//

#ifndef RenderSystem_h
#define RenderSystem_h

#include "cocos2d.h"
#include "ECS/EntityFu.h"

class RenderSystem : public System
{
public:
    static void tick(float dt);
};

#endif /* RenderSystem_h */
