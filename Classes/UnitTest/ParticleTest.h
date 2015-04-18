#ifdef ENABLE_TDD
//
//  ParticleTest.h
//
//
#ifndef __TDD_ParticleTest__
#define __TDD_ParticleTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class ParticleTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
	void testBuildInExplosion(Ref *sender);
}; 

#endif

#endif
