#include "PathFinder.h"

namespace cocos2d
{
	void PathFinder::SetBlock( uint x, uint y, bool block )
	{
		if(x>=m_width || y>=m_height)	return;

		Node* node = GetNodeSafe(x, y);
		if(node->blocked != block)
		{
			node->blocked = block;
			m_dirty = true;
		}
	}

	void PathFinder::Reset()
	{
		m_dirty = true;
		m_dst_num = 0;
		memset(m_destinations, 0, sizeof(m_destinations));

		for(uint y = 0; y < m_height; ++y)
		{
			for(uint x = 0; x < m_width; ++x)
			{
				uint i = y * m_width + x;
				Node& node = m_data[i];
				node.x = x;
				node.y = y;
				node.blocked = false;
			}
		}
	}

	void PathFinder::AddDestination( uint dst_x, uint dst_y )
	{
		if(m_dst_num >= MAX_DST_COUNT-1)	return;
		if(dst_x > m_width-1)	
			dst_x = m_width-1;
		if(dst_y > m_height-1)
			dst_y = m_height-1;

		m_destinations[m_dst_num].x = dst_x;
		m_destinations[m_dst_num].y = dst_y;
		++m_dst_num;
	}

	PathFinder::Node* PathFinder::GetNode( uint x, uint y )
	{
		if(x<m_width && y<m_height)
		{
			return &(m_data[y*m_width+x]);
		}
		return 0;
	}

	const PathFinder::Node* PathFinder::GetNode( uint x, uint y ) const
	{
		if(x<m_width && y<m_height)
		{
			return &(m_data[y*m_width+x]);
		}
		return 0;
	}

	void PathFinder::Prepare()
	{
		uint count = m_width * m_height;
		for(uint i = 0; i<count; ++i)
		{
			Node& node	= m_data[i];
			memset(node.steps, 255, sizeof(node.steps));
			memset(node.childs, 0, sizeof(node.childs));
			memset(node.dirs, 0, sizeof(node.dirs));
			memset(node.checked, 0, sizeof(node.checked));
		}
	}

	void PathFinder::BuildPaths()
	{
		if(!m_dirty) return;
		m_dirty = false;

		Prepare();

		static std::vector<Node*>	s_open_nodes;
		for(uint dst_i = 0; dst_i < m_dst_num; ++dst_i)
		{
			// start from destination, search every open node
			s_open_nodes.clear();
			Point& dst = m_destinations[dst_i];
			Node* dst_node = GetNodeSafe(dst);
			dst_node->steps[dst_i] = 0;
			dst_node->checked[dst_i] = true;
			s_open_nodes.push_back(dst_node);

			for(uint i = 0; i < s_open_nodes.size(); ++i)
			{
				Node* node = s_open_nodes[i];
				uint step = node->steps[dst_i] + 1;

				// left
				Node* parent = GetNode(node->x-1, node->y);
				if(parent && !parent->blocked && !parent->checked[dst_i])
				{
					parent->steps[dst_i] = step;
					parent->childs[dst_i] = node;
					parent->dirs[dst_i] = DIR_RIGHT;
					parent->checked[dst_i] = true;
					s_open_nodes.push_back(parent);
				}

				// up
				parent = GetNode(node->x, node->y - 1);
				if(parent && !parent->blocked && !parent->checked[dst_i])
				{
					parent->steps[dst_i] = step;
					parent->childs[dst_i] = node;
					parent->dirs[dst_i] = DIR_DOWN;
					parent->checked[dst_i] = true;
					s_open_nodes.push_back(parent);
				}

				// right
				parent = GetNode(node->x + 1, node->y);
				if(parent && !parent->blocked && !parent->checked[dst_i])
				{
					parent->steps[dst_i] = step;
					parent->childs[dst_i] = node;
					parent->dirs[dst_i] = DIR_LEFT;
					parent->checked[dst_i] = true;
					s_open_nodes.push_back(parent);
				}

				// down
				parent = GetNode(node->x, node->y + 1);
				if(parent && !parent->blocked && !parent->checked[dst_i])
				{
					parent->steps[dst_i] = step;
					parent->childs[dst_i] = node;
					parent->dirs[dst_i] = DIR_UP;
					parent->checked[dst_i] = true;
					s_open_nodes.push_back(parent);
				}
			}
		}
	}

	bool PathFinder::GetPath(uint src_x, uint src_y, uint dest_id, std::vector<uint>& path )
	{
		if(m_dirty)
		{
			BuildPaths();
		}

		Node* node = GetNode(src_x, src_y);
		if(node==0)	
			return false;

		// find the nearest dest
// 		uint min_step = 0xffffffff;
// 		uint min_path = 0xffffffff;
// 		for(uint i = 0; i < MAX_DST_COUNT; ++i)
// 		{
// 			if(node->steps[i] < min_step)
// 			{
// 				min_step = node->steps[i];
// 				min_path = i;
// 			}
// 		}

		uint min_path = dest_id;
		if(min_path >= MAX_DST_COUNT)
			return false;

		path.clear();
		uint i = min_path;
		Dir cur_dir = node->dirs[i];
		if (cur_dir == DIR_INVALID)
			return false;
		
		path.push_back(node->x);
		path.push_back(node->y);
		while(cur_dir != DIR_INVALID)
		{
			node = node->childs[i];
			
			Dir old_dir = cur_dir;
			cur_dir = node->dirs[i];
			if(old_dir != cur_dir)
			{
				path.push_back(node->x);
				path.push_back(node->y);
			}
		}
		return true;
	}

}