#ifndef __PATHFINDER_H__
#define __PATHFINDER_H__

#include <vector>

#include <iostream>
#include "cocoa\CCObject.h"
using namespace std;

namespace cocos2d
{
	typedef unsigned int uint;
	
	
	// support at most 4 destinations
#define MAX_DST_COUNT 4


	class CC_DLL PathFinder : public CCObject
	{
		// location of next node
		enum Dir	
		{
			DIR_INVALID = 0,
			DIR_LEFT	= 1,
			DIR_UP		= 2,
			DIR_RIGHT	= 3,
			DIR_DOWN	= 4,

		};
		struct Point
		{
			uint x;
			uint y;
		};
		struct Node
		{
			// static data
			uint x;
			uint y;
			bool blocked;

			// dynamic data
			bool	checked[MAX_DST_COUNT];
			uint	steps[MAX_DST_COUNT];
			Node*	childs[MAX_DST_COUNT];
			Dir		dirs[MAX_DST_COUNT];
		};
	public:
		PathFinder(uint w, uint h)
			: m_width(w)
			, m_height(h)
			, m_dirty(true)
		{
			m_data = (Node*)malloc(w*h*sizeof(Node));
			Reset();
		}
		~PathFinder()
		{
			free(m_data);
			m_data = 0;
		}

		void Reset();

		void SetBlock(uint x, uint y, bool block);

		// Set the origin point and the destination point
		void AddDestination(uint dst_x, uint dst_y);

		// Get the path to destination
		// if there is no path to any dest, return false
		bool GetPath(uint src_x, uint src_y, uint dest_id, std::vector<uint>& path);

	protected:
		inline Node* GetNodeSafe(uint x, uint y)	{ return m_data + y * m_width + x;	}
		inline Node* GetNodeSafe(const Point& pt)	{ return m_data + pt.y * m_width + pt.x;}

		Node* GetNode(uint x, uint y);
		const Node* GetNode(uint x, uint y) const;

		void Prepare();
		void BuildPaths();
	protected:
		Node*	m_data;
		uint	m_width;
		uint	m_height;

		bool	m_dirty;
		uint	m_dst_num;
		Point	m_destinations[MAX_DST_COUNT];
	};


}

#endif