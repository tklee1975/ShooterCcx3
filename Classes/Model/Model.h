//
//  Model.h
//  Shooter
//
//  Created by Ken Lee on 1/2/15.
//
//

#ifndef __Shooter__Model__
#define __Shooter__Model__

#include <stdio.h>
#include "cocos2d.h"

class World;

USING_NS_CC;

class Model : public Sprite
{
public:
	enum class Type {
		Me,
		Enemy,
		Unknown
	};
	
	
public:
	Model();
	
	void setWorld(World *world);
	void getHit();				// This Model get hit
	void destroy();				// This model being destory
	void spawn();				// This model being spawn
	Type getType();
	virtual Rect getBoundingBox() const;
	virtual void setTexture(const std::string &filename);
	void addBoundLayer();
	virtual bool canCollide() const;

protected:
	World *mWorld;		// the world holding this model
	Type mType;
	Vec2 mPadding;
	LayerColor *mBoundLayer;
	//virtual Rect getBound() = 0;
};

#endif /* defined(__Shooter__Model__) */
