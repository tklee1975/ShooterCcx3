#ifdef ENABLE_TDD
//
//  ShipTest.m
//	TDD Framework 
//
//
#include "ShipTest.h"
#include "TDDHelper.h"
#include "Ship.h"
#include "StringHelper.h"
#include "MyShip.h"
#include "World.h"
#include "EnemyShip.h"

void ShipTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	mMyShip = NULL;
	mEnemyShip = NULL;
	
	// 
	World *world = World::instance();
	world->reset();
	world->scheduleUpdate();
	addChild(world);
	
	mWorld = world;
	
	setupTouchListener();
}


void ShipTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void ShipTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(ShipTest::subTest);
	SUBTEST(ShipTest::testEnemyFire);
	SUBTEST(ShipTest::testEnemyAttack);
	SUBTEST(ShipTest::addMyShip);
	SUBTEST(ShipTest::testFire);
	SUBTEST(ShipTest::testAutoFire);
	SUBTEST(ShipTest::testExplode);
}

#pragma mark -
#pragma mark Sub Test Definition
#pragma mark - Touch handling
void ShipTest::setupTouchListener()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	
	listener->onTouchBegan = CC_CALLBACK_2(ShipTest::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(ShipTest::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(ShipTest::onTouchEnded, this);
	
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}


bool ShipTest::onTouchBegan(Touch *touch, Event *event)
{
	if(mMyShip == NULL) {
		return false;
	}

	handleShipDir(touch->getLocation());

	return true;
}

void ShipTest::handleShipDir(const Vec2 &worldPos)
{
	Vec2 localPoint = convertToNodeSpace(worldPos);
	
	Size size = this->getContentSize();
	MoveDir dir;
	if(localPoint.x < size.width / 2) {
		dir = MoveDirLeft;
	} else {
		dir = MoveDirRight;
	}
	
	if(mMyShip != NULL) {
		mMyShip->changeDir(dir);
	}

}

void ShipTest::onTouchMoved(Touch *touch, Event *event)
{
	handleShipDir(touch->getLocation());
}

void ShipTest::onTouchEnded(Touch *touch, Event *event)
{
	if(mMyShip != NULL) {
		mMyShip->changeDir(MoveDirNone);
	}
}


#pragma mark - Test

void ShipTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
	
	Ship *ship = Ship::create();
	
	Rect firstBound = ship->getBoundingBox();
	
	ship->setPosition(Vec2(200, 50));
	addChild(ship);
	
	Rect secondBound = ship->getBoundingBox();
	
	log("bound before: %s", StringHelper::strRect(firstBound).c_str());
	log("bound after: %s", StringHelper::strRect(secondBound).c_str());
}

void ShipTest::addMyShip(Ref *sender)
{
	log("addMyShip");
	if(mMyShip != NULL) {
		return;
	}
	
	Size size = this->getContentSize();
	Vec2 pos = Vec2(size.width / 2, 100);
	
	MyShip *ship = MyShip::create();
	ship->setPosition(pos);
	ship->setWorld(mWorld);
	
	//addChild(ship);
	mWorld->addShip(ship, pos);
	
	ship->scheduleUpdate();
	
	//LayerColor *layer = gm
	
	mMyShip = ship;
	
	log("shipBound=%s", StringHelper::strRect(mMyShip->getBoundingBox()).c_str());
}

void ShipTest::testFire(Ref *sender)
{
	log("addMyShip");
	if(mMyShip == NULL) {
		log("Ship is not ready");
		return;
	}
	
	mMyShip->fire();
}

void ShipTest::testAutoFire(Ref *sender)
{
	log("testAutoFire");
	if(mMyShip == NULL) {
		log("Ship is not ready");
		return;
	}
	
	bool flag = mMyShip->getAutoFire();
	
	mMyShip->setAutoFire(!flag);
}

void ShipTest::testExplode(Ref *sender)
{
	if(mMyShip == NULL) {
		log("Ship is not ready");
		return;
	}
	
	mMyShip->explode();
	mMyShip = NULL;
}

void ShipTest::testEnemyFire(Ref *sender)
{
	if(mEnemyShip == NULL) {
		mEnemyShip = EnemyShip::create();
		mWorld->addShip(mEnemyShip, Vec2(150, 300));
	}
	
	mEnemyShip->fire();
}

void ShipTest::testEnemyAttack(Ref *sender)
{
	if(mEnemyShip == NULL) {
		mEnemyShip = EnemyShip::create();
		mWorld->addShip(mEnemyShip, Vec2(150, 300));
	}
	
	//bool flag = mEnemyShip->getAttackMode();
	
	mEnemyShip->setAttackMode(true);
}



#endif
