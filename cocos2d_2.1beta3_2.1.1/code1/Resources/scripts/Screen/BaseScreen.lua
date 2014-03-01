BaseScreen = BaseScreen or BaseClass()

function BaseScreen:__init()
	self.texture_name_list = {
		"media/bg1.jpg",
		"media/squirm_mask2.jpg",
	}
	self.bg_name = "media/bg1.jpg"
	self.bg_mask_mask 	= "media/squirm_mask2.jpg"
end

function BaseScreen:Enter()
	self:PreloadTextures()

	--创建背景
	if self.squirm_bg == nil then
		local squirm_color_tex = TextureLoader.Instance:GetTexture(self.bg_name)
		local squirm_mask_tex = TextureLoader.Instance:GetTexture(self.bg_mask_mask)
		if squirm_color_tex and squirm_mask_tex then
			self.squirm_bg = CCSquirmAnimNode:create(squirm_color_tex, squirm_mask_tex)
			self.squirm_bg:setContentSize(CCSize(g_real_visible_sz.width, g_real_visible_sz.height+30))
			self.squirm_bg:setPosition(ccp(-g_real_visible_sz.width/2, -g_real_visible_sz.height/2))
			-- self.squirm_bg:setMaskScale(2)
			self.squirm_bg:setTextureScale(g_real_visible_sz.width / 1024)
			self.squirm_bg:setAnimSpeed(0.15)
			-- self.squirm_bg:setOpacity(255)
			g_game_scene:addChild(self.squirm_bg, Config.ZOrder.Squirm)
		end
	end
end

function BaseScreen:Exit()
	self:UnloadTextures()

	if self.squirm_bg then
		self.squirm_bg:removeFromParentAndCleanup(true)
		self.squirm_bg = nil
	end
end

function BaseScreen:Update(delta_time, running_time)
end

function BaseScreen:PreloadTextures()
	-- print("= = =PreloadTextures")
	-- for _, tex_name in pairs(self.texture_name_list) do
	-- 	print("PreloadTextures:", tex_name)
	-- 	local tex = CCTextureCache:sharedTextureCache():addImage(tex_name)
	-- end
end

function BaseScreen:UnloadTextures()
	-- print("= = =UnloadTextures")
	-- for name, tex in pairs(self.texture_list) do
	-- 	print("UnloadTextures:", name)
	-- 	CCTextureCache:sharedTextureCache():removeTexture(tex)
	-- end
	-- self.texture_list = {}
end