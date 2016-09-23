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

#include "MoveCom.h"
#include "RenderCom.h"
#include "CollisionCom.h"

struct System::Ent
{
    Eid id;
    
    //BEGIN
    MoveCom& move;
    RenderCom& render;
    CollisionCom& collision;
    //END
    
    Ent(Eid _id);
};

#endif /* ComList_hpp */
