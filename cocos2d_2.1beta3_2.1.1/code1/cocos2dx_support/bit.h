#ifndef bit123_h__
#define bit123_h__

#define LUA_BITOP_VERSION	"1.0.2"

#define LUA_LIB

extern "C"
{
#	include "lua.h"
#	include "lauxlib.h"
};


LUALIB_API int luaopen_bit_custom(lua_State *L);

#endif // bit_h__