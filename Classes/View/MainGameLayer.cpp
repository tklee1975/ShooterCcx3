//
//  MainGameLayer.cpp
//  Shooter
//
//  Created by Ken Lee on 8/4/15.
//
//

#include "MainGameLayer.h"


#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "GameOverDialog.h"
#include "World.h"
#include "GameData.h"

#define PLAYER_LIFE		3
#define SCORE1			1
#define SCORE2			2

using namespace cocostudio::timeline;

Scene* MainGameLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	MainGameLayer *layer = MainGameLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	layer->startLevel(1);

	// return the scene
	return scene;
}


// on "init" you need to initialize your instance
bool MainGameLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}
	mWorld = nullptr;
	mDialog = nullptr;

	mCurrentLevel = 1;

	// Setup UI
	Node *rootNode = CSLoader::createNode("MainGameLayer.csb");
	addChild(rootNode);
	setupUI(rootNode);

	setupWorld();	// should be after setupUI


	mIsGameOver = true;

	//
	setScore(0);
	setLife(PLAYER_LIFE);
	hideLevelBanner();

	return true;
}

// ui note:
//		worldPanel	Panel	Panel for the World Layer
//		lifeText	Text	Text information for Life	(should be X 3)
//		scoreText	Text	Text information for score
//		levelText	Text	Level Popup
void MainGameLayer::setupUI(cocos2d::Node *mainPanel)
{
	Node *node;

	// Bind node to corresponding class variable
	node = mainPanel->getChildByName("lifeText");
	mLifeText = (Text *)node;

	node = mainPanel->getChildByName("scoreText");
	mScoreText = (Text *)node;

	node = mainPanel->getChildByName("levelText");
	mLevelText = (Text *)node;

	node = mainPanel->getChildByName("worldPanel");
	mWorldPanel = (Text *)node;

}

void MainGameLayer::setupWorld()
{
	if(mWorldPanel == nullptr) {
		log("setupWorld: mWorldPanel is null");
		return;
	}

	mWorld = World::instance();
	mWorld->reset();
	mWorld->setCallback(CC_CALLBACK_2(MainGameLayer::handleCallback, this));

	mWorldPanel->addChild(mWorld);

	mWorld->scheduleUpdate();
	mWorld->spawnMyShip();
}

void MainGameLayer::setLife(int life)
{
	mLife = life;
	if(mLifeText == NULL) {
		return;
	}

	char temp[20];
	sprintf(temp, "x %d", mLife);

	mLifeText->setString(temp);
}

void MainGameLayer::setScore(int score)
{
	mScore = score;
	if(mScoreText == NULL) {
		return;
	}

	char temp[30];
	sprintf(temp, "%d", mScore);

	mScoreText->setString(temp);

}

void MainGameLayer::hideLevelBanner()
{
	if(mLevelText == NULL) {
		return;
	}

	mLevelText->setVisible(false);
}

void MainGameLayer::showLevelBanner()
{
	if(mLevelText == NULL) {
		return;
	}

	char temp[30];
	sprintf(temp, "Level %d", mCurrentLevel);

	mLevelText->setString(temp);
	mLevelText->setVisible(true);
	
	// fade in
	auto fadeIn = FadeIn::create(1.0f);
	auto delay = DelayTime::create(1.5f);
	auto fadeOut = FadeOut::create(0.5f);

	World *world = mWorld;
	auto startWorld = CallFunc::create([world](){
		world->startWorld();
	});

	//
	auto seq = Sequence::create(fadeIn, delay, fadeOut, startWorld, nullptr);
	mLevelText->setOpacity(0);
	mLevelText->runAction(seq);


}

void MainGameLayer::startLevel(int level)
{
	if(mWorld == NULL) {
		log("error: mWorld is null");
		return;
	}

	if(level == 1) {
		setScore(0);
	}

	mIsGameOver = false;

	mCurrentLevel = level;

	mWorld->generateLevel(mCurrentLevel);
	showLevelBanner();


}

void MainGameLayer::handlePlayerDie()
{
	int newLife = mLife - 1;

	if(newLife < 0) {	newLife = 0; }

	setLife(newLife);

	if(newLife > 0) {
		mWorld->spawnMyShip();
	} else {
		// This is Game Over case
		GameData::instance()->setScore(mScore);
		showGameOverDialog();
	}
}

void MainGameLayer::increaseScore(int addScore)
{
	int newScore = mScore + addScore;

	setScore(newScore);
}

void MainGameLayer::startNewLevel()
{
	int newLevel = mCurrentLevel + 1;
	startLevel(newLevel);
}

void MainGameLayer::handleCallback(Ref *ref, World::WorldEvent event)
{
	if(mIsGameOver) {		// No need to handle any if game is overed
		return;
	}

	switch(event) {
		case World::WorldEvent::PlayerDie:
		{
			handlePlayerDie();
			break;
		}

		case World::WorldEvent::HitMonster1:
		{
			increaseScore(SCORE1);
			break;
		}

		case World::WorldEvent::HitMonster2:
		{
			increaseScore(SCORE2);
			break;
		}

		case World::WorldEvent::LevelClear:
		{
			startNewLevel();
			break;
		}
	}
}

void MainGameLayer::showGameOverDialog()
{
	GameOverDialog *dialog = GameOverDialog::create();

	addChild(dialog);

	dialog->setOKListener(CC_CALLBACK_1(MainGameLayer::onOK, this));
	dialog->setCancelListener(CC_CALLBACK_1(MainGameLayer::onCancel, this));

	mDialog = dialog;
}


void MainGameLayer::onOK(Ref *sender)
{
	log("OK button is clicked");

	if(mDialog != nullptr) {
		mDialog->removeFromParent();
	}

	setLife(PLAYER_LIFE);
	startLevel(1);


}

void MainGameLayer::onCancel(Ref *sender)
{
	log("Cancel button is clicked");
	Director::getInstance()->popToRootScene();
}
