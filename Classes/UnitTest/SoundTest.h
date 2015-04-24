#ifdef ENABLE_TDD
//
//  SoundTest.h
//
//
#ifndef __TDD_SoundTest__
#define __TDD_SoundTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class SoundTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
}; 

#endif

#endif
