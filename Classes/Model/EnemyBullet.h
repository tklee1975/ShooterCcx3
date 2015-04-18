//
//  EnemyBullet.h
//  Shooter
//
//  Created by Ken Lee on 4/4/15.
//
//

#ifndef __Shooter__EnemyBullet__
#define __Shooter__EnemyBullet__

#include <stdio.h>
#include "Bullet.h"


class EnemyBullet : public Bullet
{
public:
	virtual bool init();
	virtual void move() override;
	
public:
	
	// Creation method
	CREATE_FUNC(EnemyBullet);
	static EnemyBullet *create(const Vec2 &moveDir);
	
	CC_SYNTHESIZE(Vec2, mMoveDir, MoveDir);
	CC_SYNTHESIZE(float, mSpeed, Speed);
};
#endif /* defined(__Shooter__EnemyBullet__) */
