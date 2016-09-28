//
//  CollisionCom.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/23.
//
//

#include "CollisionCom.h"

USING_NS_CC;

CollisionCom::CollisionCom(Vec2 pos, Size size, kCollisionType collisionType)
    : pos(pos)
    , size(size)
    , collisionType(collisionType)
{
}

CollisionCom::CollisionCom()
: CollisionCom(Vec2::ZERO, Size::ZERO, kCollisionType::kNone)
{
}

bool CollisionCom::empty() const
{
    return size.equals(Size::ZERO);
}
