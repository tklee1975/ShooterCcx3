//
//  MyLayerColor.h
//  Shooter
//
//  Created by Ken Lee on 5/2/15.
//
//

#ifndef __Shooter__MyLayerColor__
#define __Shooter__MyLayerColor__

#include <stdio.h>

#include "cocos2d.h"

USING_NS_CC;

class MyLayerColor : public cocos2d::LayerColor
{
public:
	static MyLayerColor *create(const Color4B& color, float width, float height);
	
	virtual bool initWithColor(const cocos2d::Color4B &color, float width, float height);
};
#endif /* defined(__Shooter__MyLayerColor__) */
