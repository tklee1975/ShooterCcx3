#ifdef ENABLE_TDD
//
//  CollisionDetectorTest.m
//	TDD Framework 
//
//
#include "CollisionDetectorTest.h"
#include "TDDHelper.h"

void CollisionDetectorTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void CollisionDetectorTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void CollisionDetectorTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(CollisionDetectorTest::subTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void CollisionDetectorTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
}


#endif
