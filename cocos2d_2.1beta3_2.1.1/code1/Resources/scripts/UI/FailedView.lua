FailedView = FailedView or BaseClass(BaseView)

function FailedView:__init()
	self.root_bg = AssetsHelper.CreateUIScaleSprite("window_bg")
	self.root_bg:setContentSize(CCSize(512, 256))
	self.root_bg:setPosition(-128, -20)
	self.root_wnd:addChild(self.root_bg)

	print("!!!!!!!!!!!FailedView !!!!!!!!!!")
	self.title = CCLabelTTF:create("你输了！！！", "Helvetica", 28)
	self.title:setPosition(ccp(256, 200))
	self.root_bg:addChild(self.title)

	if self.btn_retry == nil then
		self.btn_retry = AssetsHelper.CreateButton("retry")
		self.btn_retry:setPosition(ccp(100, 100))
		self.root_bg:addChild(self.btn_retry)

		local func = function (event_type, x, y)
			self:Close()
			GlobalEventSystem:Fire(EventName.Retry)
		end
		self.btn_retry:addScriptCallBackForControlEvent(func, CCControlEventTouchUpInside)
	end

	if self.btn_go_mainmenu == nil then
		self.btn_go_mainmenu = AssetsHelper.CreateButton("go_mainmenu")
		self.btn_go_mainmenu:setPosition(ccp(300, 100))
		self.root_bg:addChild(self.btn_go_mainmenu)

		local func = function (event_type, x, y)
			self:Close()
			GlobalEventSystem:Fire(EventName.GoSelectMap)
		end
		self.btn_go_mainmenu:addScriptCallBackForControlEvent(func, CCControlEventTouchUpInside)
	end
end

function FailedView:__delete()
end
