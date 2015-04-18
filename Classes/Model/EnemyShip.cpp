//
//  EnemyShip.cpp
//  Shooter
//
//  Created by Ken Lee on 6/2/15.
//
//

#include "EnemyShip.h"
#include "EnemyBullet.h"
#include "World.h"
#include "StringHelper.h"

EnemyShip *EnemyShip::create(EnemyType enemyType, int level)
{
	EnemyShip *ship = new EnemyShip();
	
	ship->init(enemyType, level);
	ship->autorelease();
	
	return ship;
}

bool EnemyShip::init()
{
	return init(EnemyType::Normal, 1);
}

bool EnemyShip::init(EnemyType enemyType, int level)
{
	if(Ship::init() == false) {
		return false;
	}
	
	mLevel = level;
	setEnemyType(enemyType);
	const char *sprite = enemyType == EnemyType::Normal ? "eship1.png" : "eship2.png";
	
	this->setTexture(sprite);
	mType = Model::Type::Enemy;
	
	
	setupLevel();
	
	mTimeToAttack = 0;
	mTimeToNextRecharge = 0.1;		// 5 second to recharge
	mRemainBullet = mBullet;			//
	
	return true;
}

void EnemyShip::setupLevel()
{
	mBulletChase = mEnemyType == EnemyType::Angry;
	
	int modLevel = (int)((mLevel - 1) / 5 + 1);
	
	mRechargeTime = 5 / (1 + 0.5 * modLevel);
	
	mBullet = modLevel;
	mBulletSpeed = mBulletChase ? 3 : 6;
}

void EnemyShip::update(float delta)
{
	//handleAutoFire(delta);
	attackLogic(delta);
}

void EnemyShip::attackLogic(float delta)
{
	//log("enemyShip: attack: mode=%d", mAttackFlag);
	if(mAttackFlag == false) {
		return;	// No attack
	}
	
	mTimeToNextRecharge -= delta;
	
	if(mTimeToNextRecharge > 0) {
		return;	// Wait for recharge
	}
	
	if(mRemainBullet <= 0) {
		mTimeToNextRecharge = mRechargeTime;	// 5 second to recharge
		mRemainBullet = mBullet;
		return;
	}
	
	mTimeToAttack -= delta;
	if(mTimeToAttack > 0) {
		return;		// No yet fire next bullet
	}
	
	fire();
	
	mRemainBullet--;	// lest bullet
	mTimeToAttack = 0.1;	// wait for 0.2 second to fire
	
}

Vec2 EnemyShip::getMoveToPlayerDir()
{
	Vec2 myPos = getPosition();
	Ship *playerShip = World::instance()->getMyShip();
	if(playerShip == NULL) {
		Size size = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
		return Vec2(0, -size.height);		// default
	}
	
	Vec2 playerPos = World::instance()->getMyShip()->getPosition();
	
	float y = 0;
	float x = myPos.x - myPos.y * (playerPos.x - myPos.x) / (playerPos.y - myPos.y);
	
	float deltaY = y - myPos.y;
	float deltaX = x - myPos.x;
	
	return Vec2(deltaX, deltaY);
}

void EnemyShip::fire()
{
	World *world = World::instance();
	
	Vec2 delta;
	if(mBulletChase == false) {
		Size size = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
		delta = Vec2(0, -size.height);		// default
	} else {
		delta = getMoveToPlayerDir();
	}
	
	EnemyBullet *bullet = EnemyBullet::create(delta);
	bullet->setSpeed(mBulletSpeed);
	
	world->addBullet(bullet, this->getPosition());
}

std::string EnemyShip::toString()
{
	char temp[100];
	
	sprintf(temp, "pos:%s", StringHelper::strVec2(getPosition()).c_str());
	sprintf(temp, "%s type:%d", temp, mEnemyType);
	
	return std::string(temp);
}