#ifndef CCSquirmAnimNode_h__
#define CCSquirmAnimNode_h__

#include "base_nodes/CCNode.h"
#include "ccTypes.h"

NS_CC_BEGIN
	class CCTexture2D;
	class CC_DLL CCSquirmAnimNode : public CCNode
	{
	public:
		CCSquirmAnimNode();
		~CCSquirmAnimNode();

		static CCSquirmAnimNode* create(CCTexture2D* color_texture, CCTexture2D* mask_texture);

		void setOpacity(unsigned int opacity);
		
		void setColor(const ccColor3B& color);

		void setTextureScale(float f);

		void setMaskScale(float f);

		void setAnimSpeed(float f);



		bool initWithTwoTextures(CCTexture2D* color_texture, CCTexture2D* mask_texture);

		virtual void draw();
		virtual void update(float dt);

	protected:
		void rebuildVertices();

	protected:
		ccV2F_C4B_T2Fx2_Quad	m_sQuad;
		ccBlendFunc        m_sBlendFunc;            /// It's required for CCTextureProtocol inheritance
		CCTexture2D*       m_pobTexture;            /// CCTexture2D object that is used to render the sprite
		CCTexture2D*	   m_maskTexture;		

		bool m_vertices_dirty;
		// opacity
		GLubyte m_opacity;                         /// Goes from 0-255. 0 means fully tranparent and 255 means fully opaque.

		// Color: conforms with CCRGBAProtocol protocol
		ccColor3B m_color;

		float	m_mask_left_edge;
		float	m_mask_horz_scale;
		float	m_mask_anim_speed;

		float	m_texture_horz_scale;
	};

NS_CC_END
#endif