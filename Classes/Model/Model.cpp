//
//  Model.cpp
//  Shooter
//
//  Created by Ken Lee on 1/2/15.
//
//

#include "Model.h"
#include "StringHelper.h"


Model::Model()
: mWorld(NULL)
, mType(Type::Unknown)
, mPadding(Vec2(0, 0))
{

}

void Model::setWorld(World *world)
{
	mWorld = world;
}

Model::Type Model::getType()
{
	return mType;
}

void Model::addBoundLayer()
{
	Rect rect = getBoundingBox();
	LayerColor *layer = LayerColor::create(Color4B(0, 0, 255, 120),
						rect.size.width, rect.size.height);
	layer->setPosition(mPadding.x, mPadding.y);
	addChild(layer);
}

Rect Model::getBoundingBox() const
{
	Rect bound = Sprite::getBoundingBox();
	
	return Rect(bound.getMinX()+mPadding.x,
				bound.getMinY()+mPadding.y,
				bound.size.width - mPadding.x * 2,
				bound.size.height - mPadding.y * 2);
}

void Model::setTexture(const std::string &filename)
{
	Sprite::setTexture(filename);
	// addBoundLayer();
	
	//log("bound=%s", StringHelper::strRect(getBoundingBox()).c_str());
}


bool Model::canCollide() const
{
	return true;
}