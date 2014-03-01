#ifndef LuaUI_h__
#define LuaUI_h__


extern "C" {
#include "tolua++.h"
#include "tolua_fix.h"
}


TOLUA_API int tolua_UI_open(lua_State* tolua_S);

#endif