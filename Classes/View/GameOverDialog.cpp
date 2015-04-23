//
//  GameOverDialog.cpp
//  Shooter
//
//  Created by Ken Lee on 19/4/15.
//
//

#include "GameOverDialog.h"

#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

#include "GameData.h"

using namespace cocostudio::timeline;

// Local Method
namespace {
	void setFadeIn(Node *node, float delayTime, float fadeTime)
	{
		
		auto delay = delayTime <= 0 ? nullptr : DelayTime::create(delayTime);
		auto fadeIn = FadeIn::create(fadeTime);
		
		Action *action;
		
		if(delay == nullptr) {
			action = fadeIn;
		} else {
			action = Sequence::create(delay, fadeIn, nullptr);
		}
		
		node->setOpacity(0);
		node->runAction(action);
	}
	
	void setMoveIn(Node *node, float delayTime, float moveTime, const Vec2 &pos)
	{
		
		auto delay = delayTime <= 0 ? nullptr : DelayTime::create(delayTime);
		auto moveIn = MoveTo::create(moveTime, pos);
		
		Action *action;
		
		if(delay == nullptr) {
			action = moveIn;
		} else {
			action = Sequence::create(delay, moveIn, nullptr);
		}
		
		node->runAction(action);
	}
}

// on "init" you need to initialize your instance
bool GameOverDialog::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}
	
	mOKButton = nullptr;
	mCancelButton = nullptr;
	
	// Setup UI
	Node *rootNode = CSLoader::createNode("GameOverDialog.csb");
	addChild(rootNode);
	setupUI(rootNode);
	
	// update the score
	updateLastScore();
	updateBestScore();
	
	return true;
}

// ui note:
//		panelDialog	Panel	Panel for the Dialog
//		textGameOver	Text	Game Over Title
//		buttonOK		Button	OK Button
//		buttonCancel	Button	Cancel Button
//		scoreText		Text
//		bestScoreText	Text
void GameOverDialog::setupUI(cocos2d::Node *mainPanel)
{
	Node *node, *panelDialog;
	
	// Bind node to corresponding class variable
	node = mainPanel->getChildByName("textGameOver");
	setFadeIn(node, 0, 1.0f);
	
	//
	panelDialog = mainPanel->getChildByName("panelDialog");
	setFadeIn(panelDialog, 1, 0.5f);
	
	// auto parent = this;
	// Score text
	mBestScoreText = (Text *) panelDialog->getChildByName("bestScoreText");
	mLastScoreText = (Text *) panelDialog->getChildByName("scoreText");
	
	
	//	// Bind node to corresponding class variable
	mOKButton = (Button *) panelDialog->getChildByName("buttonOK");
	mCancelButton = (Button *) panelDialog->getChildByName("buttonCancel");
	
//	mOKButton->addClickEventListener(<#const ccWidgetClickCallback &callback#>)
}

void GameOverDialog::setOKListener(const Widget::ccWidgetClickCallback &callback)
{
	if(mOKButton) {
		mOKButton->addClickEventListener(callback);
	} else {
		log("mOKButton is null");
	}
}

void GameOverDialog::setCancelListener(const Widget::ccWidgetClickCallback &callback)
{
	if(mCancelButton) {
		mCancelButton->addClickEventListener(callback);
	} else {
		log("mCancelButton is null");
	}

}
void GameOverDialog::updateLastScore()
{
	int lastScore = GameData::instance()->getLastScore();
	
	if(mLastScoreText == nullptr) {
		return;
	}
	
	char temp[100];
	sprintf(temp, "Score: %d", lastScore);
	
	mLastScoreText->setString(temp);
}

void GameOverDialog::updateBestScore()
{
	int bestScore = GameData::instance()->getBestScore();

	if(mBestScoreText == nullptr) {
		return;
	}
	
	char temp[100];
	sprintf(temp, "(Best Score: %d)", bestScore);
	
	mBestScoreText->setString(temp);
}