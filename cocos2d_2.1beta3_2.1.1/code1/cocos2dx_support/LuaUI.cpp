
#include "LuaUI.h"
#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"
#include "CCControlExtension\CCControlButton.h"
#include "CCLuaEngine.h"

using namespace cocos2d;
using namespace cocos2d::extension;

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
	tolua_usertype(tolua_S,"CCScale9Sprite");
	tolua_usertype(tolua_S,"CCControl");
	tolua_usertype(tolua_S,"CCLayer");
	tolua_usertype(tolua_S,"CCSize");
	tolua_usertype(tolua_S,"CCSpriteFrame");
	tolua_usertype(tolua_S,"CCNode");
	tolua_usertype(tolua_S,"CCRect");
	tolua_usertype(tolua_S,"CCControlButton");
}

/* method: setEnabled of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControl_setEnabled00
static int tolua_Controls_CCControl_setEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
		!tolua_isboolean(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
		bool bEnabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEnabled'", NULL);
#endif
		{
			self->setEnabled(bEnabled);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setEnabled'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isEnabled of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControl_isEnabled00
static int tolua_Controls_CCControl_isEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isEnabled'", NULL);
#endif
		{
			bool tolua_ret = (bool)  self->isEnabled();
			tolua_pushboolean(tolua_S,(bool)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'isEnabled'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSelected of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControl_setSelected00
static int tolua_Controls_CCControl_setSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
		!tolua_isboolean(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
		bool bSelected = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSelected'", NULL);
#endif
		{
			self->setSelected(bSelected);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setSelected'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isSelected of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControl_isSelected00
static int tolua_Controls_CCControl_isSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isSelected'", NULL);
#endif
		{
			bool tolua_ret = (bool)  self->isSelected();
			tolua_pushboolean(tolua_S,(bool)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'isSelected'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHighlighted of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControl_addScriptCallBackForControlEvent00
static int tolua_Controls_CCControl_addScriptCallBackForControlEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
		!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,3,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
		LUA_FUNCTION nHandler = (  toluafix_ref_function(tolua_S,2,0));
		CCControlEvent controlEvent = (unsigned int)tolua_tonumber(tolua_S,3,0);
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addScriptCallBackForControlEvent'", NULL);
#endif
		{
			self->addScriptCallBackForControlEvent(nHandler, controlEvent);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'addScriptCallBackForControlEvent'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHighlighted of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControl_setHighlighted00
static int tolua_Controls_CCControl_setHighlighted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
		!tolua_isboolean(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
		bool bHighlighted = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHighlighted'", NULL);
#endif
		{
			self->setHighlighted(bHighlighted);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setHighlighted'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isHighlighted of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControl_isHighlighted00
static int tolua_Controls_CCControl_isHighlighted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isHighlighted'", NULL);
#endif
		{
			bool tolua_ret = (bool)  self->isHighlighted();
			tolua_pushboolean(tolua_S,(bool)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'isHighlighted'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCScale9Sprite */
#ifndef TOLUA_DISABLE_tolua_Controls_CCScale9Sprite_create00
static int tolua_Controls_CCScale9Sprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCScale9Sprite",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		(tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CCRect",0,&tolua_err)) ||
		(tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CCRect",0,&tolua_err)) ||
		!tolua_isnoobj(tolua_S,5,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		const char* file = ((const char*)  tolua_tostring(tolua_S,2,0));
		CCRect rect = *((CCRect*)  tolua_tousertype(tolua_S,3,0));
		CCRect capInsets = *((CCRect*)  tolua_tousertype(tolua_S,4,0));
		{
			CCScale9Sprite* tolua_ret = (CCScale9Sprite*)  CCScale9Sprite::create(file,rect,capInsets);
			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCScale9Sprite");
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

/* method: create of class  CCScale9Sprite */
#ifndef TOLUA_DISABLE_tolua_Controls_CCScale9Sprite_create01
static int tolua_Controls_CCScale9Sprite_create01(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCScale9Sprite",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		(tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CCRect",0,&tolua_err)) ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
		)
		goto tolua_lerror;
	else
	{
		const char* file = ((const char*)  tolua_tostring(tolua_S,2,0));
		CCRect rect = *((CCRect*)  tolua_tousertype(tolua_S,3,0));
		{
			CCScale9Sprite* tolua_ret = (CCScale9Sprite*)  CCScale9Sprite::create(file,rect);
			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCScale9Sprite");
		}
	}
	return 1;
tolua_lerror:
	return tolua_Controls_CCScale9Sprite_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCScale9Sprite */
#ifndef TOLUA_DISABLE_tolua_Controls_CCScale9Sprite_create02
static int tolua_Controls_CCScale9Sprite_create02(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCScale9Sprite",0,&tolua_err) ||
		(tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)) ||
		!tolua_isstring(tolua_S,3,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
		)
		goto tolua_lerror;
	else
	{
		CCRect capInsets = *((CCRect*)  tolua_tousertype(tolua_S,2,0));
		const char* file = ((const char*)  tolua_tostring(tolua_S,3,0));
		{
			CCScale9Sprite* tolua_ret = (CCScale9Sprite*)  CCScale9Sprite::create(capInsets,file);
			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCScale9Sprite");
		}
	}
	return 1;
tolua_lerror:
	return tolua_Controls_CCScale9Sprite_create01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCScale9Sprite */
#ifndef TOLUA_DISABLE_tolua_Controls_CCScale9Sprite_create03
static int tolua_Controls_CCScale9Sprite_create03(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCScale9Sprite",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
	{
		const char* file = ((const char*)  tolua_tostring(tolua_S,2,0));
		{
			CCScale9Sprite* tolua_ret = (CCScale9Sprite*)  CCScale9Sprite::create(file);
			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCScale9Sprite");
		}
	}
	return 1;
tolua_lerror:
	return tolua_Controls_CCScale9Sprite_create02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithSpriteFrame of class  CCScale9Sprite */
#ifndef TOLUA_DISABLE_tolua_Controls_CCScale9Sprite_createWithSpriteFrame00
static int tolua_Controls_CCScale9Sprite_createWithSpriteFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCScale9Sprite",0,&tolua_err) ||
		!tolua_isusertype(tolua_S,2,"CCSpriteFrame",0,&tolua_err) ||
		(tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CCRect",0,&tolua_err)) ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCSpriteFrame* spriteFrame = ((CCSpriteFrame*)  tolua_tousertype(tolua_S,2,0));
		CCRect capInsets = *((CCRect*)  tolua_tousertype(tolua_S,3,0));
		{
			CCScale9Sprite* tolua_ret = (CCScale9Sprite*)  CCScale9Sprite::createWithSpriteFrame(spriteFrame,capInsets);
			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCScale9Sprite");
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'createWithSpriteFrame'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithSpriteFrame of class  CCScale9Sprite */
#ifndef TOLUA_DISABLE_tolua_Controls_CCScale9Sprite_createWithSpriteFrame01
static int tolua_Controls_CCScale9Sprite_createWithSpriteFrame01(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCScale9Sprite",0,&tolua_err) ||
		!tolua_isusertype(tolua_S,2,"CCSpriteFrame",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
	{
		CCSpriteFrame* spriteFrame = ((CCSpriteFrame*)  tolua_tousertype(tolua_S,2,0));
		{
			CCScale9Sprite* tolua_ret = (CCScale9Sprite*)  CCScale9Sprite::createWithSpriteFrame(spriteFrame);
			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCScale9Sprite");
		}
	}
	return 1;
tolua_lerror:
	return tolua_Controls_CCScale9Sprite_createWithSpriteFrame00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithSpriteFrameName of class  CCScale9Sprite */
#ifndef TOLUA_DISABLE_tolua_Controls_CCScale9Sprite_createWithSpriteFrameName00
static int tolua_Controls_CCScale9Sprite_createWithSpriteFrameName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCScale9Sprite",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		(tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CCRect",0,&tolua_err)) ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		const char* spriteFrameName = ((const char*)  tolua_tostring(tolua_S,2,0));
		CCRect capInsets = *((CCRect*)  tolua_tousertype(tolua_S,3,0));
		{
			CCScale9Sprite* tolua_ret = (CCScale9Sprite*)  CCScale9Sprite::createWithSpriteFrameName(spriteFrameName,capInsets);

			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCScale9Sprite");
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'createWithSpriteFrameName'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithSpriteFrameName of class  CCScale9Sprite */
#ifndef TOLUA_DISABLE_tolua_Controls_CCScale9Sprite_createWithSpriteFrameName01
static int tolua_Controls_CCScale9Sprite_createWithSpriteFrameName01(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCScale9Sprite",0,&tolua_err) ||
		!tolua_isstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
	{
		const char* spriteFrameName = ((const char*)  tolua_tostring(tolua_S,2,0));
		{
			CCScale9Sprite* tolua_ret = (CCScale9Sprite*)  CCScale9Sprite::createWithSpriteFrameName(spriteFrameName);

			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCScale9Sprite");
		}
	}
	return 1;
tolua_lerror:
	return tolua_Controls_CCScale9Sprite_createWithSpriteFrameName00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCScale9Sprite */
#ifndef TOLUA_DISABLE_tolua_Controls_CCScale9Sprite_create04
static int tolua_Controls_CCScale9Sprite_create04(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCScale9Sprite",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
		)
		goto tolua_lerror;
	else
	{
		{
			CCScale9Sprite* tolua_ret = (CCScale9Sprite*)  CCScale9Sprite::create();
			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCScale9Sprite");
		}
	}
	return 1;
tolua_lerror:
	return tolua_Controls_CCScale9Sprite_create03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setContentSize of class  CCScale9Sprite */
#ifndef TOLUA_DISABLE_tolua_Controls_CCScale9Sprite_setContentSize00
static int tolua_Controls_CCScale9Sprite_setContentSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCScale9Sprite",0,&tolua_err) ||
		(tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCScale9Sprite* self = (CCScale9Sprite*)  tolua_tousertype(tolua_S,1,0);
		const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setContentSize'", NULL);
#endif
		{
			self->setContentSize(*size);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setContentSize'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpriteFrame of class  CCScale9Sprite */
#ifndef TOLUA_DISABLE_tolua_Controls_CCScale9Sprite_setSpriteFrame00
static int tolua_Controls_CCScale9Sprite_setSpriteFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCScale9Sprite",0,&tolua_err) ||
		!tolua_isusertype(tolua_S,2,"CCSpriteFrame",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCScale9Sprite* self = (CCScale9Sprite*)  tolua_tousertype(tolua_S,1,0);
		CCSpriteFrame* spriteFrame = ((CCSpriteFrame*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpriteFrame'", NULL);
#endif
		{
			self->setSpriteFrame(spriteFrame);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setSpriteFrame'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEnabled of class  CCControlButton */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControlButton_setEnabled00
static int tolua_Controls_CCControlButton_setEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControlButton",0,&tolua_err) ||
		!tolua_isboolean(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControlButton* self = (CCControlButton*)  tolua_tousertype(tolua_S,1,0);
		bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEnabled'", NULL);
#endif
		{
			self->setEnabled(enabled);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setEnabled'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSelected of class  CCControlButton */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControlButton_setSelected00
static int tolua_Controls_CCControlButton_setSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControlButton",0,&tolua_err) ||
		!tolua_isboolean(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControlButton* self = (CCControlButton*)  tolua_tousertype(tolua_S,1,0);
		bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSelected'", NULL);
#endif
		{
			self->setSelected(enabled);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setSelected'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHighlighted of class  CCControlButton */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControlButton_setHighlighted00
static int tolua_Controls_CCControlButton_setHighlighted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControlButton",0,&tolua_err) ||
		!tolua_isboolean(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControlButton* self = (CCControlButton*)  tolua_tousertype(tolua_S,1,0);
		bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHighlighted'", NULL);
#endif
		{
			self->setHighlighted(enabled);
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setHighlighted'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isPushed of class  CCControlButton */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControlButton_isPushed00
static int tolua_Controls_CCControlButton_isPushed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControlButton",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControlButton* self = (CCControlButton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPushed'", NULL);
#endif
		{
			bool tolua_ret = (bool)  self->isPushed();
			tolua_pushboolean(tolua_S,(bool)tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'isPushed'.",&tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCControlButton */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControlButton_create00
static int tolua_Controls_CCControlButton_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCControlButton",0,&tolua_err) ||
		!tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
		!tolua_isusertype(tolua_S,3,"CCScale9Sprite",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCNode* label = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
		CCScale9Sprite* backgroundSprite = ((CCScale9Sprite*)  tolua_tousertype(tolua_S,3,0));
		{
			CCControlButton* tolua_ret = (CCControlButton*)  CCControlButton::create(label,backgroundSprite);
			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCControlButton");
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

/* method: create of class  CCControlButton */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControlButton_create01
static int tolua_Controls_CCControlButton_create01(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCControlButton",0,&tolua_err) ||
		!tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isstring(tolua_S,3,0,&tolua_err) ||
		!tolua_isnumber(tolua_S,4,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,5,&tolua_err)
		)
		goto tolua_lerror;
	else
	{
		std::string title = ((std::string)  tolua_tocppstring(tolua_S,2,0));
		const char* fontName = ((const char*)  tolua_tostring(tolua_S,3,0));
		float fontSize = ((float)  tolua_tonumber(tolua_S,4,0));
		{
			CCControlButton* tolua_ret = (CCControlButton*)  CCControlButton::create(title,fontName,fontSize);
			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCControlButton");
		}
	}
	return 1;
tolua_lerror:
	return tolua_Controls_CCControlButton_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCControlButton */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControlButton_create02
static int tolua_Controls_CCControlButton_create02(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCControlButton",0,&tolua_err) ||
		!tolua_isusertype(tolua_S,2,"CCScale9Sprite",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
	{
		CCScale9Sprite* sprite = ((CCScale9Sprite*)  tolua_tousertype(tolua_S,2,0));
		{
			CCControlButton* tolua_ret = (CCControlButton*)  CCControlButton::create(sprite);
			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCControlButton");
		}
	}
	return 1;
tolua_lerror:
	return tolua_Controls_CCControlButton_create01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCControlButton */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControlButton_create03
static int tolua_Controls_CCControlButton_create03(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S,1,"CCControlButton",0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,2,&tolua_err)
		)
		goto tolua_lerror;
	else
	{
		{
			CCControlButton* tolua_ret = (CCControlButton*)  CCControlButton::create();
			int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
			int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
			toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCControlButton");
		}
	}
	return 1;
tolua_lerror:
	return tolua_Controls_CCControlButton_create02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE



	/* method: create of class  CCControlButton */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControlButton_setAdjustBackgroundImage
static int tolua_Controls_CCControlButton_setAdjustBackgroundImage(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControlButton",0,&tolua_err) ||
		!tolua_isboolean(tolua_S,2,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControlButton* self = (CCControlButton*)  tolua_tousertype(tolua_S,1,0);
		bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAdjustBackgroundImage'", NULL);
#endif
		{
			self->setAdjustBackgroundImage(enabled);
		}
	}
	return 0;
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setAdjustBackgroundImage'.",&tolua_err);
	return 0;
}
#endif //#ifndef TOLUA_DISABLE


/* method: create of class  CCControlButton */
#ifndef TOLUA_DISABLE_tolua_Controls_CCControlButton_setBackgroundSpriteForState
static int tolua_Controls_CCControlButton_setBackgroundSpriteForState(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCControlButton",0,&tolua_err) ||
		!tolua_isusertype(tolua_S,2,"CCScale9Sprite",0,&tolua_err) ||
		!tolua_isnumber(tolua_S,3,0,&tolua_err)||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCControlButton* self = (CCControlButton*)  tolua_tousertype(tolua_S,1,0);
		CCScale9Sprite* sprite = (CCScale9Sprite*)	tolua_tousertype(tolua_S,2,0);
		CCControlState st = (CCControlState)(int) tolua_tonumber(tolua_S,3,0);
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBackgroundSpriteForState'", NULL);
#endif
		{
			self->setBackgroundSpriteForState(sprite, st);
		}
	}
	return 0;
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'setBackgroundSpriteForState'.",&tolua_err);
	return 0;
}
#endif //#ifndef TOLUA_DISABLE

TOLUA_API int tolua_UI_open( lua_State* tolua_S )
{
	tolua_open(tolua_S);
	tolua_reg_types(tolua_S);
	tolua_module(tolua_S,NULL,0);
	tolua_beginmodule(tolua_S,NULL);

	tolua_constant(tolua_S,"CCControlEventTouchDown",CCControlEventTouchDown);
	tolua_constant(tolua_S,"CCControlEventTouchDragInside",CCControlEventTouchDragInside);
	tolua_constant(tolua_S,"CCControlEventTouchDragOutside",CCControlEventTouchDragOutside);
	tolua_constant(tolua_S,"CCControlEventTouchDragEnter",CCControlEventTouchDragEnter);	
	tolua_constant(tolua_S,"CCControlEventTouchDragExit",CCControlEventTouchDragExit);
	tolua_constant(tolua_S,"CCControlEventTouchUpInside",CCControlEventTouchUpInside);
	tolua_constant(tolua_S,"CCControlEventTouchUpOutside",CCControlEventTouchUpOutside);
	tolua_constant(tolua_S,"CCControlEventTouchCancel",CCControlEventTouchCancel);
	tolua_constant(tolua_S,"CCControlEventValueChanged",CCControlEventValueChanged);


	tolua_constant(tolua_S,"CCControlStateNormal",CCControlStateNormal);
	tolua_constant(tolua_S,"CCControlStateHighlighted",CCControlStateHighlighted);
	tolua_constant(tolua_S,"CCControlStateDisabled",CCControlStateDisabled);
	tolua_constant(tolua_S,"CCControlStateSelected",CCControlStateSelected);

	tolua_cclass(tolua_S,"CCControl","CCControl","CCLayer",NULL);
	tolua_beginmodule(tolua_S,"CCControl");
	tolua_function(tolua_S,"setEnabled",tolua_Controls_CCControl_setEnabled00);
	tolua_function(tolua_S,"isEnabled",tolua_Controls_CCControl_isEnabled00);
	tolua_function(tolua_S,"setSelected",tolua_Controls_CCControl_setSelected00);
	tolua_function(tolua_S,"isSelected",tolua_Controls_CCControl_isSelected00);
	tolua_function(tolua_S,"setHighlighted",tolua_Controls_CCControl_setHighlighted00);
	tolua_function(tolua_S,"isHighlighted",tolua_Controls_CCControl_isHighlighted00);
	tolua_function(tolua_S,"addScriptCallBackForControlEvent",tolua_Controls_CCControl_addScriptCallBackForControlEvent00);
	tolua_endmodule(tolua_S);
	tolua_cclass(tolua_S,"CCScale9Sprite","CCScale9Sprite","CCNode",NULL);
	tolua_beginmodule(tolua_S,"CCScale9Sprite");
	tolua_function(tolua_S,"create",tolua_Controls_CCScale9Sprite_create00);
	tolua_function(tolua_S,"create",tolua_Controls_CCScale9Sprite_create01);
	tolua_function(tolua_S,"create",tolua_Controls_CCScale9Sprite_create02);
	tolua_function(tolua_S,"create",tolua_Controls_CCScale9Sprite_create03);
	tolua_function(tolua_S,"createWithSpriteFrame",tolua_Controls_CCScale9Sprite_createWithSpriteFrame00);
	tolua_function(tolua_S,"createWithSpriteFrame",tolua_Controls_CCScale9Sprite_createWithSpriteFrame01);
	tolua_function(tolua_S,"createWithSpriteFrameName",tolua_Controls_CCScale9Sprite_createWithSpriteFrameName00);
	tolua_function(tolua_S,"createWithSpriteFrameName",tolua_Controls_CCScale9Sprite_createWithSpriteFrameName01);
	tolua_function(tolua_S,"create",tolua_Controls_CCScale9Sprite_create04);
	tolua_function(tolua_S,"setContentSize",tolua_Controls_CCScale9Sprite_setContentSize00);
	tolua_function(tolua_S,"setSpriteFrame",tolua_Controls_CCScale9Sprite_setSpriteFrame00);
	tolua_endmodule(tolua_S);
	tolua_cclass(tolua_S,"CCControlButton","CCControlButton","CCControl",NULL);
	tolua_beginmodule(tolua_S,"CCControlButton");
	tolua_function(tolua_S,"setEnabled",tolua_Controls_CCControlButton_setEnabled00);
	tolua_function(tolua_S,"setSelected",tolua_Controls_CCControlButton_setSelected00);
	tolua_function(tolua_S,"setHighlighted",tolua_Controls_CCControlButton_setHighlighted00);
	tolua_function(tolua_S,"isPushed",tolua_Controls_CCControlButton_isPushed00);
	tolua_function(tolua_S,"create",tolua_Controls_CCControlButton_create00);
	tolua_function(tolua_S,"create",tolua_Controls_CCControlButton_create01);
	tolua_function(tolua_S,"create",tolua_Controls_CCControlButton_create02);
	tolua_function(tolua_S,"create",tolua_Controls_CCControlButton_create03);
	tolua_function(tolua_S,"setAdjustBackgroundImage",tolua_Controls_CCControlButton_setAdjustBackgroundImage);
	tolua_function(tolua_S,"setBackgroundSpriteForState",tolua_Controls_CCControlButton_setBackgroundSpriteForState);
	
	tolua_endmodule(tolua_S);
	tolua_endmodule(tolua_S);
	return 1;
}
