#ifdef ENABLE_TDD
//
//  CocosStudioTest.h
//
//
#ifndef __TDD_CocosStudioTest__
#define __TDD_CocosStudioTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class CocosStudioTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testMainScene(Ref *sender);
	void testMainGameLayer(Ref *sender);
	void testGameOverDialog(Ref *sender);
}; 

#endif

#endif
