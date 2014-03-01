#ifndef DreamSAPPairManager_h__
#define DreamSAPPairManager_h__

////#include "DreamPredependencies.h"
////#include "boost/pool/object_pool.hpp"
////#include "boost/dynamic_bitset.hpp"
////#include "boost/unordered_map.hpp"

#include "ccTypes.h"
#include "sap/sapBitset.h"

#include <map>


namespace SweepAndPrune
{
#pragma pack(push)  /* push current alignment to stack */
#pragma pack(1)     /* set alignment to 1 byte boundary */
	struct CC_DLL Pair
	{
		cocos2d::uint16c id0;
		cocos2d::uint16c id1;
		const void*	object0;
		const void*	object1;
		//#ifdef PAIR_USER_DATA
		void*		userData;
		//#endif

		cocos2d::uint8c flagRemoved:1;
		cocos2d::uint8c flagInArray:1;
		cocos2d::uint8c flagNew:1;
		cocos2d::uint8c lastCreate:1;
		cocos2d::uint8c flagReserved:4;

		const void*	GetObject0() const	{ return object0;}
		const void*	GetObject1() const	{ return object1;}
		bool		IsInArray()	 const	{ return flagInArray;}
		bool		IsRemoved()	 const	{ return flagRemoved;}
		bool		IsNew()		 const	{ return flagNew;}
	private:
		void		SetInArray()				{ flagInArray = 1;}
		void		SetRemoved()				{ flagRemoved = 1;}
		void		SetNew()					{ flagNew = 1;}
		void		ClearInArray()				{ flagInArray = 0;	}
		void		ClearRemoved()				{ flagRemoved = 0;	}
		void		ClearNew()					{ flagNew = 0;	}
		friend class ArraySAP;
	};
#pragma pack(pop)

	typedef std::vector<Pair*> PairList;

	class CC_DLL PairManager
	{
	public:
		PairManager(cocos2d::uint32c capacity = 1024);
		~PairManager();

		Pair*	AddPair(cocos2d::uint16c id0, cocos2d::uint16c id1, const void* object0, const void* object1);
		bool	RemovePair	(cocos2d::uint16c id0, cocos2d::uint16c id1);
		bool	RemovePair(cocos2d::uint32c keyVal);
		Pair*	FindPair(cocos2d::uint16c id0, cocos2d::uint16c id1);
		Pair*	FindPair(cocos2d::uint32c keyVal);

		inline cocos2d::uint32c GetPairKey(Pair* pPair)
		{
			return GetKey(pPair->id0, pPair->id1);
		}
			
		bool RemovePairs(const Bitset& dbRemoveObjects);

		PairList& FindAssociatePairs(const Bitset& dbRemoveObjects);

		size_t GetPairsSize() const {return mPairHashMap.size();}
	private: 
		void AjustRightPairsOrder(cocos2d::uint16c& id0, cocos2d::uint16c& id1, const void*& object0,const void*& object1) const;
		void AjustRightPairsOrder(cocos2d::uint16c& id0, cocos2d::uint16c& id1) const;
		cocos2d::uint32c GetKey(cocos2d::uint16c id0,cocos2d::uint16c id1) const;
	private:
		typedef std::map<cocos2d::uint32c,Pair*> PairHashMap;
		PairHashMap mPairHashMap;
	};
}

#endif // DreamSAPPairManager_h__