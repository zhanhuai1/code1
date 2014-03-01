LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

APP_CPPFLAGS += -DCOCOS2D_DEBUG=1

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../cocos2dx_support/bit.cpp \
                   ../../cocos2dx_support/CCLuaEngine.cpp \
                   ../../cocos2dx_support/Cocos2dxLuaLoader.cpp \
                   ../../cocos2dx_support/LuaCocos2d.cpp \
                   ../../cocos2dx_support/LuaUI.cpp \
                   ../../cocos2dx_support/tolua_fix.c
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
										$(LOCAL_PATH)/../../../cocos2dx/platform \
										$(LOCAL_PATH)/../../../cocos2dx/include  \
										$(LOCAL_PATH)/../../cocos2dx_support  \
										$(LOCAL_PATH)/../../../extensions/GUI              

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static cocos_lua_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions) $(call import-module,scripting/lua/proj.android/jni)
