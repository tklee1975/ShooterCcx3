#ifdef ENABLE_TDD
//
//  CallbackTest.h
//
//
#ifndef __TDD_CallbackTest__
#define __TDD_CallbackTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class CallbackTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
	void handleCallback(Ref *sender, int value);
	
private:
	void testStdFunc(Ref *sender);
	void testLayerCallback(Ref *sender);
	void testStdBind(Ref *sender);
	void testCallBack2(Ref *sender);
}; 

#endif

#endif
