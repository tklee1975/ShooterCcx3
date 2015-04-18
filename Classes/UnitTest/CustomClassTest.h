#ifdef ENABLE_TDD
//
//  CustomClassTest.h
//
//
#ifndef __TDD_CustomClassTest__
#define __TDD_CustomClassTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class CustomClassTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testLayerColor(Ref *sender);
}; 

#endif

#endif
