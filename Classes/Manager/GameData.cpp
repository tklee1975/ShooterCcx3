//
//  GameData.cpp
//  TapToJump
//
//  Created by Ken Lee on 23/4/15.
//
//

#include "GameData.h"

static GameData *sInstance = NULL;

//#define k
GameData *GameData::instance()
{
	if(sInstance != NULL) {
		return sInstance;
	}
	
	sInstance = new GameData();
	
	return sInstance;
}

GameData::GameData()
: mBestScore(0)
, mLastScore(0)
{
	
}

int GameData::getLastScore()
{
	return mLastScore;
}

int GameData::getBestScore()
{
	return mBestScore;
}

void GameData::setScore(int newScore)
{
	mLastScore = newScore;
	if(mLastScore > mBestScore) {
		mBestScore = mLastScore;
	}
}