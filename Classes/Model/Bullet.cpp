//
//  Bullet.cpp
//  Shooter
//
//  Created by Ken Lee on 28/1/15.
//
//

#include "Bullet.h"
#include "World.h"

Bullet::Bullet()
{
	
}

Bullet::~Bullet()
{
	
}


bool Bullet::init()
{
	if(Model::init() == false) {
		return false;
	}
	
	return true;
}



void Bullet::removeSelfFromWorld()
{
	if(mWorld == NULL) {
		log("Bullet:removeSelfFromWorld: mWorld is NULL");
		return;
	}
	
	mWorld->removeBullet(this);
}

