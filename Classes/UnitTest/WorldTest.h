#ifdef ENABLE_TDD
//
//  WorldTest.h
//
//
#ifndef __TDD_WorldTest__
#define __TDD_WorldTest__

// Include Header

#include "TDDTest.h"
#include "World.h"

// Class Declaration 
class WorldTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);

	// Touch handling
	void setupTouchListener();
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	void onTouchEnded(Touch *touch, Event *event);
	void handleShipDir(const Vec2 &worldPos);
	
	// Callback
	void handleCallback(Ref *ref, World::WorldEvent event);
	
private:
	void addWorld(Ref *sender);
	void addBullet(Ref *sender);
	void testLevel(Ref *sender);
	void addShip(Ref *sender);
	void showInfo(Ref *sender);
	void testExplosion(Ref *sender);
	void testSpawn(Ref *sender);
	void testRemoveEnemies(Ref *sender);
	
private:
	World *mWorld;
	int mLevel;
};

#endif

#endif
