#ifdef ENABLE_TDD
//
//  ShipTest.h
//
//
#ifndef __TDD_ShipTest__
#define __TDD_ShipTest__

// Include Header

#include "TDDTest.h"

class MyShip;
class EnemyShip;
class World;

// Class Declaration 
class ShipTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	void setupTouchListener();
	
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	void onTouchEnded(Touch *touch, Event *event);
	
	void handleShipDir(const Vec2 &worldPos);
	
private:
	void subTest(Ref *sender);
	void testEnemyFire(Ref *sender);
	void addMyShip(Ref *sender);
	void testFire(Ref *sender);
	void testAutoFire(Ref *sender);
	void testExplode(Ref *sender);
	void testEnemyAttack(Ref *sender);
	
private:
	MyShip *mMyShip;
	EnemyShip *mEnemyShip;
	World *mWorld;
	Vec2 mTouchDownPos;
}; 

#endif

#endif
