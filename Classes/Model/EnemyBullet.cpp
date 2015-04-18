//
//  EnemyBullet.cpp
//  Shooter
//
//  Created by Ken Lee on 4/4/15.
//
//

#include "EnemyBullet.h"

EnemyBullet *EnemyBullet::create(const Vec2 &moveDir)
{
	EnemyBullet *bullet = EnemyBullet::create();
	
	bullet->setMoveDir(moveDir);
	
	return bullet;
}

bool EnemyBullet::init()
{
	if(Bullet::init() == false) {
		return false;
	}
	
	this->setTexture("ebullet1.png");
	
	
	mType = Model::Type::Enemy;
	
	
	Size size = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	mMoveDir = Vec2(0, -size.height);		// default
	
	mSpeed = 10;
	
	return true;
}

void EnemyBullet::move()
{
	
	float duration = mSpeed;		// speed
	
	auto move = MoveBy::create(duration, mMoveDir);
	
	auto action = Sequence::create(move, RemoveSelf::create(),
								   CallFunc::create(std::bind(&EnemyBullet::removeSelfFromWorld, this) ),
								   NULL);
	
	this->runAction(action);
}
