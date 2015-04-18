#ifdef ENABLE_TDD
//
//  BulletTest.h
//
//
#ifndef __TDD_BulletTest__
#define __TDD_BulletTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class BulletTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	

private:
	void testCreate(Ref *sender);
	void testMove(Ref *sender);
	void testEnemyBullet(Ref *sender);
}; 

#endif

#endif
