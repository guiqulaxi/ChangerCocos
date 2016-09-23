//
//  InputManager.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/23.
//
//

#include "InputManager.h"

USING_NS_CC;

InputManager* InputManager::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new InputManager();
    }
    return _instance;
}

void InputManager::destoryInstance()
{
    if(_instance)
    {
        delete _instance;
        _instance = nullptr;
    }
}

InputManager::InputManager()
{
    
}

InputManager::~InputManager()
{
    
}

void InputManager::addKeyState(EventKeyboard::KeyCode keyCode)
{
    _keyStates[keyCode] = true;
}

void InputManager::removeKeyState(EventKeyboard::KeyCode keyCode)
{
    _keyStates[keyCode] = false;
}

bool InputManager::isKeyDown(cocos2d::EventKeyboard::KeyCode keyCode)
{
    return _keyStates[keyCode] == true;
}

InputManager* InputManager::_instance = nullptr;