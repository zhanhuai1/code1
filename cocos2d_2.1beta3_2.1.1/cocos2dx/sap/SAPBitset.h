#ifndef DreamBitset_h__
#define DreamBitset_h__

#include "ccTypes.h"
#include <vector>

namespace SweepAndPrune
{
	class Bitset
	{
	public:
		Bitset(size_t totalSize = 1024);
		~Bitset();
	
		bool Test(size_t index) const;
		
		void Reset();
		
		void Reserve(size_t capacity);
		
		void Set(size_t index, bool bSet = true);

		size_t GetSlotsNum() const { return m_totalSize;}
		size_t GetDataLen() const;
		const cocos2d::uint8c* GetDataPtr() const;

		void Inverse();

		void SetFrom(size_t start_index, size_t count, bool bSet = true);

		bool FindMultiZero(size_t expect_num, size_t& out_start_index) const;
	private:
		void CalcIndexSavePosAndOffset(size_t index, size_t& outSavePos, size_t& outOffset) const;
	protected:
		std::vector<cocos2d::uint32c> m_dataContainer;
		size_t m_totalSize;

	};
}


#endif // DreamBitset_h__
