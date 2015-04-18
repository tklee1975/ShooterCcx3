#ifdef ENABLE_TDD
//
//  CollisionDetectorTest.h
//
//
#ifndef __TDD_CollisionDetectorTest__
#define __TDD_CollisionDetectorTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class CollisionDetectorTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
}; 

#endif

#endif
