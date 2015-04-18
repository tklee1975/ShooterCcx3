//
//  CollisionDetector.h
//  Shooter
//
//  Created by Ken Lee on 1/2/15.
//
//

#ifndef __Shooter__CollisionDetector__
#define __Shooter__CollisionDetector__

#include <stdio.h>

#include "Model.h"

class CollisionDetector
{
public:
	static bool checkCollision(Model *bullet, Model * targets);
	static void checkCollision(Model *bullet, Vector<Model *> targets);
	
};
#endif /* defined(__Shooter__CollisionDetector__) */
