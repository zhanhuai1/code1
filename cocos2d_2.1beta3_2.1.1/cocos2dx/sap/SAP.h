#ifndef DreamSweepAndPrune_h__
#define DreamSweepAndPrune_h__

#include "ccTypes.h"
#include "sap/SAPDefinition.h"
#include "sap/SAPPairManager.h"
#include "kazmath/aabb.h"
#include "sap/SAPBitset.h"
#include <vector>
#include <set>


#define SAP_GROUP_SCENE_OBJECT 1
#define SAP_GROUP_CAMERA       2

#define SAP_MAP_CAMARE	1<<2
#define SAP_MAP_TILE	1<<3
#define SAP_MAP_PLAYER	1<<4
#define SAP_MAP_COSTUM	1<<5

namespace SweepAndPrune
{
	// Forward declarations
	class ASAP_EndPoint;
	class ASAP_Box;
	struct InnerAABB;
	struct CreateData;

	class CC_DLL ArraySAP
	{
	public:
		class CC_DLL SAPCommonListner
		{
		public:
			virtual void* OnPairCreate(const void* pObject0, const void* pObject1){return NULL;}
			virtual void OnPairDelete(const void* pObject0, const void* pObject1, void* pPairData){}
		};

		class CC_DLL SAPQueryListner
		{
		public:
			virtual void OnQueryObject(const void* pObject){};
		};
	private:
		struct				BPMinPosInfo		//temp struct for box pruning 
		{
			ValType			minPos;
			cocos2d::uint32c boxIndex;
		};
		typedef std::vector<BPMinPosInfo> BPMinPosInfoList;
	private:
		PairManager mPairManager;

		typedef std::vector<cocos2d::uint32c> IDList;
		typedef std::set<cocos2d::uint32c> IDSet;
		IDSet				mOperatePairSet;

		typedef std::vector<SAPBox> SAPBoxList;
		SAPBoxList			mBoxList;
		IDList				mFreeBoxIdList;

		////boost::object_pool<SAPEndPoint> mEndPointPool;

		////SAPEndPointSortMap  mEndPointMap[3];

		SAPEndPointArray   mEndPointArrays[3];



		// For batch creation
		typedef std::map<cocos2d::uint32c,CreateData> CreateDataMap;
		//typedef std::vector<CreateData> CreateDataList;
		CreateDataMap		mCreateDataMap;



		// For batch removal
		IDList				mRemoveList;

		////SapCreatePairFunc   mPairCreateFunc;
		////SapDeletePairFunc   mPairDeleteFunc;

		SAPCommonListner* m_pCommonListner;
		////boost::dynamic_bitset<> mCreatesDbFlags;
		Bitset mCreatesDbFlags;
	public:
		ArraySAP();
		~ArraySAP();

		cocos2d::uint32c AddObject(void* object, const kmAABB& box, cocos2d::uint16c groupFlag = 0xffff, cocos2d::uint16c collisionFlag = 0xffff);
		bool RemoveObject(cocos2d::uint32c handle);
		bool UpdateObject(cocos2d::uint32c handle, const kmAABB& box);

		cocos2d::uint32c DumpPairs();
	
		void SetCommonListner(SAPCommonListner* pListner);
		////void SetOnPairCreateFunc(SapCreatePairFunc onCreateFunc) {mPairCreateFunc = onCreateFunc;}
		////void SetOnPairDeleteFunc(SapDeletePairFunc onDeleteFunc) {mPairDeleteFunc = onDeleteFunc;}

		cocos2d::uint32c QueryObjectsByAABB(const kmAABB& queryBox, SAPQueryListner* pQueryListner, cocos2d::uint16c collisionFlag = 0xffff);

		PairList QueryObjectAssociatePairs(cocos2d::uint32c handle);
	private:
		inline void AddPair(const void* object0, const void* object1, cocos2d::uint16c id0, cocos2d::uint16c id1)
		{
			Pair* UP = mPairManager.AddPair(id0, id1, object0, object1);

			if(UP->lastCreate==0)
			{
				// Persistent pair
			}
			else
			{
				UP->lastCreate = 0;
				////UP->object0 = object0;
				////UP->object1 = object1;
				UP->SetInArray();
				mOperatePairSet.insert(mPairManager.GetPairKey(UP));
				UP->SetNew();
			}
			UP->ClearRemoved();
		}

		inline void RemovePair(const void* object0, const void* object1, cocos2d::uint16c id0, cocos2d::uint16c id1)
		{
			Pair* UP = mPairManager.FindPair(id0, id1);
			if(UP)
			{
				if(!UP->IsInArray())
				{
					UP->SetInArray();
					mOperatePairSet.insert(mPairManager.GetPairKey(UP));
				}
				UP->SetRemoved();
			}
		}

		inline SAPBox* RequestNewBox()
		{
			if(!mFreeBoxIdList.empty())
			{
				cocos2d::uint32c boxIndex = mFreeBoxIdList[mFreeBoxIdList.size()-1];
				mFreeBoxIdList.pop_back();
				return &mBoxList[boxIndex];
			}
			else
			{
				SAPBox tmpBox;
				////memset(&tmpBox,0,sizeof(tmpBox));
				tmpBox.mBoxIndex = mBoxList.size();
				mBoxList.push_back(tmpBox);
				return &mBoxList[mBoxList.size()-1];
			}
		}

		inline void	FreeBox(SAPBox* pBox)
		{
			mFreeBoxIdList.push_back(pBox->mBoxIndex);
		}


		void BoxPruningBetweenTwoSet(const BPMinPosInfoList& boxCircleSet, const BPMinPosInfoList& boxBeenDetectSet);
		void BoxPruningForBatchCreate(CreateDataMap& batchDataMap);
		void BatchCreate();
			

		void BatchRemove();
			
		void InsertEndPointToArray(const SAPEndPoint& endPoint,cocos2d::uint32c axis);
		void InsertEndPointToArrayBatch(const SAPEndPointArray& insertArray,cocos2d::uint32c axis);

		void UpdateIndexForEndPointArray(cocos2d::uint32c axis, cocos2d::uint32c fromIndex);

		inline cocos2d::uint32c GetPropIndexFromEndPointArray(cocos2d::uint32c axis, ValType val, cocos2d::uint32c currentIndex);

		inline void ShiftOneItemInEndPointArray(cocos2d::uint32c axis,cocos2d::uint32c srcIndex,cocos2d::uint32c dstIndex);
		
		inline void ChangeEndPointValue(SAPBox& srcBox, InnerAABB& updateBox, cocos2d::uint32c axis, bool bMaxEndPoint, ValType newValue);
	
		inline SAPEndPoint* GetBoxEndPoint(SAPBox& srcBox, cocos2d::uint32c axis,bool bMaxEndPoint);
	
		inline ValType GetBoxEndPointValue(SAPBox& srcBox, cocos2d::uint32c axis,bool bMaxEndPoint);

		inline bool Intersect( SAPBox& a,  SAPBox& b, cocos2d::uint32c axis);

		inline bool Intersect2D( SAPBox& a,  SAPBox& b, cocos2d::uint32c axis1, cocos2d::uint32c axis2);
			
		inline bool Intersect1D_Min(InnerAABB& a, SAPBox& b, cocos2d::uint32c axis);

		inline bool IntersectValType(ValType aMin, ValType aMax, ValType bMin, ValType bMax);
	};
}


#endif // DreamSweepAndPrune_h__
