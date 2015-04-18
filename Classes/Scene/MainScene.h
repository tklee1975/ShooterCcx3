//
//  MainScene.h
//  Shooter
//
//  Created by Ken Lee on 18/4/15.
//
//

#ifndef __Shooter__MainScene__
#define __Shooter__MainScene__

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

USING_NS_CC_EXT;
USING_NS_CC;

using namespace cocos2d;
using namespace cocos2d::ui;


class MainSceneLayer : public Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene *createScene();
	
	// create function for this Layer
	CREATE_FUNC(MainSceneLayer);
	
	virtual bool init();
	
private:
	void setupUI(Node *mainPanel);
	void startGame();
};

#endif /* defined(__Shooter__MainScene__) */
