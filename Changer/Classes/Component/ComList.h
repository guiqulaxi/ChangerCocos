//
//  ComList.hpp
//  Changer
//
//  Created by WilhanTian on 16/9/22.
//
//

#ifndef ComList_h
#define ComList_h

#include "ECS/EntityFu.h"

#include "PositionCom.h"
#include "MoveCom.h"
#include "BlowFlyCom.h"
#include "RenderCom.h"
#include "CollisionCom.h"
#include "InputCom.h"

struct System::Ent
{
    Eid id;
    
    //BEGIN
    PositionCom& position;
    MoveCom& move;
    BlowFlyCom& blowFly;
    RenderCom& render;
    CollisionCom& collision;
    InputCom& input;
    //END
    
    Ent(Eid _id);
};

#endif /* ComList_hpp */
