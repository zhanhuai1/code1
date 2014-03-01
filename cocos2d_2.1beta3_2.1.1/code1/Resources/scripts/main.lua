require("BaseClass.BaseClass")
require("Screen.MovableObj")

require("Config.Config")
require("Config.EnemyAnimations")
require("Config.BulletAnimations")
require("Config.red")
require("Config.AllUIFrames")
require("Config.FontsConfig")
require("Config.MapsConfig.AllMaps")

require("Bullets.BaseBullet")
require("Bullets.BulletTypesConfig")
require("Enemys.BaseEnemy")
require("Enemys.EnemyTypesConfig")
require("Towers.BaseTower")
require("Towers.TowerTypesConfig")

require("Screen.Map")
require("Screen.ScreenManager")
require("Screen.ShineObjManager")
require("Screen.TileObj")

require("UI.BaseView")
require("UI.PopupMenu")
require("UI.GameInfoView")
require("UI.FailedView")
require("UI.SucceedView")

require("Utils.Utils")
require("Utils.SinHelper")
require("Utils.SinAnimManager")
require("Utils.EventSystem")
require("Utils.EventName")
require("Utils.TextureLoader")
require("Utils.AssetsHelper")



-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
	print("----------------------------------------")
	print("LUA ERROR: " .. tostring(msg) .. "\n")
	print(debug.traceback())
	print("----------------------------------------")
end

g_game_scene = nil
g_running_time = 0 				--秒
g_running_frame = 0
g_real_visible_rct = CCRect(0, 0, 0, 0)
g_real_visible_sz = CCSize(0,0)


GlobalEventSystem = EventSystem.New()

function Start()
	-- avoid memory leak
	collectgarbage("setpause", 100)
	collectgarbage("setstepmul", 5000)
	math.randomseed(os.time())
	
	--是否显示帧信息
	CCDirector:sharedDirector():setDisplayStats(false)
	--注册update函数
	CCDirector:sharedDirector():getScheduler():scheduleScriptFunc(Update, 0, false)

	-------------------------------------------------------------------
	--根据设备分辨率计算合适的设计分辨率
	local glview = CCDirector:sharedDirector():getOpenGLView()
	local frame_sz = glview:getFrameSize()
	
	local tiles_p = Config.MapTilesX / Config.MapTilesY
	local device_p = frame_sz.width / frame_sz.height
	local design_w = frame_sz.width
	local design_h = frame_sz.height
	print(string.format("frame_sz:%d, %d   tiles_p:%.4f,  device_p:%.4f", frame_sz.width, frame_sz.height, tiles_p, device_p))
	if tiles_p < device_p then
		design_w = Config.MapTilesX * Config.TileSize.width
		print("!!!!!!!!d 1   design_w:", design_w)
		if design_w > frame_sz.width then
			design_w = frame_sz.width
			print("!!!!!!!!d 2   design_w:", design_w)
			if design_w < Config.TileSize.width * 16 then
				design_w = Config.TileSize.width * 16
				print("!!!!!!!!d 3   design_w:", design_w)
			end
		end
		design_h = design_w / device_p
	else
		design_h = Config.MapTilesY * Config.TileSize.height
		if design_h > frame_sz.height then
			design_h = frame_sz.height
			if design_h < Config.TileSize.height * 9 then
				design_h = Config.TileSize.height * 9
			end
		end
		design_w = design_h * device_p
	end	
	g_real_visible_sz.width = design_w
	g_real_visible_sz.height = design_h
	g_real_visible_rct = CCRect(-design_w/2, -design_h/2, design_w, design_h)
	-- print(string.format("g_real_visible_rct:%.2f, %.2f, %.2f, %.2f", g_real_visible_rct.origin.x, g_real_visible_rct.origin.y, design_w, design_h))
	glview:setDesignResolutionSize(g_real_visible_sz.width, g_real_visible_sz.height, kResolutionShowAll)

	--------------------------------------------------------------------

	-- local sx = frame_sz.width / g_designed_wnd_sz.width
	-- local sy = frame_sz.height / g_designed_wnd_sz.height
	-- local min_s = (sx < sy) and sx or sy
	-- g_real_visible_sz.width = frame_sz.width / min_s
	-- g_real_visible_sz.height = frame_sz.height / min_s
	-- print("Real Window Size : ", g_real_visible_sz.width, g_real_visible_sz.height)
	-- glview:setDesignResolutionSize(g_real_visible_sz.width, g_real_visible_sz.height, kResolutionShowAll)

	-- local w, h = frame_sz.width / min_s, g_designed_wnd_sz.height
	-- print("g_real_visible_rct : ", w, h)
	-- g_real_visible_rct.size = CCSize(w, h)
	-- g_real_visible_rct.origin = ccp(-w/2, -h/2)

	SinHelper.New()
	SinAnimManager.New()
	ShineObjManager.New()
	ScreenManager.New()
	TextureLoader.New()

	--创建Scene
	g_game_scene = CCScene:create()
	CCDirector:sharedDirector():runWithScene(g_game_scene)

	--创建各个Screen
	GlobalEventSystem:Fire(EventName.GoMainMenu)
end

function Update(delta_time)
	g_running_time = g_running_time + delta_time
	g_running_frame = g_running_frame + 1
	-- print(g_running_time)
	TextureLoader.Instance:Update(delta_time, g_running_time)
	ScreenManager.Instance:Update(delta_time, g_running_time)
	SinAnimManager.Instance:Update(delta_time, g_running_time)
	ShineObjManager.Instance:Update(delta_time, g_running_time)
	return 1
end

function EnterForeground()
	print("EnterForeground!!!!!!!!!!!!!!!")
end

function EnterBackground()
	print("EnterBackground!!!!!!!!!!!!!!!!!!!")
end
