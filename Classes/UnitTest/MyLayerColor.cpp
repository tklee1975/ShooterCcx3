//
//  MyLayerColor.cpp
//
#include "MyLayerColor.h"


MyLayerColor * MyLayerColor::create(const Color4B& color, float width, float height)
{
	MyLayerColor * layer = new (std::nothrow) MyLayerColor();
	if( layer && layer->initWithColor(color, width, height))
	{
		
		layer->autorelease();
		return layer;
	}
	
	CC_SAFE_DELETE(layer);
	return nullptr;
}

bool MyLayerColor::initWithColor(const cocos2d::Color4B &color, float width, float height)
{
	//////////////////////////////
	// 1. super init first
	bool isOk = LayerColor::initWithColor(color, width, height);
	if (isOk == false)
	{
		return false;
	}
	
	return true;
}

