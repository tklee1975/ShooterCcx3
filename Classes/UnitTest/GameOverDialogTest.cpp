#ifdef ENABLE_TDD
//
//  GameOverDialogTest.m
//	TDD Framework 
//
//
#include "GameOverDialogTest.h"
#include "TDDHelper.h"
#include "GameOverDialog.h"
#include "GameData.h"

void GameOverDialogTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void GameOverDialogTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void GameOverDialogTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(GameOverDialogTest::subTest);
	SUBTEST(GameOverDialogTest::testOKCancel);
}

#pragma mark -
#pragma mark Sub Test Definition
void GameOverDialogTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
	
	GameData::instance()->setScore(300);
	
	GameOverDialog *dialog = GameOverDialog::create();
	
	addChild(dialog);
}

void GameOverDialogTest::testOKCancel(Ref *sender)
{
	log("this is a sample subTest");
	
	GameOverDialog *dialog = GameOverDialog::create();
	
	addChild(dialog);
	
	dialog->setOKListener(CC_CALLBACK_1(GameOverDialogTest::onOK, this));
	dialog->setCancelListener(CC_CALLBACK_1(GameOverDialogTest::onCancel, this));
}

void GameOverDialogTest::onOK(Ref *sender)
{
	log("OK button is clicked");
}

void GameOverDialogTest::onCancel(Ref *sender)
{
	log("Cancel button is clicked");
}




#endif
