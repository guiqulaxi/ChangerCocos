//
//  RenderCom.hpp
//  Changer
//
//  Created by WilhanTian on 16/9/22.
//
//

#ifndef RenderCom_hpp
#define RenderCom_hpp

#include "cocos2d.h"
#include "ECS/EntityFu.h"

struct RenderCom : Entity::Component
{
    CREATE_CID;
    
    cocos2d::Sprite* sprite;
    
    RenderCom(const std::string& filename, cocos2d::Layer* layer);
    RenderCom();
    
    virtual bool empty() const;
};

#endif /* RenderCom_hpp */
