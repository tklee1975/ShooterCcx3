//
//  MainGameLayer.h
//  Shooter
//
//  Created by Ken Lee on 8/4/15.
//
//

#ifndef __Shooter__MainGameLayer__
#define __Shooter__MainGameLayer__

#include <stdio.h>

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

#include "World.h"

USING_NS_CC_EXT;
USING_NS_CC;

using namespace cocos2d;
using namespace cocos2d::ui;


class MainGameLayer : public Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene *createScene();
	
	CREATE_FUNC(MainGameLayer);

	bool init();

	
public:
	void setLife(int life);
	void setScore(int score);
	void startLevel(int level);
	void hideLevelBanner();
	void showLevelBanner();
	
private:
	void setupUI(Node *mainPanel);
	void setupWorld();
	void handleCallback(Ref *ref, World::WorldEvent event);
	
	void handlePlayerDie();
	void increaseScore(int addScore);
	void startNewLevel();
	void showGameOverDialog();
	void onOK(Ref *sender);
	void onCancel(Ref *sender);

private:	// private members
	Text *mScoreText;
	Text *mLifeText;
	Text *mLevelText;
	Node *mWorldPanel;
	World *mWorld;
	
	Node *mDialog;
	
	//
	int mScore;
	int mLife;
	int mCurrentLevel;
	bool mIsGameOver;
};

#endif /* defined(__Shooter__MainGameLayer__) */
