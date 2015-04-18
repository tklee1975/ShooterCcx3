#ifdef ENABLE_TDD
//
//  ActionTest.h
//
//
#ifndef __TDD_ActionTest__
#define __TDD_ActionTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class ActionTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
	void testFunc(Ref *sender);		// Fade In and Out
}; 

#endif

#endif
