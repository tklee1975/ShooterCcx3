#ifdef ENABLE_TDD
//
//  ActionTest.m
//	TDD Framework 
//
//
#include "ActionTest.h"
#include "TDDHelper.h"

void ActionTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void ActionTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void ActionTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(ActionTest::subTest);
	SUBTEST(ActionTest::testFunc);
}

#pragma mark -
#pragma mark Sub Test Definition
void ActionTest::subTest(Ref *sender)		// Fade In and Out
{
	log("this is a sample subTest");
	
	Label *label = Label::createWithSystemFont("Testing", "Arial", 20);
	label->setTextColor(Color4B::RED);
	label->setPosition(Vec2(160, 200));
	
	addChild(label);
	
	
	// fade in
	auto fadeIn = FadeIn::create(1.0f);
	auto delay = DelayTime::create(1.3f);
	auto fadeOut = FadeOut::create(0.5f);
	auto remove = RemoveSelf::create();
	
	//
	auto seq = Sequence::create(fadeIn, delay, fadeOut, remove, nullptr);
	label->setOpacity(0);
	label->runAction(seq);
}


void ActionTest::testFunc(Ref *sender)		// Fade In and Out
{
	log("this is a sample subTest");
	
	Label *label = Label::createWithSystemFont("Testing", "Arial", 20);
	label->setTextColor(Color4B::RED);
	label->setPosition(Vec2(160, 200));
	
	addChild(label);
	
	
	
	// fade in
	auto fadeIn = FadeIn::create(1.0f);
	auto delay = DelayTime::create(1.3f);
	auto fadeOut = FadeOut::create(0.5f);
	auto callbackRotate = CallFunc::create([](){
		log("Action Done!");
	});

	
	//
	auto seq = Sequence::create(fadeIn, delay, fadeOut, callbackRotate, nullptr);
	label->setOpacity(0);
	label->runAction(seq);
}


#endif
