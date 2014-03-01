#ifndef __MapTileCalculator_h__
#define __MapTileCalculator_h__

#include <assert.h>
#include <vector>

class MapTileCalculator
{
	struct TileInfo
	{
		bool is_filled;			// 是否填充内容
		unsigned int res_id;
	};
public:
	MapTileCalculator(unsigned int w, unsigned int h)
		: m_map_width(w)
		, m_map_height(h)
	{
		unsigned int c = w * h;
		TileInfo init_info = {false, 0xffffffff};
		m_tile_info_array.reserve(c);
		m_tile_info_array.resize(c, init_info);
	}

	bool IsFilled(unsigned int x, unsigned int y)
	{
		TileInfo* info = GetTileInfo(x, y);
		assert(info);
		return info->is_filled;
	}
	void FillTile(unsigned int x, unsigned int y)
	{
		TileInfo* info = GetTileInfo(x, y);
		assert(info);
		info->is_filled = true;
		
		// 刷新相邻3x3格的资源
		for(unsigned int j = y-1; j <= y+1; ++j)
		{
			for(unsigned int i = x-1; i <= x+1; ++i)
			{
				UpdateResId(i, j);
			}
		}
	}

	TileInfo* GetTileInfo(unsigned int x, unsigned int y)
	{
		if(x<m_map_width && y<m_map_height)
		{
			unsigned int i = y * m_map_width + x;
			TileInfo* p = &(m_tile_info_array[i]);
			return p;
		}
		return 0;
	}

protected:
	inline bool CheckFilled1(const TileInfo* info) const { return (info && info->is_filled);}
	inline bool CheckFilled3(const TileInfo* left, const TileInfo* top, const TileInfo* lt) const { return (left && top && lt && left->is_filled && top->is_filled && lt->is_filled);}

	void UpdateResId(unsigned int x, unsigned int y)
	{
		TileInfo* info = GetTileInfo(x, y);
		if(info == 0)
			return;

		unsigned int res_id = 0;
		if(info->is_filled)
		{			
			TileInfo* left = GetTileInfo(x-1, y);	// 1000
			TileInfo* top = GetTileInfo(x, y-1);	// 0100
			TileInfo* right = GetTileInfo(x+1, y);	// 0010
			TileInfo* bot = GetTileInfo(x, y+1);	// 0001

			if(CheckFilled1(left))
			{
				res_id |= 8;
			}
			
			if(CheckFilled1(top))
			{
				res_id |= 4;
			}
			
			if(CheckFilled1(right))
			{
				res_id |= 2;
			}
			
			if(CheckFilled1(bot))
			{
				res_id |= 1;
			}
		}
		else
		{
			res_id = 1 << 4;

			TileInfo* left = GetTileInfo(x-1, y);	// 1000
			TileInfo* top = GetTileInfo(x, y-1);	// 0100
			TileInfo* right = GetTileInfo(x+1, y);	// 0010
			TileInfo* bot = GetTileInfo(x, y+1);	// 0001
			TileInfo* lt = GetTileInfo(x-1, y-1);
			TileInfo* rt = GetTileInfo(x+1, y-1);
			TileInfo* rb = GetTileInfo(x+1, y+1);
			TileInfo* lb = GetTileInfo(x-1, y+1);

			if(CheckFilled3(left, top, lt))
			{
				res_id |= 8;
			}
			
			if(CheckFilled3(right, top, rt))
			{
				res_id |= 4;
			}

			if(CheckFilled3(right, bot, rb))
			{
				res_id |= 2;
			}

			if(CheckFilled3(left, bot, lb))
			{
				res_id |= 1;
			}
		}
		info->res_id = res_id;
	}

protected:
	typedef std::vector<TileInfo>	TileInfoArray;
	TileInfoArray	m_tile_info_array;
	unsigned int	m_map_width;
	unsigned int	m_map_height;
};

#endif