//
//  MainScene.cpp
//  Shooter
//
//  Created by Ken Lee on 18/4/15.
//
//

#include "MainScene.h"

// For cocos studio ui
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

// For unit test
#include "TDDHelper.h"

// Game
#include "MainGameLayer.h"


Scene* MainSceneLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	
	// 'layer' is an autorelease object
	auto layer = MainSceneLayer::create();
	
	// add layer as a child to scene
	scene->addChild(layer);
	
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainSceneLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}
	
	// Setup UI
	Node *rootNode = CSLoader::createNode("MainScene.csb");
	addChild(rootNode);
	setupUI(rootNode);
	
	
	// Adding test button
	Point pos = Point(240, 70);
	TDDHelper::addTestButton(this, pos);
	
	return true;
}

void MainSceneLayer::setupUI(cocos2d::Node *mainPanel)
{
	
	auto parent = this;
	
//	// Bind node to corresponding class variable
	Button *startButton = (Button *) mainPanel->getChildByName("buttonStart");
//	mPlayerButton = (Button *)node;
	if(startButton != NULL) {
		startButton->addClickEventListener([parent](Ref *) {
			parent->startGame();
		});
	}
	
//	mLifeText = (Text *)node;
}

void MainSceneLayer::startGame() {
	log("startGame is called");
	
	Director::getInstance()->pushScene(MainGameLayer::createScene());
}


