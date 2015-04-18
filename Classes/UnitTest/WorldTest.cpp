#ifdef ENABLE_TDD
//
//  WorldTest.m
//	TDD Framework 
//
//
#include "WorldTest.h"
#include "TDDHelper.h"
#include "World.h"
#include "MyBullet.h"
#include "EnemyShip.h"
#include "Constants.h"
#include "MyShip.h"

void WorldTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	mWorld = NULL;
	mLevel = 1;
	//setupTouchListener();
}


void WorldTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void WorldTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(WorldTest::addWorld);
	SUBTEST(WorldTest::addBullet);
	SUBTEST(WorldTest::testLevel);
	SUBTEST(WorldTest::testRemoveEnemies);
	SUBTEST(WorldTest::addShip);
	SUBTEST(WorldTest::showInfo);
	SUBTEST(WorldTest::testExplosion);
	SUBTEST(WorldTest::testSpawn);
}


#pragma mark - Touch handling
void WorldTest::setupTouchListener()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	
	listener->onTouchBegan = CC_CALLBACK_2(WorldTest::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(WorldTest::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(WorldTest::onTouchEnded, this);
	
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

bool WorldTest::onTouchBegan(Touch *touch, Event *event)
{
	if(mWorld == NULL) {
		return false;
	}
	
	handleShipDir(touch->getLocation());
	
	return true;
}

void WorldTest::handleShipDir(const Vec2 &worldPos)
{
	if(mWorld == NULL) {
		return;
	}
	
	MyShip *ship = mWorld->getMyShip();
	if(ship == NULL) {
		return;
	}

	
	Vec2 localPoint = convertToNodeSpace(worldPos);
	
	Size size = this->getContentSize();
	MoveDir dir;
	if(localPoint.x < size.width / 2) {
		dir = MoveDirLeft;
	} else {
		dir = MoveDirRight;
	}
	
	ship->changeDir(dir);
}

void WorldTest::onTouchMoved(Touch *touch, Event *event)
{
	handleShipDir(touch->getLocation());
}

void WorldTest::onTouchEnded(Touch *touch, Event *event)
{
	if(mWorld == NULL) {
		return;
	}
	
	MyShip *ship = mWorld->getMyShip();
	if(ship == NULL) {
		return;
	}
	ship->changeDir(MoveDirNone);
}


#pragma mark -
#pragma mark Sub Test Definition
void WorldTest::addWorld(Ref *sender)
{
	log("Testing World");
	
	if(mWorld != NULL) {
		return;
	}
	
	World *world = World::instance();
	world->reset();
	world->spawnMyShip();
	world->scheduleUpdate();
	world->setCallback(CC_CALLBACK_2(WorldTest::handleCallback, this));
	
	addChild(world);
	
	mWorld = world;
}


void WorldTest::addBullet(Ref *sender)
{
	log("Testing bullet");
	
	if(mWorld == NULL) {
		log("World isn't created");
		return;
	}
	
	MyBullet *bullet = MyBullet::create();
	
	mWorld->addBullet(bullet, Vect(100, 10));
}

void WorldTest::addShip(Ref *sender)
{
	log("Testing ship");
	
	if(mWorld == NULL) {
		log("World isn't created");
		return;
	}
	
	if(mWorld->getEnemyCount() > 10) {
		log("too many enemys");
		return;
	}
	
	EnemyShip *ship = EnemyShip::create();
	

	static int x = 50;
	static int y = 500;
	
	if(x > 320) {
		x = 50;
		y -= 60;
	}
	
	mWorld->addShip(ship, Vect(x, y));
	
	x += 60;
}

void WorldTest::showInfo(Ref *sender)
{
	log("Testing showInfo");
	
	if(mWorld == NULL) {
		log("World isn't created");
		return;
	}

	log("World:\n%s", mWorld->info().c_str());
}

void WorldTest::testExplosion(Ref *sender)
{
	log("Testing testExplosion");
	
	if(mWorld == NULL) {
		log("World isn't created");
		return;
	}

	mWorld->addExplosion(Vec2(50, 300));
}


void WorldTest::testSpawn(Ref *sender)
{
	if(mWorld == NULL) {
		log("World isn't created");
		return;
	}
	
//	int idx = 0;
	int level = 1;
	for(int x=40; x<320; x+=80) {
		Vec2 pos = Vec2(x, 400);
		
		mWorld->spawnEnemy(pos, level);
		
		level += 20;
	}
	
	
//	mWorld->spawnMyShip();
//	mWorld->getMyShip()->setAutoFire(true);
}

void WorldTest::testRemoveEnemies(Ref *sender)
{
	if(mWorld == NULL) {
		log("World isn't created");
		return;
	}

	mWorld->removeAllEnemies();
}

void WorldTest::testLevel(Ref *sender)
{
	if(mWorld == NULL) {
		log("World isn't created");
		return;
	}
	
	//mWorld->reset();
	
	
	mWorld->generateLevel(mLevel);
	
	mLevel++;
	
	if(mLevel > 10) {
		mLevel = 1;
	}
}

void WorldTest::handleCallback(Ref *ref, World::WorldEvent event)
{
	log("WorldEvent: %d", event);
	
	if(event == World::WorldEvent::PlayerDie)
	{
		mWorld->spawnMyShip();
	}
}

#endif
