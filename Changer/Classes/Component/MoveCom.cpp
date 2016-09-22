//
//  MoveCom.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/22.
//
//

#include "MoveCom.h"

USING_NS_CC;

MoveCom::MoveCom(cocos2d::Vec2 pos, cocos2d::Vec2 speed)
    : pos(pos)
    , speed(speed)
{
    printf("**** %f, %f", speed.x, speed.y);
}

MoveCom::MoveCom()
: MoveCom(Vec2(0, 0), Vec2(0, 0))
{
}

bool MoveCom::empty() const
{
    return speed.isZero();
}