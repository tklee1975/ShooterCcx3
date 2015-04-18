#ifdef ENABLE_TDD
//
//  MainLayerTest.h
//
//
#ifndef __TDD_MainLayerTest__
#define __TDD_MainLayerTest__

// Include Header

#include "TDDTest.h"


// Class Declaration 
class MainLayerTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testMainScene(Ref *sender);
	void testCreateScene(Ref *sender);
}; 

#endif

#endif
