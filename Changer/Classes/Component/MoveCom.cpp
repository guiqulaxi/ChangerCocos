//
//  MoveCom.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/22.
//
//

#include "MoveCom.h"

USING_NS_CC;

MoveCom::MoveCom(cocos2d::Vec2 speed)
: speed(speed)
{
}

MoveCom::MoveCom()
    : MoveCom(Vec2(0,0))
{
}

bool MoveCom::empty() const
{
    return speed.isZero();
}
