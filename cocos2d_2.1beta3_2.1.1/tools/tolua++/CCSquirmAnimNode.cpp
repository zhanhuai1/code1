/*
** Lua binding: Cocos2d
** Generated automatically by tolua++-1.0.92 on 10/19/13 18:34:56.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Cocos2d_open (lua_State* tolua_S);


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"CCSquirmAnimNode");
 tolua_usertype(tolua_S,"CCTexture2D");
 tolua_usertype(tolua_S,"ccColor3B");
}

/* method: create of class  CCSquirmAnimNode */
#ifndef TOLUA_DISABLE_tolua_Cocos2d_CCSquirmAnimNode_create00
static int tolua_Cocos2d_CCSquirmAnimNode_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSquirmAnimNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTexture2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTexture2D* color_texture = ((CCTexture2D*)  tolua_tousertype(tolua_S,2,0));
  CCTexture2D* mask_texture = ((CCTexture2D*)  tolua_tousertype(tolua_S,3,0));
  {
   CCSquirmAnimNode* tolua_ret = (CCSquirmAnimNode*)  CCSquirmAnimNode::create(color_texture,mask_texture);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSquirmAnimNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  CCSquirmAnimNode */
#ifndef TOLUA_DISABLE_tolua_Cocos2d_CCSquirmAnimNode_setOpacity00
static int tolua_Cocos2d_CCSquirmAnimNode_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSquirmAnimNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSquirmAnimNode* self = (CCSquirmAnimNode*)  tolua_tousertype(tolua_S,1,0);
  unsigned int opacity = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacity'", NULL);
#endif
  {
   self->setOpacity(opacity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  CCSquirmAnimNode */
#ifndef TOLUA_DISABLE_tolua_Cocos2d_CCSquirmAnimNode_setColor00
static int tolua_Cocos2d_CCSquirmAnimNode_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSquirmAnimNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSquirmAnimNode* self = (CCSquirmAnimNode*)  tolua_tousertype(tolua_S,1,0);
  const ccColor3B* color = ((const ccColor3B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTextureScale of class  CCSquirmAnimNode */
#ifndef TOLUA_DISABLE_tolua_Cocos2d_CCSquirmAnimNode_setTextureScale00
static int tolua_Cocos2d_CCSquirmAnimNode_setTextureScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSquirmAnimNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSquirmAnimNode* self = (CCSquirmAnimNode*)  tolua_tousertype(tolua_S,1,0);
  float f = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTextureScale'", NULL);
#endif
  {
   self->setTextureScale(f);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTextureScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaskScale of class  CCSquirmAnimNode */
#ifndef TOLUA_DISABLE_tolua_Cocos2d_CCSquirmAnimNode_setMaskScale00
static int tolua_Cocos2d_CCSquirmAnimNode_setMaskScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSquirmAnimNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSquirmAnimNode* self = (CCSquirmAnimNode*)  tolua_tousertype(tolua_S,1,0);
  float f = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaskScale'", NULL);
#endif
  {
   self->setMaskScale(f);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaskScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimSpeed of class  CCSquirmAnimNode */
#ifndef TOLUA_DISABLE_tolua_Cocos2d_CCSquirmAnimNode_setAnimSpeed00
static int tolua_Cocos2d_CCSquirmAnimNode_setAnimSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSquirmAnimNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSquirmAnimNode* self = (CCSquirmAnimNode*)  tolua_tousertype(tolua_S,1,0);
  float f = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimSpeed'", NULL);
#endif
  {
   self->setAnimSpeed(f);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Cocos2d_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"CCSquirmAnimNode","CCSquirmAnimNode","CCNode",NULL);
  tolua_beginmodule(tolua_S,"CCSquirmAnimNode");
   tolua_function(tolua_S,"create",tolua_Cocos2d_CCSquirmAnimNode_create00);
   tolua_function(tolua_S,"setOpacity",tolua_Cocos2d_CCSquirmAnimNode_setOpacity00);
   tolua_function(tolua_S,"setColor",tolua_Cocos2d_CCSquirmAnimNode_setColor00);
   tolua_function(tolua_S,"setTextureScale",tolua_Cocos2d_CCSquirmAnimNode_setTextureScale00);
   tolua_function(tolua_S,"setMaskScale",tolua_Cocos2d_CCSquirmAnimNode_setMaskScale00);
   tolua_function(tolua_S,"setAnimSpeed",tolua_Cocos2d_CCSquirmAnimNode_setAnimSpeed00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Cocos2d (lua_State* tolua_S) {
 return tolua_Cocos2d_open(tolua_S);
};
#endif

