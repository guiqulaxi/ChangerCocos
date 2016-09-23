//
//  InputManager.h
//  Changer
//
//  Created by WilhanTian on 16/9/23.
//
//

#ifndef InputManager_h
#define InputManager_h

#include "cocos2d.h"

class InputManager
{
public:
    static InputManager* getInstance();
    static void destoryInstance();
    
    void addKeyState(cocos2d::EventKeyboard::KeyCode keyCode);
    void removeKeyState(cocos2d::EventKeyboard::KeyCode keyCode);
    
    bool isKeyDown(cocos2d::EventKeyboard::KeyCode keyCode);
    
private:
    InputManager();
    ~InputManager();
    
    static InputManager* _instance;
    
    std::map<cocos2d::EventKeyboard::KeyCode, bool> _keyStates;
};


#endif /* InputManager_h */
