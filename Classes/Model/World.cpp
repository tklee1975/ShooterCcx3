

//
//  World.cpp
//  Shooter
//
//  Created by Ken Lee on 2/2/15.
//
//

#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;


#include "World.h"
#include "StringHelper.h"
#include "Bullet.h"
#include "Ship.h"
#include "EnemyShip.h"
#include "MyBullet.h"
#include "EnemyBullet.h"
#include "MyShip.h"
#include "EnemyLevelLogic.h"



static World *sInstance = NULL;

//#define k
World *World::instance()
{
	if(sInstance != NULL) {
		return sInstance;
	}
	
	sInstance = new World();
	sInstance->init();
	
	return sInstance;
}


bool World::init()
{
	Size size = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	
	log("World size=%s", StringHelper::strSize(size).c_str());
	
	bool isOk = LayerColor::initWithColor(Color4B::BLACK, size.width, size.height);
	if (isOk == false)
	{
		return false;
	}
	
	//mCallback = nullptr;
	preloadSounds();
	
	setupTouchListener();
	setupBounds();
	mState = WorldState::NotStart;
	
	return true;
}

void World::preloadSounds()
{
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_FIRE);
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EXPLORE_ME);
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EXPLORE_OTHER);
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_LEVEL_COMPLETE);
}

void World::playSound(const char *file)
{
	SimpleAudioEngine::getInstance()->playEffect(file);
}

void World::setupBounds()
{
	Size designSize = Director::getInstance()->getVisibleSize();
	
	log("setupBounds: designSize=%s", StringHelper::strSize(designSize).c_str());

	float insetX = 10;
	float insetY = 10;
	mMyShipBound = Rect(insetX, insetY, designSize.width-insetX*2,
						designSize.height / 2 - insetY*2);
	mWorldBound = Rect(0, 0, designSize.width, designSize.height);

	
	bool showBoundArea = false;
	
	if(showBoundArea == false) {
		return;
	}
	mWorldBoundLayer = LayerColor::create(Color4B(0, 0, 255, 50),
										  mWorldBound.size.width, mWorldBound.size.height);
	mWorldBoundLayer->setPosition(mWorldBound.origin);
	addChild(mWorldBoundLayer);

	
	mShipBoundLayer = LayerColor::create(Color4B(255, 0, 0, 50),
						mMyShipBound.size.width, mMyShipBound.size.height);
	mShipBoundLayer->setPosition(mMyShipBound.origin);
	addChild(mShipBoundLayer);
	
	//
	
	
}

void World::addBullet(Bullet *bullet, const Vect &from)
{
	if(bullet == NULL) {
		return;
	}
	
	addModel(bullet, from);
	bullet->move();
	
	if (bullet->getType() == Model::Type::Me) {
		mMyBullets.pushBack(bullet);
	} else {
		mEnemyBullets.pushBack(bullet);
	}

	//mMyBullets.pushBack(bullet);
}

void World::removeBullet(Bullet *bullet)
{
	if(bullet == NULL) {
		return;
	}
	
	if (bullet->getType() == Model::Type::Me) {
		mMyBullets.eraseObject(bullet);
	} else {
		mEnemyBullets.eraseObject(bullet);
	}
}

void World::checkBulletCollision()
{
	if(mState != WorldState::Running) {
		return;
	}
	
	Vector<EnemyShip *> hitEnemy;
	
	// Find the collided enemies
	for(int i=0; i<mEnemies.size(); i++) {
		EnemyShip *ship = (EnemyShip *) mEnemies.at(i);
		if(ship->canCollide() == false) {
			continue;
		}
		
		Rect shipBound = ship->getBoundingBox();
		for(int j=0; j<mMyBullets.size(); j++) {
			MyBullet *bullet = (MyBullet *)mMyBullets.at(j);
			
			Rect bulletBound = bullet->getBoundingBox();
			
			if(bulletBound.intersectsRect(shipBound)) {
				hitEnemy.pushBack(ship);
				bullet->removeFromParent();
				mMyBullets.eraseObject(bullet);
				break;
			}
		}
	}
	
	// Find the collide myShip
	if(mMyShip != NULL && mMyShip->canCollide()) {
		for(int j=0; j<mEnemyBullets.size(); j++) {
			EnemyBullet *bullet = (EnemyBullet *)mEnemyBullets.at(j);
			
			Rect bulletBound = bullet->getBoundingBox();
			if(bulletBound.intersectsRect(mMyShip->getBoundingBox())) {
				mMyShip->explode();
				break;
			}
		}
	}
	
	
	
	for(int i=0; i<hitEnemy.size(); i++) {
		EnemyShip *ship = (EnemyShip *) hitEnemy.at(i);
		
		ship->explode();
	}
	
}

// Level 1: 0 0 0 N N 0 0 0
// Level 2: 0 0 A N N A 0 0
void World::generateLevel(int level)
{

	
	spawnMyShip();
	
	// Create Enemies;
	removeAllEnemies();
	
	Vector<EnemyShip *> shipList;
	
	EnemyLevelLogic::createEnemy(level, shipList);
	
	for(int i=0; i<shipList.size(); i++) {
		EnemyShip *ship = shipList.at(i);
		
		ship->setAttackMode(false);
		addShip(ship, ship->getPosition());
	}
	
	
	//
	shipList.clear();	// clean up
}

void World::spawnEnemy(const Vec2 &pos, int level)
{
	EnemyShip *ship = EnemyShip::create(EnemyShip::EnemyType::Normal, level);
	ship->setAttackMode(true);
	addShip(ship, pos);	
}

void World::handleMyShipMove()
{
	if(mMyShip == NULL) {
		return;
	}
	
	// Method 1: Simply set the position	// not good
	// mSprite->setPosition(mNewPos);
	
	// Method 2: Move by Diff
	float diffX = mNewTouchPos.x - mLastTouchPos.x;
	float diffY = mNewTouchPos.y - mLastTouchPos.y;
	
	
	Vec2 newPos = mMyShip->getPosition();
	newPos.x += diffX;
	newPos.y += diffY;
	
	
	
	if(newPos.x < mMyShipBound.getMinX())		{ newPos.x = mMyShipBound.getMinX(); }
	if(newPos.x > mMyShipBound.getMaxX())		{ newPos.x = mMyShipBound.getMaxX(); }
	if(newPos.y < mMyShipBound.getMinY())		{ newPos.y = mMyShipBound.getMinY(); }
	if(newPos.y > mMyShipBound.getMaxY())		{ newPos.y = mMyShipBound.getMaxY(); }

	mMyShip->setPosition(newPos);
	
	
	mLastTouchPos = mNewTouchPos;
}

void World::spawnMyShip()
{
	MyShip *ship;
	if(mMyShip != nullptr) {
		ship = mMyShip;
	} else {
		Size size = this->getContentSize();
		Vec2 pos = Vec2(size.width / 2, 50);
		
		ship = MyShip::create();
		addShip(ship, pos);
	}
	
	ship->setAutoFire(mState == WorldState::Running ? true : false);
}

void World::addModel(Model *model, const Vec2 &pos)
{
	model->setWorld(this);
	model->setPosition(pos);
	
	addChild(model);
}

void World::addShip(Ship *ship, const Vect &pos)
{
	if(ship == NULL) {
		return;
	}
	
	addModel(ship, pos);
	
	if (ship->getType() == Model::Type::Me) {
		setMyShip((MyShip *) ship);
	} else {
		mEnemies.pushBack(ship);
	}
}


void World::removeMyShip(MyShip *ship)
{
	if(ship != mMyShip) {
		return;
	}
	
	playSound(SOUND_EXPLORE_ME);
	
	setMyShip(NULL);
	removeChild(ship);
	sendEvent(WorldEvent::PlayerDie);
}

void World::removeEnemyShip(EnemyShip *ship)
{
	mEnemies.eraseObject(ship);
	removeChild(ship);
	
	playSound(SOUND_EXPLORE_OTHER);
	
	WorldEvent event = ship->getEnemyType() == EnemyShip::EnemyType::Angry ?
							WorldEvent::HitMonster2 : WorldEvent::HitMonster1;
	sendEvent(event);
	
	
	if(mEnemies.size() > 0) {
		return;
	}
	
	// Level end
	playSound(SOUND_LEVEL_COMPLETE);
	
	// Wait for Next Level
	mState = WorldState::WaitForNextLevel;
	if(mMyShip != nullptr) {
		mMyShip->setAutoFire(false);
	}
	
	sendEvent(WorldEvent::LevelClear);
}

void World::removeShip(Ship *ship)
{
	if(ship == NULL) {
		return;
	}
	
	if (ship->getType() == Model::Type::Me) {
		removeMyShip((MyShip *) ship);
	} else {
		removeEnemyShip((EnemyShip *) ship);
	}
	
}

void World::removeModel(Model *model)
{
	if(model == NULL) {
		return;
	}
	
// if 
	
}

int World::getEnemyCount()
{
	return (int) mEnemies.size();
}

void World::addExplosion(const Vec2 &position)
{
	std::string filename = "particle/explosion.plist";
	
	ParticleSystemQuad *emitter = ParticleSystemQuad::create(filename);
	emitter->setPosition(position);
	emitter->setScale(0.4);
	
	addChild(emitter);
}

void World::update(float delta)
{
//	log("World update: %f", delta);
	if(mMyShip != NULL) {
		mMyShip->update(delta);
	}
	for(int i=0; i<mEnemies.size(); i++) {
		EnemyShip *ship = (EnemyShip *) mEnemies.at(i);
		
		ship->update(delta);
	}
	
	checkBulletCollision();
}

std::string World::info() const
{
	std::string info = "";
	char temp[200];

	// my bullet
	sprintf(temp, "My bullet count: %zd\n", mMyBullets.size());
	info += temp;

	sprintf(temp, "Enemy bullet count: %zd\n", mEnemyBullets.size());
	info += temp;

	return info;
}

#pragma mark -
#pragma mark Touch
void World::setupTouchListener()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	
	listener->onTouchBegan = CC_CALLBACK_2(World::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(World::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(World::onTouchEnded, this);
	
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	
}



bool World::onTouchBegan(Touch *touch, Event *event)
{
	const Vec2 &worldPos = touch->getLocation();
	// log("began: world=%s", StringHelper::strVec2(worldPos).c_str());

	mLastTouchPos = convertToNodeSpace(worldPos);
	
	return true;
}

void World::onTouchMoved(Touch *touch, Event *event)
{
	const Vec2 &worldPos = touch->getLocation();
	
	
	// log("move: world=%s", StringHelper::strVec2(worldPos).c_str());
	mNewTouchPos = convertToNodeSpace(worldPos);
	

	handleMyShipMove();
}

void World::onTouchEnded(Touch *touch, Event *event)
{
	const Vec2 &worldPos = touch->getLocation();
	
	// log("end: world=%s", StringHelper::strVec2(worldPos).c_str());
}

void World::reset()
{
	if(getParent() != NULL) {
		removeFromParent();
	}
	
	removeAllEnemies();
	
	setMyShip(NULL);
	mMyBullets.clear();
	mEnemyBullets.clear();
	
	removeAllChildren();
	setupBounds();
	
	mState = WorldState::NotStart;
}

void World::removeAllEnemies()
{
	for(int i=0; i<mEnemies.size(); i++) {
		Model *ship = mEnemies.at(i);
		removeChild(ship);		
	}
	mEnemies.clear();
}

void World::sendEvent(WorldEvent worldEvent)
{
	if(mCallback == nullptr) {
		log("sendEvent: mCallback is null");
		return;
	}
	
	mCallback(this, worldEvent);
}

void World::setCallback(const Callback &callback)
{
	mCallback = callback;
}

void World::startWorld()
{
	mState = WorldState::Running;
	if(mMyShip != nullptr) {
		mMyShip->setAutoFire(true);
	}
	
	for(int i=0; i<mEnemies.size(); i++) {
		EnemyShip *ship = (EnemyShip *) mEnemies.at(i);
		ship->setAttackMode(true);
	}
}