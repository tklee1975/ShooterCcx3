#ifdef ENABLE_TDD
//
//  CallbackTest.m
//	TDD Framework 
//
//
#include "CallbackTest.h"
#include "TDDHelper.h"

// Testing Functions for this test
void sumTwo(int a, int b)
{
	int sum = a + b;
	
	log("%d + %d = %d", a, b, sum);
}


// Testing Class
class TestLayer : public LayerColor
{
public:
	typedef std::function<void(Ref *, int value)> TestLayerCallback;
	
public:
	CREATE_FUNC(TestLayer);
	virtual bool init();
	void setCallback(const TestLayerCallback &callback);
	
private:
	void onButtonClicked(Ref *sender);
	
private:
	TestLayerCallback mCallback;
};



bool TestLayer::init()
{
	bool isOk = LayerColor::initWithColor(Color4B::BLUE, 100, 80);
	if (isOk == false)
	{
		return false;
	}
	
	mCallback = nullptr;
	
	Label *label = Label::createWithSystemFont("Press Me", "arial", 14);
	
	// typedef std::function<void(Ref*)> ccMenuCallback;
	auto pressButton = MenuItemLabel::create(label, CC_CALLBACK_1(TestLayer::onButtonClicked, this));
	
	auto menu = Menu::create(pressButton, NULL);
	menu->setPosition(Vec2(50, 40));
	this->addChild(menu, 1);
	
	return true;
}

void TestLayer::onButtonClicked(Ref *sender)
{
	log("hello!");
	if(mCallback != nullptr) {
		mCallback(this, 1000);
	}
}

void TestLayer::setCallback(const TestLayerCallback &callback)
{
	mCallback = callback;
}


//
void CallbackTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void CallbackTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void CallbackTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(CallbackTest::testStdFunc);
	SUBTEST(CallbackTest::testLayerCallback);
	SUBTEST(CallbackTest::testCallBack2);
}

#pragma mark -
#pragma mark Sub Test Definition
void CallbackTest::testStdFunc(Ref *sender)
{
	log("this is a std::fuction");
	// Reference: http://en.cppreference.com/w/cpp/utility/functional/function
	
	// Using function call
	std::function<void(int, int)> funcSum = sumTwo;		// --> Point to a global function
	funcSum(10, 30);
	
	// binded function
	std::function<void()> sum20_30 = std::bind(sumTwo, 20, 30);
	sum20_30();
}


void CallbackTest::testLayerCallback(Ref *sender)
{
	TestLayer *layer = TestLayer::create();
	
	layer->setPosition(Vec2(100, 200));
	
	const TestLayer::TestLayerCallback callback = [](Ref *, int value) {
						log("Callback is called. value=%d", value);
				};
	layer->setCallback(callback);
	
	addChild(layer);
}

void CallbackTest::handleCallback(Ref *sender, int value)
{
	log("handleCallback: value=%d", value);
}

void CallbackTest::testCallBack2(Ref *sender)
{
	TestLayer *layer = TestLayer::create();
	
	layer->setPosition(Vec2(100, 200));
	
	TestLayer::TestLayerCallback callback = CC_CALLBACK_2(CallbackTest::handleCallback, this);
	layer->setCallback(callback);
	
	addChild(layer);
}


#endif
