//
//  InputSystem.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/23.
//
//

#include "InputSystem.h"

#include "Core/InputManager.h"
#include "Component/ComList.h"
#include "Core/common.h"

USING_NS_CC;

void InputSystem::tick(float dt)
{
    auto inputMgr = InputManager::getInstance();
    auto all = Entity::getAll<MoveCom>();
    for(Eid id : all)
    {
        System::Ent e(id);
        InputCom& input = e.input;
        MoveCom& move = e.move;
        
        if(input.empty()) continue;
        
        if(inputMgr->isKeyDown(cocos2d::EventKeyboard::KeyCode::KEY_A))
        {
            move.speed.x = -kPlayerSpeed;
        }
        else if(inputMgr->isKeyDown(cocos2d::EventKeyboard::KeyCode::KEY_D))
        {
            move.speed.x = kPlayerSpeed;
        }
        else{
            move.speed.x = .0f;
        }
        
        if(inputMgr->isKeyDown(cocos2d::EventKeyboard::KeyCode::KEY_W))
        {
            move.speed.y = kPlayerSpeed;
        }
        else if(inputMgr->isKeyDown(cocos2d::EventKeyboard::KeyCode::KEY_S))
        {
            move.speed.y = -kPlayerSpeed;
        }
        else{
            move.speed.y = .0f;
        }
    }
    
}
