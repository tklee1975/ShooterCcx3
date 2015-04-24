//
//  MyShip.cpp
//  Shooter
//
//  Created by Ken Lee on 9/2/15.
//
//

#include "MyShip.h"
#include "MyBullet.h"
#include "World.h"

#define kSpeed			110
#define kFireInterval	0.5



bool MyShip::init()
{
	if(Ship::init() == false) {
		return false;
	}
	
	mPadding = Vec2(5, 0);
	
	// Spawning handling
	mIsSpawning = true;
	setOpacity(150);
	mSpawnCountDown = 3.0f;	// 3 seconds

	
	this->setTexture("myship.png");
	mType = Model::Type::Me;
	mFireFlag = false;
	mFireCountdown = kFireInterval;
	return true;
}

void MyShip::update(float delta)
{
	
	
	handleSpawning(delta);
	
	// Update the ship position
	// log("update: delta=%f", delta);
	//updatePosition(delta);
	handleAutoFire(delta);
}

void MyShip::handleSpawning(float delta)
{
	if(mIsSpawning == false) {
		return;
	}
	
	mSpawnCountDown -= delta;
	
	if(mSpawnCountDown > 0) {
		return;
	}
	
	mIsSpawning = false;
	setOpacity(255);
}

void MyShip::handleAutoFire(float delta)
{
	if(mFireFlag == false) {
		return;
	}
	
	if(mIsSpawning == true) {
		return;
	}
	
	// handle count down first
	mFireCountdown -= delta;
	
	
	if(mFireCountdown > 0) {
		return;
	}
	
	fire();
	
	mFireCountdown = kFireInterval;
}

void MyShip::updatePosition(float delta)
{
	if(mDir == MoveDirNone) {
		return;
	}
	
	Vec2 current = getPosition();
	
	float deltaX = mDir * delta * kSpeed;
	float newX = current.x + deltaX;
	
	if(newX < 0) {
		newX = 0;
	}else if(newX > 280) {
		newX = 280;
	}
	
	setPositionX(newX);
}


void MyShip::changeDir(MoveDir dir)
{
	mDir = dir;
}


void MyShip::fire()
{
	// Need to bind the World Model to continue the logic
	if(mWorld == NULL) {
		return;
	}
	
	MyBullet *bullet = MyBullet::create();
	
	Vec2 pos = this->getPosition();
	Size size = this->getContentSize();
	pos.y += size.height / 2 + 10;
	
	mWorld->addBullet(bullet, pos);
	
	mWorld->playSound(SOUND_FIRE);
}

bool MyShip::canCollide() const
{
	return mIsSpawning == false;
}