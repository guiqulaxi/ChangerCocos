//
//  MoveCom.h
//  Changer
//
//  Created by WilhanTian on 16/9/22.
//
//

#ifndef _MOVE_COM_H_
#define _MOVE_COM_H_

#include "cocos2d.h"
#include "ECS/EntityFu.h"

struct MoveCom : Entity::Component
{
    CREATE_CID;
    
    cocos2d::Vec2 pos;//position
    cocos2d::Vec2 speed;
    
    MoveCom(cocos2d::Vec2 pos, cocos2d::Vec2 speed);
    MoveCom();
    
    virtual bool empty() const;
};

#endif //_MOVE_COM_H_