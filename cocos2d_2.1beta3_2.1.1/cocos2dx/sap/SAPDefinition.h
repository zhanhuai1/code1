#ifndef DreamSAPDefinition_h__
#define DreamSAPDefinition_h__

#include "ccTypes.h"
#include "kazmath/vec3.h"
#include "kazmath/aabb.h"
#include <vector>


namespace SweepAndPrune
{
	# define USE_INTEGERS
	////# define USE_SHORT_INDEX

#		ifdef USE_INTEGERS
		typedef cocos2d::uint32c	ValType;
#		else
		typedef float	ValType;
#		endif

#		ifdef USE_SHORT_INDEX
		typedef cocos2d::uint16c IndexType;
		typedef cocos2d::uint32c KeyType;
#			define	INVALID_INDEX	0xffff
#		else
		typedef cocos2d::uint32c IndexType;
		typedef cocos2d::uint64c KeyType;
#			define	INVALID_INDEX	0xffffffff
#		endif

	enum AxisIndex
	{
		X_					= 0,
		Y_					= 1,
		Z_					= 2,
		W_					= 3,

		AXIS_FORCE_DWORD	= 0x7fffffff
	};

	enum AxisOrder
	{
		AXES_XYZ			= (X_)|(Y_<<2)|(Z_<<4),
		AXES_XZY			= (X_)|(Z_<<2)|(Y_<<4),
		AXES_YXZ			= (Y_)|(X_<<2)|(Z_<<4),
		AXES_YZX			= (Y_)|(Z_<<2)|(X_<<4),
		AXES_ZXY			= (Z_)|(X_<<2)|(Y_<<4),
		AXES_ZYX			= (Z_)|(Y_<<2)|(X_<<4),

		AXES_FORCE_DWORD	= 0x7fffffff
	};

	class Axes 
	{
	public:

		Axes(AxisOrder order)
		{
			mAxis0 = (order   ) & 3;
			mAxis1 = (order>>2) & 3;
			mAxis2 = (order>>4) & 3;
		}
		~Axes()		{}

		cocos2d::uint32c mAxis0;
		cocos2d::uint32c mAxis1;
		cocos2d::uint32c mAxis2;
	};



	struct InnerAABB
	{
		ValType mMinX;
		ValType mMinY;
		ValType mMinZ;
		ValType mMaxX;
		ValType mMaxY;
		ValType mMaxZ;

		inline ValType	GetMin(cocos2d::uint32c i)	const	{	return (&mMinX)[i];	}
		inline ValType	GetMax(cocos2d::uint32c i)	const	{	return (&mMaxX)[i];	}
	};

	struct CreateData
	{
		cocos2d::uint32c mHandle;
		kmAABB mBox;
	};

	struct SAPEndPoint
	{
	public:
		SAPEndPoint()
			:flagMax(0)
			,ownerIndex(0)
			,mValue(0)
		{

		}

		~SAPEndPoint()
		{

		}

		inline bool operator < ( const SAPEndPoint& rhs ) const
		{
			return (mValue < rhs.mValue);
		}

		ValType	mValue;		// Min or Max value
		cocos2d::uint32c  ownerIndex:31;
		////UINT32  flagSentinel:1;
		cocos2d::uint32c  flagMax:1;
	};

	typedef std::vector<SAPEndPoint> SAPEndPointArray;
	typedef SAPEndPointArray::iterator SAPEndPointArrayIter;

	class SAPBox
	{
	public:
		SAPBox()
			:mCollisionFlag(0xffff),
			mGroupFlag(0xffff)
		{
			for (int i=0;i<3;i++)
			{
				mMin[i] = INVALID_INDEX;
				mMax[i] = INVALID_INDEX;
			}
		}
		~SAPBox()	
		{

		}

		IndexType mMin[3];
		IndexType mMax[3];

		cocos2d::uint16c mGroupFlag;
		cocos2d::uint16c mCollisionFlag;

		void*     mObject;
		cocos2d::uint32c    mBoxIndex;

		inline ValType GetMaxValue(cocos2d::uint32c i, const SAPEndPoint* baseAddr)	const
		{
			return baseAddr[mMax[i]].mValue;
		}

		inline ValType GetMinValue(cocos2d::uint32c i, const SAPEndPoint* baseAddr) const
		{
			return baseAddr[mMin[i]].mValue;
		}

		inline bool CanCollideWith(const SAPBox& otherBox)
		{
			return ((otherBox.mGroupFlag&mCollisionFlag) && (otherBox.mCollisionFlag&mGroupFlag));
		}
	};

	//! Integer representation of a floating-point value.
#		define IR(x)					((cocos2d::uint32c&)(x))

	//! Floating-point representation of an integer value.
#		define FR(x)					((float&)(x))
	
	inline cocos2d::uint32c EncodeFloat(const float val)
	{
		// We may need to check on -0 and 0
		// But it should make no practical difference.
		cocos2d::uint32c ir = IR(val);

		if(ir & 0x80000000) //negative?
			ir = ~ir;//reverse sequence of negative numbers
		else
			ir |= 0x80000000; // flip sign

		return ir;
	}

	inline float DecodeFloat(cocos2d::uint32c ir)
	{
		cocos2d::uint32c rv;

		if(ir & 0x80000000) //positive?
			rv = ir & ~0x80000000; //flip sign
		else
			rv = ~ir; //undo reversal

		return FR(rv);
	}

	// From Jon Watte IIRC
	inline void Prefetch(void const* ptr)
	{ 
		(void)*(char const volatile *)ptr;	
	}
}

#endif // DreamSAPDefinition_h__