#ifdef ENABLE_TDD
//
//  MainLayerTest.m
//	TDD Framework 
//
//
#include "MainLayerTest.h"
#include "TDDHelper.h"

#include "MainScene.h"

void MainLayerTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void MainLayerTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void MainLayerTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(MainLayerTest::testMainScene);
	SUBTEST(MainLayerTest::testCreateScene);
}

#pragma mark -
#pragma mark Sub Test Definition
void MainLayerTest::testMainScene(Ref *sender)
{
	log("this is a sample subTest");
	// Setup the mainLayer
	MainSceneLayer *layer = MainSceneLayer::create();
	addChild(layer);
}


void MainLayerTest::testCreateScene(Ref *sender)
{
	log("this is a sample subTest");
	// Setup the mainLayer
	Scene *scene = MainSceneLayer::createScene();
	
	Director::getInstance()->pushScene(scene);
}


#endif
