//
//  MyShip.h
//  Shooter
//
//  Created by Ken Lee on 9/2/15.
//
//

#ifndef __Shooter__MyShip__
#define __Shooter__MyShip__

#include <stdio.h>
#include "Ship.h"
#include "Constants.h"

class MyShip : public Ship
{
public:
	virtual bool init();
	
	void changeDir(MoveDir dir);
	
	virtual void update(float delta) override;
	
	virtual void fire() override;
	virtual bool canCollide() const;
	
	
public:
	CREATE_FUNC(MyShip);
	CC_SYNTHESIZE(bool, mFireFlag, AutoFire);
	
private:
	void updatePosition(float delta);
	void handleAutoFire(float delta);
	void handleSpawning(float delta);
	
private:
	MoveDir mDir;
	bool mIsSpawning;
	float mFireCountdown;
	float mSpawnCountDown;
};
#endif /* defined(__Shooter__MyShip__) */
