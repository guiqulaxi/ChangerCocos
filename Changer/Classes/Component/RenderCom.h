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

enum kAnimType
{
    kDown = 0,
    kUp,
    kLeft,
    kRight,
    
    kFightDown,
    kFightUp,
    kFightLeft,
    kFightRight
};

/// 渲染组件
/// 基础组件，用来渲染一切对象
struct RenderCom : Entity::Component
{
    CREATE_CID;
    
    cocos2d::Sprite* sprite;
    std::vector<cocos2d::SpriteFrame*> frames;
    kAnimType type = kAnimType::kDown;
    float rate = 2;
    float curDt;
    int index;
    
    RenderCom(const std::string& filename, cocos2d::Layer* layer);
    RenderCom();
    
    ~RenderCom();
    
    virtual bool empty() const;
};

#endif /* RenderCom_hpp */
