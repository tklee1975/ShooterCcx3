#ifdef ENABLE_TDD
//
//  TouchTest.m
//	TDD Framework 
//
//
#include "TouchTest.h"
#include "TDDHelper.h"
#include "StringHelper.h"

void TouchTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	mSprite = NULL;
	
	setupTouchListener();
}


void TouchTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

void TouchTest::setupTouchListener()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	
	listener->onTouchBegan = CC_CALLBACK_2(TouchTest::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(TouchTest::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(TouchTest::onTouchEnded, this);
	
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

#pragma mark -
#pragma mark List of Sub Tests

void TouchTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TouchTest::subTest);
}


#pragma mark -
#pragma mark Touch


bool TouchTest::onTouchBegan(Touch *touch, Event *event)
{
	const Vec2 &worldPos = touch->getLocation();
	log("began: world=%s", StringHelper::strVec2(worldPos).c_str());
	
	mLastPos = convertToNodeSpace(worldPos);
	
	return true;
}



void TouchTest::onTouchMoved(Touch *touch, Event *event)
{
	const Vec2 &worldPos = touch->getLocation();
	mNewPos = convertToNodeSpace(worldPos);
	
	log("move: world=%s", StringHelper::strVec2(worldPos).c_str());
	
	handleMove();
}

void TouchTest::onTouchEnded(Touch *touch, Event *event)
{
	const Vec2 &worldPos = touch->getLocation();
	
	log("end: world=%s", StringHelper::strVec2(worldPos).c_str());
}

#pragma mark -
#pragma mark Handle Sprite movement
void TouchTest::handleMove()
{
	if(mSprite == NULL) {
		return;
	}
	
	// Method 1: Simply set the position	// not good
	// mSprite->setPosition(mNewPos);
	
	// Method 2: Move by Diff
	float diffX = mNewPos.x - mLastPos.x;
	float diffY = mNewPos.y - mLastPos.y;
	
	Vec2 newPos = mSprite->getPosition();
	newPos.x += diffX;
	newPos.y += diffY;
	
	if(newPos.x < 0)		{ newPos.x = 0; }
	if(newPos.x >= 320)		{ newPos.x = 320; }
	if(newPos.y < 0)		{ newPos.y = 0; }
	if(newPos.y >= 320)		{ newPos.y = 320; }

	mSprite->setPosition(newPos);
//	MoveTo *move = MoveTo::create(0, newPos);
//	mSprite->runAction(move);
	
	
	mLastPos = mNewPos;
}

#pragma mark -
#pragma mark Sub Test Definition
void TouchTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
	mSprite = Sprite::create("myship.png");
	mSprite->setPosition(Vec2(200, 20));
	
	addChild(mSprite);
}


#endif
