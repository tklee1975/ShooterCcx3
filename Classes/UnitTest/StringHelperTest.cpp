#ifdef ENABLE_TDD
//
//  StringHelperTest.m
//	TDD Framework 
//
//
#include "StringHelperTest.h"
#include "TDDHelper.h"
#include "cocos2d.h"
#include "StringHelper.h"

USING_NS_CC;

void StringHelperTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void StringHelperTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void StringHelperTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(StringHelperTest::test_strRect);
}

#pragma mark -
#pragma mark Sub Test Definition
void StringHelperTest::test_strRect(Ref *sender)
{
	log("strRect");
	
	Rect rect = Rect(10, 50, 100, 120);
	
	log("rect=%s", StringHelper::strRect(rect).c_str());
}


#endif
