//
//  ComList.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/22.
//
//

#include "ComList.h"

#define DEFINE_COM(_CLASS_NAME_) Cid _CLASS_NAME_::cid = __id++;
#define DEFINE_COM_BEGIN static unsigned __id = 0;
#define DEFINE_COM_END Cid Entity::Component::numCids = __id;

#define REGISTER_COM(_CLASS_NAME_, _PARAM_NAME_) _PARAM_NAME_(Entity::get<_CLASS_NAME_>(__id)),
#define REGISTER_COM_BEGIN System::Ent::Ent(Eid _id):
#define REGISTER_COM_END id(_id){}

DEFINE_COM_BEGIN
DEFINE_COM(MoveCom)
DEFINE_COM(RenderCom)
DEFINE_COM_END

REGISTER_COM_BEGIN
REGISTER_COM(MoveCom, move)
REGISTER_COM(RenderCom, render)
REGISTER_COM_END