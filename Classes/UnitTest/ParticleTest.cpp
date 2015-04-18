#ifdef ENABLE_TDD
//
//  ParticleTest.m
//	TDD Framework 
//
//
#include "ParticleTest.h"
#include "TDDHelper.h"

void ParticleTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void ParticleTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void ParticleTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(ParticleTest::subTest);
	SUBTEST(ParticleTest::testBuildInExplosion);
}

#pragma mark -
#pragma mark Sub Test Definition
void ParticleTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
	
	std::string filename = "particle/explosion.plist";
	
	ParticleSystemQuad *emitter = ParticleSystemQuad::create(filename);
	emitter->setPosition(Vec2(150, 200));
	emitter->setScale(0.5);
	
	addChild(emitter);
}

void ParticleTest::testBuildInExplosion(Ref *sender)
{
	log("this is a sample subTest");
	
	ParticleSystemQuad *emitter = ParticleExplosion::create();
	emitter->setAutoRemoveOnFinish(true);
	emitter->setPosition(Vec2(150, 200));
	emitter->setScale(0.5);
	
	addChild(emitter);
}


#endif
