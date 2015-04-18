//
//  Ship.h
//  Shooter
//
//  Created by Ken Lee on 30/1/15.
//
//

#ifndef __Shooter__Ship__
#define __Shooter__Ship__

#include <stdio.h>
#include "cocos2d.h"

#include "Model.h"

USING_NS_CC;
class Ship : public Model
{
	
	
public: // method
	Ship();
	virtual ~Ship();
	
	virtual bool init();
	
	//void setXY(int x, int y);
	void move();
	virtual void fire() {}
	void explode();
	
	virtual Rect getBound();
	
	CREATE_FUNC(Ship);
private: // member
};
#endif /* defined(__Shooter__Ship__) */
