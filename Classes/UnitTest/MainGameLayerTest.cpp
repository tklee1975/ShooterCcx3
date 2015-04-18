#ifdef ENABLE_TDD
//
//  MainGameLayerTest.m
//	TDD Framework 
//
//
#include "MainGameLayerTest.h"
#include "TDDHelper.h"
#include "MainGameLayer.h"

void MainGameLayerTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	// Setup the mainLayer
	MainGameLayer *layer = MainGameLayer::create();
	addChild(layer);
	mMainLayer = layer;
	mLevel = 1;
}


void MainGameLayerTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void MainGameLayerTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(MainGameLayerTest::subTest);
	SUBTEST(MainGameLayerTest::changeLevel);
}

#pragma mark -
#pragma mark Sub Test Definition
void MainGameLayerTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
	mMainLayer->showLevelBanner();
}

void MainGameLayerTest::changeLevel(Ref *sender)
{
	log("this is a sample subTest");
	mMainLayer->startLevel(mLevel);
	mLevel++;
}


#endif
