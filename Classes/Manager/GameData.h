//
//  GameData.h
//  Shooter
//
//  Created by Ken Lee on 23/4/15.
//
//

#ifndef __Shooter__GameData__
#define __Shooter__GameData__

#include <stdio.h>
class GameData
{
public: // Type and Enum
	static GameData *instance();
	
	void setScore(int newScore);
	int getLastScore();
	int getBestScore();
	
private:
	GameData();
	
private:
	int mBestScore;
	int mLastScore;
};
#endif /* defined(__Shooter__GameData__) */
