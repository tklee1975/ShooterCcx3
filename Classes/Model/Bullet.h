//
//  Bullet.h
//  Shooter
//
//  Created by Ken Lee on 28/1/15.
//
//

#ifndef __Shooter__Bullet__
#define __Shooter__Bullet__

#include <stdio.h>
#include "cocos2d.h"
#include "Model.h"

USING_NS_CC;


class Bullet : public Model
{
public:
	enum class Type {
		Me,
		Enemy
	};
	
public: // method
	Bullet();
	virtual ~Bullet();
	
	virtual bool init();
	
	//void setXY(int x, int y);
	virtual void move() {} 	// to be override
	
	void removeSelfFromWorld();
	//void explode();
	
};

#endif /* defined(__Shooter__Bullet__) */
