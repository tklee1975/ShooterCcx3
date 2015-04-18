#ifdef ENABLE_TDD
//
//  CocosStudioTest.m
//	TDD Framework 
//
//
#include "CocosStudioTest.h"
#include "TDDHelper.h"

#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocostudio::timeline;

void CocosStudioTest::setUp()
{
	log("TDD Setup is called");
	FileUtils::getInstance()->addSearchPath("gui");
	FileUtils::getInstance()->addSearchPath("image");
}


void CocosStudioTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void CocosStudioTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(CocosStudioTest::testMainScene);
	SUBTEST(CocosStudioTest::testMainGameLayer);
	SUBTEST(CocosStudioTest::testGameOverDialog);
}

#pragma mark -
#pragma mark Sub Test Definition
void CocosStudioTest::testMainScene(Ref *sender)
{
	Node *rootNode = CSLoader::createNode("MainScene.csb");
	addChild(rootNode);
}


void CocosStudioTest::testMainGameLayer(Ref *sender)
{
	Node *rootNode = CSLoader::createNode("MainGameLayer.csb");
	addChild(rootNode);
}

void CocosStudioTest::testGameOverDialog(Ref *sender)
{
	Node *rootNode = CSLoader::createNode("GameOverDialog.csb");
	addChild(rootNode);
}

#endif
