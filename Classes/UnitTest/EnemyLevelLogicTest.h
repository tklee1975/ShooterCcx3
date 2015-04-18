#ifdef ENABLE_TDD
//
//  EnemyLevelLogicTest.h
//
//
#ifndef __TDD_EnemyLevelLogicTest__
#define __TDD_EnemyLevelLogicTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class EnemyLevelLogicTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testCreateEnemyLv1(Ref *sender);
	void testCreateEnemyLv3(Ref *sender);
}; 

#endif

#endif
