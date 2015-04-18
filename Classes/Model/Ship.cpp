//
//  Ship.cpp
//  Shooter
//
//  Created by Ken Lee on 30/1/15.
//
//

#include "Ship.h"
#include "World.h"

Ship::Ship()
{
	
}

Ship::~Ship()
{
	
}


bool Ship::init()
{
	if(Sprite::init() == false) {
		return false;
	}
	

	return true;
}

Rect Ship::getBound()
{
	Rect rect = Sprite::getBoundingBox();
	
	return rect;
}


void Ship::explode()
{
	if(mWorld != NULL) {
		mWorld->addExplosion(this->getPosition());
		mWorld->removeShip(this);
	}
}

