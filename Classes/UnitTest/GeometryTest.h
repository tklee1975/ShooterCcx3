#ifdef ENABLE_TDD
//
//  GeometryTest.h
//
//
#ifndef __TDD_GeometryTest__
#define __TDD_GeometryTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class GeometryTest : public TDDTest
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
