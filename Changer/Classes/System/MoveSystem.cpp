//
//  MoveSystem.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/22.
//
//

#include "MoveSystem.h"
#include "cocos2d.h"
#include "Component/ComList.h"

void MoveSystem::tick(float dt)
{
    auto all = Entity::getAll<MoveCom>();
    for(Eid id : all)
    {
        Ent e(id);
        MoveCom& move = e.move;

        cocos2d::log("== %f, %f", move.pos.x, move.pos.y);
        
        if(move.empty())
            continue;
        
        move.pos += move.speed * dt;
        
        cocos2d::log("%f, %f", move.pos.x, move.pos.y);
    }
}