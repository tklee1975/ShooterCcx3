#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "MainScene.h"

USING_NS_CC;

#if COCOS2D_DEBUG == 1
#define DEBUG_MODE 1
#else
#define DEBUG_MODE 0
#endif


AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

void setupResolutionPolicy(float designW, float designH)
{
	GLView *view = Director::getInstance()->getOpenGLView();
	Size screenSize = view->getFrameSize();
	
	float designRatio = designW / designH;
	float screenRatio = screenSize.height / screenSize.width;
	
	ResolutionPolicy resolutionPolicy = screenRatio < designRatio ?
			ResolutionPolicy::FIXED_HEIGHT : ResolutionPolicy::FIXED_WIDTH;
	
	//ResolutionPolicy resolutionPolicy = ResolutionPolicy::EXACT_FIT;
	
	view->setDesignResolutionSize(designW, designH, resolutionPolicy);
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }
	
	// Using Hi-Des
	//Director::getInstance()->setContentScaleFactor(2);
	setupResolutionPolicy(320, 568);

	// Setup and configuration
	FileUtils::getInstance()->addSearchPath("image");
	FileUtils::getInstance()->addSearchPath("gui");
	FileUtils::getInstance()->addSearchPath("sound");
	
    // turn on display FPS
    director->setDisplayStats(DEBUG_MODE == 1);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 30);

    // create a scene. it's an autorelease object
    //auto scene = HelloWorld::createScene();
	auto scene = MainSceneLayer::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
