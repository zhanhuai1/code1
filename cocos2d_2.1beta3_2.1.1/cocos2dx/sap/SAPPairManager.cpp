#include "SAP/SAPPairManager.h"


namespace SweepAndPrune
{
	PairManager::PairManager(cocos2d::uint32c capacity)
	{

	}

	PairManager::~PairManager()
	{

	}

	Pair* PairManager::AddPair( cocos2d::uint16c id0, cocos2d::uint16c id1, const void* object0, const void* object1 )
	{
		AjustRightPairsOrder(id0,id1,object0,object1);
		cocos2d::uint32c tmpKey = GetKey(id0,id1);
		Pair* pPair = FindPair(id0,id1);
		if(pPair)
		{
		 	return pPair;
		}
		 			
		pPair = new Pair();
		pPair->id0 = id0;
		pPair->id1 = id1;
		pPair->object0 = object0;
		pPair->object1 = object1;
		pPair->lastCreate = 1;
		mPairHashMap.insert(std::make_pair(tmpKey,pPair));
		 			
		return pPair;
	}


	bool PairManager::RemovePair( cocos2d::uint16c id0, cocos2d::uint16c id1 )
	{
		AjustRightPairsOrder(id0,id1);
		cocos2d::uint32c tmpKey = GetKey(id0,id1);

		return RemovePair(tmpKey);
	}

	bool PairManager::RemovePair( cocos2d::uint32c keyVal )
	{
		PairHashMap::iterator iPair = mPairHashMap.find(keyVal);
		if(iPair != mPairHashMap.end())
		{
			delete iPair->second;
			iPair->second = NULL;
			mPairHashMap.erase(iPair);			
			return true;
		}
		else
		{
			return false;
		}
	}

	Pair* PairManager::FindPair( cocos2d::uint16c id0, cocos2d::uint16c id1 )
	{
		AjustRightPairsOrder(id0,id1);
		cocos2d::uint32c tmpVal = GetKey(id0,id1);

		return FindPair(tmpVal);
	}

	Pair* PairManager::FindPair( cocos2d::uint32c keyVal )
	{
		PairHashMap::iterator iPair = mPairHashMap.find(keyVal);
		if(iPair!=mPairHashMap.end())
		{
			return iPair->second;
		}
		else
		{
			return NULL;
		}
	}

	void PairManager::AjustRightPairsOrder( cocos2d::uint16c& id0, cocos2d::uint16c& id1, const void*& object0,const void*& object1 ) const
	{
		if(id0>id1)
		{
			std::swap(id0,id1);
			std::swap(object0,object1);
		}
	}

	void PairManager::AjustRightPairsOrder( cocos2d::uint16c& id0, cocos2d::uint16c& id1 ) const
	{
		if(id0>id1)
		{
			std::swap(id0,id1);
		}
	}

	cocos2d::uint32c PairManager::GetKey( cocos2d::uint16c id0,cocos2d::uint16c id1 ) const
	{
		cocos2d::uint32c tmpVal = id0;
		tmpVal = (tmpVal<<16)|id1;
		return tmpVal;
	}

	bool PairManager::RemovePairs( const Bitset& dbRemoveObjects )
	{
		for (PairHashMap::iterator iPair = mPairHashMap.begin(); iPair != mPairHashMap.end();)
		{
			Pair* pPair = iPair->second;
			if(dbRemoveObjects.Test(pPair->id0) || dbRemoveObjects.Test(pPair->id1))
			{
				mPairHashMap.erase(iPair++);
			}
			else
			{
				iPair++;
			}
		}
		return true;
	}

	PairList& PairManager::FindAssociatePairs( const Bitset& db_test_object )
	{
		static PairList pairList;
		pairList.clear();
		for (PairHashMap::iterator iPair = mPairHashMap.begin(); iPair != mPairHashMap.end();iPair++)
		{
			Pair* pPair = iPair->second;
			if(db_test_object.Test(pPair->id0) || db_test_object.Test(pPair->id1))
			{
				pairList.push_back(pPair);
			}
		}
		return pairList;
	}
}

