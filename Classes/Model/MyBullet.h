//
//  MyBullet.h
//  Shooter
//
//  Created by Ken Lee on 6/2/15.
//
//

#ifndef __Shooter__MyBullet__
#define __Shooter__MyBullet__

#include <stdio.h>
#include "Bullet.h"

class MyBullet : public Bullet
{
public:
	virtual bool init();
	virtual void move() override;
	
public:
	CREATE_FUNC(MyBullet);
};

#endif /* defined(__Shooter__MyBullet__) */
