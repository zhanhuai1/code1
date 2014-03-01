
AssetsHelper = AssetsHelper or {}

function AssetsHelper.CreateUIScaleSprite(frame_name)
	local frame_info = g_frames_config[frame_name]
	if frame_info then
		local sprite = CCScale9Sprite:create(frame_info.texture, frame_info.rect)
		sprite:setContentSize(frame_info.rect.size)
		return sprite
	end
	return nil
end

function AssetsHelper.CreateButton(frame_name)
	local normal_sprite = AssetsHelper.CreateUIScaleSprite(frame_name)
	local btn = CCControlButton:create(normal_sprite)
	btn:setContentSize(g_frames_config[frame_name].rect.size)
	btn:setEnabled(true)
	btn:setAdjustBackgroundImage(false)
	btn:setTouchEnabled(true)
	return btn
end

function AssetsHelper.CreateFrameSprite(frame_name)
	local frame_info = g_frames_config[frame_name]
	if frame_info then
		local sprite = CCSprite:create(frame_info.texture, frame_info.rect)
		return sprite
	end
	return nil
end

function AssetsHelper.CreateAnimateAction(anim_name)
	local anim_frames = g_animations_config[anim_name]
	if anim_frames == nil then
		return nil
	end

	local frames_array = CCArray:create()
	for i=1, #anim_frames do
		local f_def = anim_frames[i]
		local tex = CCTextureCache:sharedTextureCache():addImage(f_def.texture)
		local rect = CCRectMake(f_def.x, f_def.y, f_def.w, f_def.h)
		local frame = CCSpriteFrame:createWithTexture(tex, rect)
		if f_def.anchor_x ~= nil then
			frame:setOffset(ccp(-f_def.anchor_x + math.floor(f_def.w / 2), -f_def.anchor_y + math.floor(f_def.h / 2)))
		end
		frames_array:addObject(frame)
	end

	local animation = CCAnimation:createWithSpriteFrames(frames_array, 0.1)
	local animate_action = CCAnimate:create(animation)

	return animate_action
end


function AssetsHelper.CreateLabelTTF(font_name)
	local cfg = g_fonts_config[font_name]
	if cfg == nil then
		cfg = g_fonts_config["Common14"]
	end
	local label = CCLabelTTF:create("", cfg.name, cfg.size)
	return label
end