//
//  MyTDDCases.h
//  Cocos2dxTDDLib
//
//	This header should be included by TDDCases.h only
//  Created by Ken Lee on 25/5/14.
//
//


// Add the Header here!
#include "SampleTest.h"
#include "ExampleTest.h"
#include "LabelTest.h"
#include "BulletTest.h"
#include "ShipTest.h"
#include "StringHelperTest.h"
#include "CustomClassTest.h"
#include "WorldTest.h"
#include "ParticleTest.h"
#include "TouchTest.h"
#include "EnemyLevelLogicTest.h"
#include "CocosStudioTest.h"
#include "MainGameLayerTest.h"
#include "ActionTest.h"
#include "CallbackTest.h"
#include "GeometryTest.h"
#include "MainLayerTest.h"
#include "GameOverDialogTest.h"

//#include#
// NOTE!!! The above line is used to generate new unit test, must not be removed.

// Define
TDD_CASES
{
	
	TEST(MainLayerTest),
	TEST(GameOverDialogTest),
	TEST(ActionTest),
	TEST(GeometryTest),
	TEST(CallbackTest),
	TEST(TouchTest),
	TEST(LabelTest),
	TEST(MainGameLayerTest),
	TEST(ExampleTest),
	TEST(CocosStudioTest),
	TEST(EnemyLevelLogicTest),
	TEST(ParticleTest),
	TEST(WorldTest),
	TEST(CustomClassTest),
	TEST(BulletTest),
	TEST(ShipTest),
	TEST(StringHelperTest),
	
//#testcase#
// NOTE!!! The above line is used to generate new unit test, must not be removed.
};


