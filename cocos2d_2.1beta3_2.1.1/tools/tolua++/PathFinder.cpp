/*
** Lua binding: PathFinder
** Generated automatically by tolua++-1.0.92 on 03/22/13 00:27:31.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_PathFinder_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_PathFinder (lua_State* tolua_S)
{
 PathFinder* self = (PathFinder*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"std::vector<unsigned int>");
 tolua_usertype(tolua_S,"PathFinder");
 tolua_usertype(tolua_S,"cocos2d::CCObject");
}

/* method: new of class  PathFinder */
#ifndef TOLUA_DISABLE_tolua_PathFinder_PathFinder_new00
static int tolua_PathFinder_PathFinder_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PathFinder",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned int w = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int h = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   PathFinder* tolua_ret = (PathFinder*)  Mtolua_new((PathFinder)(w,h));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PathFinder");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  PathFinder */
#ifndef TOLUA_DISABLE_tolua_PathFinder_PathFinder_new00_local
static int tolua_PathFinder_PathFinder_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PathFinder",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned int w = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int h = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   PathFinder* tolua_ret = (PathFinder*)  Mtolua_new((PathFinder)(w,h));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PathFinder");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Reset of class  PathFinder */
#ifndef TOLUA_DISABLE_tolua_PathFinder_PathFinder_Reset00
static int tolua_PathFinder_PathFinder_Reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PathFinder",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PathFinder* self = (PathFinder*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Reset'", NULL);
#endif
  {
   self->Reset();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBlock of class  PathFinder */
#ifndef TOLUA_DISABLE_tolua_PathFinder_PathFinder_SetBlock00
static int tolua_PathFinder_PathFinder_SetBlock00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PathFinder",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PathFinder* self = (PathFinder*)  tolua_tousertype(tolua_S,1,0);
  unsigned int x = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int y = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  bool block = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBlock'", NULL);
#endif
  {
   self->SetBlock(x,y,block);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBlock'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddDetination of class  PathFinder */
#ifndef TOLUA_DISABLE_tolua_PathFinder_PathFinder_AddDetination00
static int tolua_PathFinder_PathFinder_AddDetination00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PathFinder",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PathFinder* self = (PathFinder*)  tolua_tousertype(tolua_S,1,0);
  unsigned int dst_x = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int dst_y = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddDetination'", NULL);
#endif
  {
   self->AddDetination(dst_x,dst_y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddDetination'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPath of class  PathFinder */
#ifndef TOLUA_DISABLE_tolua_PathFinder_PathFinder_GetPath00
static int tolua_PathFinder_PathFinder_GetPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PathFinder",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"std::vector<unsigned int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PathFinder* self = (PathFinder*)  tolua_tousertype(tolua_S,1,0);
  unsigned int src_x = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int src_y = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  std::vector<unsigned int>* path = ((std::vector<unsigned int>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPath'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetPath(src_x,src_y,*path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_PathFinder_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"PathFinder","PathFinder","cocos2d::CCObject",tolua_collect_PathFinder);
  #else
  tolua_cclass(tolua_S,"PathFinder","PathFinder","cocos2d::CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"PathFinder");
   tolua_function(tolua_S,"new",tolua_PathFinder_PathFinder_new00);
   tolua_function(tolua_S,"new_local",tolua_PathFinder_PathFinder_new00_local);
   tolua_function(tolua_S,".call",tolua_PathFinder_PathFinder_new00_local);
   tolua_function(tolua_S,"Reset",tolua_PathFinder_PathFinder_Reset00);
   tolua_function(tolua_S,"SetBlock",tolua_PathFinder_PathFinder_SetBlock00);
   tolua_function(tolua_S,"AddDetination",tolua_PathFinder_PathFinder_AddDetination00);
   tolua_function(tolua_S,"GetPath",tolua_PathFinder_PathFinder_GetPath00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PathFinder (lua_State* tolua_S) {
 return tolua_PathFinder_open(tolua_S);
};
#endif

