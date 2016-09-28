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
    :curDt(0)
    ,index(0)
{
    sprite = Sprite::create();
    
    if(sprite == nullptr)
        return;
    
    layer->addChild(sprite);
    
    // fixme
    for(int i = 0; i < 6; i++)
    {
        // create a frame
        SpriteFrame* frame = SpriteFrame::create(filename, Rect(i*32, 31*type, 32, 31));
        frame->retain();
        frames.push_back(frame);
    }
}

RenderCom::RenderCom()
    : RenderCom("", nullptr)
{
}

RenderCom::~RenderCom()
{
    for(auto frame : frames)
    {
        if(frame) frame->release();
    }
}

bool RenderCom::empty() const
{
    return sprite == nullptr;
}
