//
//  EnemyShip.h
//  Shooter
//
//  Created by Ken Lee on 6/2/15.
//
//

#ifndef __Shooter__EnemyShip__
#define __Shooter__EnemyShip__

#include <stdio.h>

#include "Ship.h"

class EnemyShip : public Ship
{
	
public:
	enum class EnemyType {
		Normal,
		Angry,
	};
	
public:
	virtual bool init();
	virtual bool init(EnemyType enemyType, int level);
	virtual void update(float delta) override;
	virtual void fire() override;

	CC_SYNTHESIZE(bool, mAttackFlag, AttackMode);
	CC_SYNTHESIZE(EnemyType, mEnemyType, EnemyType);
	
	std::string toString();
	
public:
	CREATE_FUNC(EnemyShip);
	static EnemyShip *create(EnemyType enemyType, int level);
	
private:
	void attackLogic(float delta);
	Vec2 getMoveToPlayerDir();
	void setupLevel();
	
private:
	int mLevel;
	float mRechargeTime;				//
	int mBulletSpeed;				// smaller, the faster
	int mBullet;					// number of bullet
	bool mBulletChase;				// Bullet Chase the player?
	
	int mRemainBullet;				// number of bullet remar
	float mTimeToNextRecharge;		// time to recharge
	float mTimeToAttack;			// time to next attack
};
#endif /* defined(__Shooter__EnemyShip__) */
