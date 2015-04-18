//
//  StringHelper.cpp
//  Shooter
//
//  Created by Ken Lee on 2/2/15.
//
//

#include "StringHelper.h"


std::string StringHelper::strVec2(const Vec2 &vec2)
{
	char temp[100];
	
	sprintf(temp, "(%.0f, %.0f)", vec2.x, vec2.y);
	
	
	return std::string(temp);
}

std::string StringHelper::strRect(const Rect &rect)
{
	char temp[100];
	
	sprintf(temp, "(%.0f, %.0f, %.0f, %.0f)",
						rect.getMinX(), rect.getMinY(),
						rect.getMaxX(), rect.getMaxY());
	
	
	return std::string(temp);
}

std::string StringHelper::strSize(const Size &size)
{
	char temp[100];
	
	sprintf(temp, "(%.0f, %.0f)", size.width, size.height);
	
	return std::string(temp);
	
}