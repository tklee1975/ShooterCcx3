#ifdef ENABLE_TDD
//
//  EnemyLevelLogicTest.m
//	TDD Framework 
//
//
#include "EnemyLevelLogicTest.h"
#include "TDDHelper.h"
#include "EnemyLevelLogic.h"
#include "EnemyShip.h"
#include "StringHelper.h"

void EnemyLevelLogicTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void EnemyLevelLogicTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void EnemyLevelLogicTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(EnemyLevelLogicTest::testCreateEnemyLv1);
	SUBTEST(EnemyLevelLogicTest::testCreateEnemyLv3);
}

#pragma mark -
#pragma mark Sub Test Definition
void EnemyLevelLogicTest::testCreateEnemyLv1(Ref *sender)
{
	Vector<EnemyShip *> shipList;
	EnemyLevelLogic::createEnemy(1, shipList);
	
	for(int i=0; i<shipList.size(); i++) {
		EnemyShip *ship = shipList.at(i);
		
		log("%s", ship->toString().c_str());
	}
}


void EnemyLevelLogicTest::testCreateEnemyLv3(Ref *sender)
{
	Vector<EnemyShip *> shipList;
	EnemyLevelLogic::createEnemy(3, shipList);
	
	for(int i=0; i<shipList.size(); i++) {
		EnemyShip *ship = shipList.at(i);
		
		log("%s", ship->toString().c_str());
	}
}

#endif
