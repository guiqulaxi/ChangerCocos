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
#include "common.h"

USING_NS_CC;

void InputSystem::tick(float dt)
{
    auto inputMgr = InputManager::getInstance();
    auto all = Entity::getAll<MoveCom>();
    for(Eid id : all)
    {
        System::Ent e(id);
        MoveCom& move = e.move;
        
        if(inputMgr->isKeyDown(cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW))
        {
            move.speed.x = -kPlayerSpeed;
        }
        else if(inputMgr->isKeyDown(cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW))
        {
            move.speed.x = kPlayerSpeed;
        }
        else{
            move.speed.x = .0f;
        }
        
        if(inputMgr->isKeyDown(cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW))
        {
            move.speed.y = kPlayerSpeed;
        }
        else if(inputMgr->isKeyDown(cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW))
        {
            move.speed.y = -kPlayerSpeed;
        }
        else{
            move.speed.y = .0f;
        }
    }
    
}
