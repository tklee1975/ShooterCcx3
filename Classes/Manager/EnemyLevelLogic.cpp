//
//  EnemyLevelLogic.cpp
//  Shooter
//
//  Created by Ken Lee on 6/4/15.
//
//

#include "EnemyLevelLogic.h"
#include "EnemyShip.h"

#define kMarginX	20
#define kMarginY	30
#define kNumPerRow	6
#define kRowHeight	40

// Local functions
namespace  {
	std::string getLevelPattern(int level) {
		int modLevel = (level-1) % 5;
		
		switch (modLevel) {
			case 0		: return "AAAAAA";
			case 1		: return "ABAAAB";
			case 2		: return "BBBBBB"
				                 "AAAAAA";
			case 3		: return "BBBBBB"
								 "AAAAAA"
								 "AAAAAA";
			case 4		: return "BBBBBB"
								 "BBBBBB"
								 "AAAAAA"
								 "AAAAAA";
			default		: return "BBBBBB";
		}
	}
}

//

void EnemyLevelLogic::createEnemy(int level, Vector<EnemyShip *> &outShipList)
{
	std::string data = getLevelPattern(level);
	
	Size screenSize = Director::getInstance()->getWinSize();
	
	
	float unitW = (screenSize.width - kMarginX * 2) / kNumPerRow;
	
	// log("debug: screenSize: %f,%f unitW=%f", screenSize.width, screenSize.height, unitW);
	
	float firstX = kMarginX + unitW / 2;
	float firstY = screenSize.height - kMarginY - kRowHeight / 2;
	
	int numRow = (int)( data.length() / kNumPerRow);
	
	long dataLen = data.length();
	Vec2 pos = Vec2(firstX, firstY);

	int idx = 0;
	
	for(int j = 0; j < numRow; j++) {
		for(int i = 0; i < kNumPerRow; i++) {
			char ch = data[idx % dataLen];
			
			EnemyShip *ship;
			if(ch == ' ') {
				ship = NULL;
			} else {
				EnemyShip::EnemyType enemyType = ch == 'A' ?
					EnemyShip::EnemyType::Normal : EnemyShip::EnemyType::Angry;
				ship = EnemyShip::create(enemyType, level);
				ship->setPosition(pos);
			}
			
			if(ship != NULL) {
				outShipList.pushBack(ship);
			}
			
			pos.x += unitW;
			idx++;
		}
		
		pos.x = firstX;
		pos.y -= kRowHeight;
	}
}

