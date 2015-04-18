//
//  EnemyLevelLogic.h
//  Shooter
//
//  Created by Ken Lee on 6/4/15.
//
//

#ifndef __Shooter__EnemyLevelLogic__
#define __Shooter__EnemyLevelLogic__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class EnemyShip;

class EnemyLevelLogic
{
public:
	static void createEnemy(int level, Vector<EnemyShip *> &outShipList);
	
};

#endif /* defined(__Shooter__EnemyLevelLogic__) */
