//
//  GameOverDialog.h
//  TapToJump
//
//  Created by Ken Lee on 19/4/15.
//
//

#ifndef __TapToJump__GameOverDialog__
#define __TapToJump__GameOverDialog__

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

USING_NS_CC_EXT;
USING_NS_CC;

using namespace cocos2d;
using namespace cocos2d::ui;


class GameOverDialog : public Layer
{
public:
	CREATE_FUNC(GameOverDialog);
	
	virtual bool init();
	
	void setOKListener(const Widget::ccWidgetClickCallback &callback);
	void setCancelListener(const Widget::ccWidgetClickCallback &callback);
	
private:
	void setupUI(Node *mainPanel);
	void updateBestScore();
	void updateLastScore();
	
private:
	Button *mOKButton;
	Button *mCancelButton;
	Text *mBestScoreText;
	Text *mLastScoreText;
};

#endif /* defined(__TapToJump__GameOverDialog__) */
