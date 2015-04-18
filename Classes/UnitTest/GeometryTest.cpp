#ifdef ENABLE_TDD
//
//  GeometryTest.m
//	TDD Framework 
//
//
#include "GeometryTest.h"
#include "TDDHelper.h"

void GeometryTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void GeometryTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void GeometryTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(GeometryTest::subTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void GeometryTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
}


#endif
