//
//  World.h
//  Shooter
//
//  Created by Ken Lee on 2/2/15.
//
//

#ifndef __Shooter__World__
#define __Shooter__World__

#include <stdio.h>
#include "cocos2d.h"
#include "Model.h"
#include "MyShip.h"

USING_NS_CC;

#define SOUND_FIRE				"shot.mp3"
#define SOUND_EXPLORE_ME		"me-explode.mp3"
#define SOUND_EXPLORE_OTHER		"enemy-explode.mp3"
#define SOUND_LEVEL_COMPLETE	"level-complete.mp3"

class Bullet;
class Ship;
class EnemyShip;

class World : public cocos2d::LayerColor
{
public: // Type and Enum
	enum class WorldEvent {
		HitMonster1 = 1,
		HitMonster2 = 2,
		PlayerDie = 3,
		LevelClear = 4,
	};
	
	enum class WorldState {
		NotStart,
		Starting,
		Running,
		WaitForNextLevel,
	};

	typedef std::function<void(Ref *, WorldEvent)> Callback;
	
public:
	// implement the "static create()" method manually
	CREATE_FUNC(World);
	static World *instance();
	
public:
	virtual bool init();
	void reset();
	void preloadSounds();
	void playSound(const char *file);
	
	virtual void update(float delta) override;

	void addBullet(Bullet *bullet, const Vect &from);
	void addShip(Ship *ship, const Vect &pos);
	
	void removeModel(Model *model);
	void removeBullet(Bullet *bullet);
	void removeShip(Ship *ship);
	void addExplosion(const Vec2 &position);
	void generateLevel(int level);
	
	void spawnEnemy(const Vec2 &pos, int level);
	void spawnMyShip();
	void removeAllEnemies();
	
	int getEnemyCount();
	
	std::string info() const;
	
	void setupTouchListener();
	
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	void onTouchEnded(Touch *touch, Event *event);

	void handleMyShipMove();
	
	void setCallback(const Callback &callback);
	void sendEvent(WorldEvent event);
	void startWorld();
	
	
	CC_SYNTHESIZE_RETAIN(MyShip *, mMyShip, MyShip);

private:
	void addModel(Model *model, const Vec2 &pos);
	void checkBulletCollision();
	void setupBounds();
	void sendEvent(Event event);
	void removeMyShip(MyShip *ship);
	void removeEnemyShip(EnemyShip *ship);
	
	
private:
	// game models
	Vector<Model *> mEnemies;		// Set of Enemy Ship
	Vector<Model *> mMyBullets;		//
	Vector<Model *> mEnemyBullets;

	// callback
	Callback mCallback;
	
	// touch
	Vec2 mLastTouchPos;
	Vec2 mNewTouchPos;
	
	// bounds
	Rect mMyShipBound;
	Rect mWorldBound;
	
	// Layer to indicate the bound
	LayerColor *mShipBoundLayer;	// a layer tell the bound of the ship
	LayerColor *mWorldBoundLayer;	// a layer tell the bound of the ship
	
	WorldState mState;
};
#endif /* defined(__Shooter__World__) */
