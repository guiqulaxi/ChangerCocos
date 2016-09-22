//
//  RenderSystem.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/22.
//
//

#include "RenderSystem.h"
#include "Component/ComList.h"

void RenderSystem::tick(float dt)
{
    auto all = Entity::getAll<RenderCom>();
    for(Eid id : all)
    {
        Ent e(id);
        RenderCom& render = e.render;
        MoveCom& move = e.move;
        
        if(render.empty())
            continue;
        
        if(move.empty())
            continue;
        
        render.sprite->setPosition(move.pos);
    }
}