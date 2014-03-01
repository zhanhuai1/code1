#include "CCSquirmAnimNode.h"
#include "shaders/CCShaderCache.h"
#include "ccMacros.h"
#include "textures/CCTexture2D.h"
#include "CCDirector.h"
#include "CCScheduler.h"
#include "shaders/CCGLProgram.h"


NS_CC_BEGIN


CCSquirmAnimNode::CCSquirmAnimNode()
: m_pobTexture(0)
, m_maskTexture(0)
, m_vertices_dirty(false)
, m_mask_left_edge(0.0f)
, m_texture_horz_scale(1.0f)
, m_mask_horz_scale(1.0f)
, m_mask_anim_speed(1.0f)
, m_opacity(255)
{
	setShaderProgram(CCShaderCache::sharedShaderCache()->programForKey(kCCShader_SquirmAnim));

	m_sBlendFunc.src = GL_SRC_ALPHA;
	m_sBlendFunc.dst = GL_ONE_MINUS_SRC_ALPHA;
	m_color = ccc3(255, 255, 255);
	
	CCDirector::sharedDirector()->getScheduler()->scheduleUpdateForTarget(this, 0, false);
}

CCSquirmAnimNode::~CCSquirmAnimNode()
{
	CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
	CC_SAFE_RELEASE(m_pobTexture);
	CC_SAFE_RELEASE(m_maskTexture);
}

void CCSquirmAnimNode::draw()
{
	CCAssert(m_pobTexture != 0 && m_maskTexture != 0, "CCSquirmAnimNode::draw(), textures mustn't be null!");
	CC_PROFILER_START_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");

	// 如果顶点数据需要刷新，就刷新之
	if(m_vertices_dirty)
	{
		rebuildVertices();
	}

	CC_NODE_DRAW_SETUP();

	ccGLBlendFunc( m_sBlendFunc.src, m_sBlendFunc.dst );

	ccGLBindTexture2DN(0, m_pobTexture->getName());
	ccGLBindTexture2DN(1, m_maskTexture->getName());

	//
	// Attributes
	//

	ccGLEnableVertexAttribs( kCCVertexAttribFlag_PosColorTexTex );

#define kQuadSize sizeof(m_sQuad.bl)
	long offset = (long)&m_sQuad;

	// vertex
	int diff = offsetof( ccV3F_C4B_T2Fx2, vertices);
	glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, kQuadSize, (void*) (offset + diff));

	// texCoods
	diff = offsetof( ccV3F_C4B_T2Fx2, texCoords);
	glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, kQuadSize, (void*)(offset + diff));

	diff = offsetof(ccV3F_C4B_T2Fx2, texCoords1);
	glVertexAttribPointer(kCCVertexAttrib_TexCoords1, 2, GL_FLOAT, GL_FALSE, kQuadSize, (void*)(offset + diff));

	// color
	diff = offsetof( ccV3F_C4B_T2Fx2, colors);
	glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE, kQuadSize, (void*)(offset + diff));


	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	CHECK_GL_ERROR_DEBUG();


#if CC_SPRITE_DEBUG_DRAW == 1
	// draw bounding box
	CCPoint vertices[4]={
		ccp(m_sQuad.tl.vertices.x,m_sQuad.tl.vertices.y),
		ccp(m_sQuad.bl.vertices.x,m_sQuad.bl.vertices.y),
		ccp(m_sQuad.br.vertices.x,m_sQuad.br.vertices.y),
		ccp(m_sQuad.tr.vertices.x,m_sQuad.tr.vertices.y),
	};
	ccDrawPoly(vertices, 4, true);
#elif CC_SPRITE_DEBUG_DRAW == 2
	// draw texture box
	CCSize s = this->getTextureRect().size;
	CCPoint offsetPix = this->getOffsetPosition();
	CCPoint vertices[4] = {
		ccp(offsetPix.x,offsetPix.y), ccp(offsetPix.x+s.width,offsetPix.y),
		ccp(offsetPix.x+s.width,offsetPix.y+s.height), ccp(offsetPix.x,offsetPix.y+s.height)
	};
	ccDrawPoly(vertices, 4, true);
#endif // CC_SPRITE_DEBUG_DRAW

	CC_INCREMENT_GL_DRAWS(1);

	CC_PROFILER_STOP_CATEGORY(kCCProfilerCategorySprite, "CCSquirmAnimNode - draw");
}

CCSquirmAnimNode* CCSquirmAnimNode::create( CCTexture2D* color_texture, CCTexture2D* mask_texture )
{
	CCSquirmAnimNode* new_node = new CCSquirmAnimNode();
	if(new_node->initWithTwoTextures(color_texture, mask_texture))
	{
		new_node->autorelease();
		return new_node;
	}
	delete new_node;
	return 0;
}

bool CCSquirmAnimNode::initWithTwoTextures( CCTexture2D* color_texture, CCTexture2D* mask_texture )
{
	m_pobTexture = color_texture;
	m_maskTexture = mask_texture;
	m_pobTexture->retain();
	m_maskTexture->retain();

	// mask_texture的寻址模式
	ccTexParams tex_param = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_CLAMP_TO_EDGE};
	m_pobTexture->setTexParameters(&tex_param);
	m_maskTexture->setTexParameters(&tex_param);

	m_vertices_dirty = true;

	return true;
}

void CCSquirmAnimNode::rebuildVertices()
{
	if(m_vertices_dirty)
	{
		memset(&m_sQuad, 0, sizeof(m_sQuad));
		int w = m_obContentSize.width;
		int h = m_obContentSize.height;
		int texture_w = m_pobTexture->getPixelsWide();
		int texture_h = m_pobTexture->getPixelsHigh();
		float max_u0 = (float)w / (float)texture_w / m_texture_horz_scale;
		float max_u1 = max_u0 / m_mask_horz_scale;

		ccColor4B clr = ccc4(m_color.r, m_color.g, m_color.b, m_opacity);

		m_sQuad.bl.vertices = vertex3(0.0f, 0.0f, 0.0f);
		m_sQuad.bl.colors = clr;
		m_sQuad.bl.texCoords = tex2(0.0f, 1.0f);
		m_sQuad.bl.texCoords1 = tex2(m_mask_left_edge, 1.0f);

		m_sQuad.br.vertices = vertex3(m_obContentSize.width, 0.0f, 0.0f);
		m_sQuad.br.colors = clr;
		m_sQuad.br.texCoords = tex2(max_u0, 1.0f);
		m_sQuad.br.texCoords1 = tex2(m_mask_left_edge + max_u1, 1.0f);

		m_sQuad.tl.vertices = vertex3(0.0f, m_obContentSize.height, 0.0f);
		m_sQuad.tl.colors = clr;
		m_sQuad.tl.texCoords = tex2(0.0f, 0.0f);
		m_sQuad.tl.texCoords1 = tex2(m_mask_left_edge, 0.0f);

		m_sQuad.tr.vertices = vertex3(m_obContentSize.width, m_obContentSize.height, 0.0f);
		m_sQuad.tr.colors = clr;
		m_sQuad.tr.texCoords = tex2(max_u0, 0.0f);
		m_sQuad.tr.texCoords1 = tex2(m_mask_left_edge + max_u1, 0.0f);

		m_vertices_dirty = false;
	}
}

void CCSquirmAnimNode::update( float dt )
{
	// 移动uv
	m_mask_left_edge += dt * m_mask_anim_speed;
	if(m_mask_left_edge > 100.0f)
	{
		m_mask_left_edge -= 100.0f;
	}

	m_vertices_dirty = true;
}

void CCSquirmAnimNode::setOpacity( unsigned int opacity )
{
	if(opacity != m_opacity)
	{
		m_opacity = opacity;
		m_vertices_dirty = true;
	}
}

void CCSquirmAnimNode::setColor( const ccColor3B& color )
{
	if(!ccc3BEqual(m_color, color))
	{
		m_color = color;
		m_vertices_dirty = true;
	}
}

void CCSquirmAnimNode::setTextureScale( float f )
{
	if(!ccFloatEqual(m_texture_horz_scale, f))
	{
		m_texture_horz_scale = f;
		m_vertices_dirty = true;
	}
}

void CCSquirmAnimNode::setMaskScale( float f )
{
	if(!ccFloatEqual(m_mask_horz_scale , f))
	{
		m_mask_horz_scale = f;
		m_vertices_dirty = true;
	}
}

void CCSquirmAnimNode::setAnimSpeed( float f )
{
	m_mask_anim_speed = f;
}

NS_CC_END