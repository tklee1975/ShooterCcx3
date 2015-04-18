//
//  StringHelper.h
//  Shooter
//
//  Created by Ken Lee on 2/2/15.
//
//

#ifndef __Shooter__StringHelper__
#define __Shooter__StringHelper__

#include <stdio.h>
#include <string>

#include "cocos2d.h"

USING_NS_CC;

class StringHelper
{
public:
	static std::string strVec2(const Vec2 &vec2);
	static std::string strRect(const Rect &rect);
	static std::string strSize(const Size &size);
};

#endif /* defined(__Shooter__StringHelper__) */
