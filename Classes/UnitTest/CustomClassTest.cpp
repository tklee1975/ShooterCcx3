#ifdef ENABLE_TDD
//
//  CustomClassTest.m
//	TDD Framework 
//
//
#include "CustomClassTest.h"
#include "TDDHelper.h"
#include "MyLayerColor.h"

void CustomClassTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void CustomClassTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void CustomClassTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(CustomClassTest::testLayerColor);
}

#pragma mark -
#pragma mark Sub Test Definition
void CustomClassTest::testLayerColor(Ref *sender)
{
	log("testLayerColor");
	
	MyLayerColor *layer = MyLayerColor::create(Color4B::RED, 200, 300);
	

	//MyLayerColor *layer = MyLayerColor::cocos2d::LayerColor::create(Color4B::RED);
	addChild(layer);
}


#endif
