#ifdef ENABLE_TDD
//
//  MainGameLayerTest.h
//
//
#ifndef __TDD_MainGameLayerTest__
#define __TDD_MainGameLayerTest__

// Include Header

#include "TDDTest.h"

class MainGameLayer;

// Class Declaration 
class MainGameLayerTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
	void changeLevel(Ref *sender);
	
private:
	MainGameLayer *mMainLayer;
	int mLevel;
}; 

#endif

#endif
