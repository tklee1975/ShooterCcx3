#ifdef ENABLE_TDD
//
//  StringHelperTest.h
//
//
#ifndef __TDD_StringHelperTest__
#define __TDD_StringHelperTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class StringHelperTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void test_strRect(Ref *sender);
}; 

#endif

#endif
