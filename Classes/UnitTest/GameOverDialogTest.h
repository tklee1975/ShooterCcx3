#ifdef ENABLE_TDD
//
//  GameOverDialogTest.h
//
//
#ifndef __TDD_GameOverDialogTest__
#define __TDD_GameOverDialogTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class GameOverDialogTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
	void testOKCancel(Ref *sender);
	void onOK(Ref *sender);
	void onCancel(Ref *sender);
	
}; 

#endif

#endif
