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

/// 输入系统
/// 用来处理一切外部设备输入
class InputSystem : public Entity::Component
{
public:
    static void tick(float dt);
};

#endif /* InputSystem_hpp */
