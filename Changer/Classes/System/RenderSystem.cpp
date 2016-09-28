//
//  RenderSystem.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/22.
//
//

#include "RenderSystem.h"
#include "Component/ComList.h"

USING_NS_CC;

void RenderSystem::tick(float dt)
{
    auto all = Entity::getAll<RenderCom>();
    for(Eid id : all)
    {
        Ent e(id);
        RenderCom& render = e.render;
        PositionCom& position = e.position;
        MoveCom& move = e.move;
        
        if(render.empty())
            continue;
        
        // FIXME
//        if(move.empty())
//            continue;
        
        render.sprite->setPosition(position.pos);
        
        // set frame
        if(render.curDt > 1.f / render.rate)
        {
            render.index = (render.index + 1) % render.frames.size();
            render.sprite->setSpriteFrame(render.frames[render.index]);
            render.curDt = 0.f;
        }
        else
        {
            render.curDt += dt;
        }
    }
}
