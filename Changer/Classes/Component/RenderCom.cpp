//
//  RenderCom.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/22.
//
//

#include "RenderCom.h"

USING_NS_CC;

RenderCom::RenderCom(const std::string& filename, Layer* layer)
{
    sprite = Sprite::create(filename);
    
    if(sprite == nullptr)
        return;
    
    layer->addChild(sprite);
}

RenderCom::RenderCom()
    : RenderCom("", nullptr)
{
}

bool RenderCom::empty() const
{
    return sprite == nullptr;
}