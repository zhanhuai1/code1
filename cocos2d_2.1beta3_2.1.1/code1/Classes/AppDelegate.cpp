#include "cocos2d.h"
#include "AppDelegate.h"
#include "SimpleAudioEngine.h"
#include "script_support/CCScriptSupport.h"
#include "CCLuaEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
    // fixed me
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
}

AppDelegate::~AppDelegate()
{
    // end simple audio engine here, or it may crashed on win32
    SimpleAudioEngine::sharedEngine()->end();
    //CCScriptEngineManager::purgeSharedManager();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
	
    // turn on display FPS
    //pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // register lua engine
    CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//     CCString* pstrFileContent = CCString::createWithContentsOfFile("scripts/main.lua");
//     if (pstrFileContent)
//     {
//         pEngine->executeString(pstrFileContent->getCString());
	//     }	
// 
// 	CCFileUtils::sharedFileUtils()->setResourceDirectory("");
// 	std::string script_path = CCFileUtils::sharedFileUtils()->getResourceDirectory();
// 	script_path.append("scripts");
// 	//std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("scripts/main.lua");
// 	pEngine->addSearchPath(script_path.c_str());
// 	script_path.append("/main.lua");
// 	//pEngine->executeScriptFile(script_path.c_str());
// 	CCString* pstrFileContent = CCString::createWithContentsOfFile(script_path.c_str());
// 	pEngine->executeString(pstrFileContent->getCString());
	std::string path = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("scripts/main.lua");
	CCLOG("main.lua path is %s", path.c_str());

	int x = path.find_last_of('/');
	std::string out_base_name = path.substr(x+1, path.size()-x-1);
	std::string script_path = path.substr(0, x);

	pEngine->addSearchPath(script_path.c_str());
	CCLOG("script path is:%s", script_path.c_str());

	std::string res_path = script_path.substr(0, script_path.rfind("/")+1);
	CCFileUtils::sharedFileUtils()->setResourceDirectory(res_path.c_str());
	CCLOG("res path is:%s", res_path.c_str());

	std::string main_file = script_path + "/main.lua";
	CCString* pstrFileContent = CCString::createWithContentsOfFile(main_file.c_str());
	if (pstrFileContent)
	{
		pEngine->executeString(pstrFileContent->getCString());
	}
	
#else
	std::string script_path = CCFileUtils::sharedFileUtils()->getDefaultResRootPath();
	
	script_path.append("scripts");
    //std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("scripts/main.lua");
    pEngine->addSearchPath(script_path.c_str());
	script_path.append("/main.lua");
    pEngine->executeScriptFile(script_path.c_str());

#endif 

	pEngine->executeGlobalFunction("Start");

	if (cocos2d::CCTime::gettimeofdayCocos2d(&m_last_updatetime, NULL) != 0)
	{
		CCLOG("cocos2d: Director: Error in gettimeofday");
	}
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
	CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
	pEngine->executeGlobalFunction("EnterBackground");

    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
	CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
	pEngine->executeGlobalFunction("EnterForeground");

    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

void AppDelegate::update()
{
	cocos2d::cc_timeval now;

// 	float delta_time = 0.0f;
// 	if (cocos2d::CCTime::gettimeofdayCocos2d(&now, NULL) != 0)
// 	{
// 		CCLOG("error in gettimeofday");
// 	}
// 	else
// 	{
// 		delta_time = (now.tv_sec - m_last_updatetime.tv_sec) + (now.tv_usec - m_last_updatetime.tv_usec) / 1000000.0f;
// 		m_last_updatetime = now;
// 	}
// 
// 	CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
// 
// 	CCLOG("AppDelegate::update()  %d", now.tv_sec);
// 	pEngine->executeGlobalFunctionEx("Update", "f", delta_time);
}
