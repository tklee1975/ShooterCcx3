//
//  MyBullet.cpp
//  Shooter
//
//  Created by Ken Lee on 6/2/15.
//
//

#include "MyBullet.h"

bool MyBullet::init()
{
	if(Bullet::init() == false) {
		return false;
	}
	
	this->setTexture("mybullet.png");
	mType = Model::Type::Me;
	
	return true;
}

void MyBullet::move()
{
	Size size = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	Vec2 target = Vec2(0, size.height);
	
	float duration = 4;
	
	auto move = MoveBy::create(duration, target);
	
	auto action = Sequence::create(move, RemoveSelf::create(),
								   CallFunc::create( std::bind(&MyBullet::removeSelfFromWorld, this) ),
								   NULL);
	
	this->runAction(action);
}