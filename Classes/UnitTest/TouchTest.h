#ifdef ENABLE_TDD
//
//  TouchTest.h
//
//
#ifndef __TDD_TouchTest__
#define __TDD_TouchTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TouchTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	void setupTouchListener();
	
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	void onTouchEnded(Touch *touch, Event *event);
	
	
private:
	void subTest(Ref *sender);
	void handleMove();
	
private:
	Sprite *mSprite;
	Vec2 mLastPos;
	Vec2 mNewPos;
}; 

#endif

#endif
