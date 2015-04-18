#ifdef ENABLE_TDD
//
//  BulletTest.m
//	TDD Framework 
//
//
#include "BulletTest.h"
#include "TDDHelper.h"
#include "MyBullet.h"
#include "EnemyBullet.h"

void BulletTest::setUp()
{
	log("TDD Setup is called");

	FileUtils::getInstance()->addSearchPath("image");
}


void BulletTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void BulletTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(BulletTest::testCreate);
	SUBTEST(BulletTest::testMove);
	SUBTEST(BulletTest::testEnemyBullet);
}

#pragma mark -
#pragma mark Sub Test Definition
void BulletTest::testCreate(Ref *sender)
{
	MyBullet *bullet = MyBullet::create();
	
	bullet->setPosition(Vec2(200, 60));
	
	addChild(bullet);
}


void BulletTest::testMove(Ref *sender)
{
	MyBullet *bullet = MyBullet::create();
	
	bullet->setPosition(Vec2(200, 60));
	
	addChild(bullet);
	
	bullet->move();
}

void BulletTest::testEnemyBullet(Ref *sender)
{
	EnemyBullet *bullet = EnemyBullet::create(Vec2(150, 300));
	
	addChild(bullet);
	
	bullet->move();
}

#endif
