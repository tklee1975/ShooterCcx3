#ifdef ENABLE_TDD
//
//  SoundTest.m
//	TDD Framework 
//
//
#include "SoundTest.h"
#include "TDDHelper.h"

#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;

#define SOUND_FIRE	"shot.mp3"

void SoundTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_FIRE);

}


void SoundTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void SoundTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(SoundTest::subTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void SoundTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
	
	SimpleAudioEngine::getInstance()->playEffect(SOUND_FIRE);
}


#endif
