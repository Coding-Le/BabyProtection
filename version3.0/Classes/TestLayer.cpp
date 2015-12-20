#include "TestLayer.h"
#include "ScrollView.h"
#include "beforezoo.h"
TestLayer::TestLayer()
{
}

TestLayer::~TestLayer()
{
}

bool TestLayer::init()
{
	return true;
}
bool TestLayer::addimage(int flag) {
	bool bRet = false;

	do {
		CC_BREAK_IF(!LayerColor::initWithColor(ccc4(255, 255, 255, 255)));

		setContentSize(CCSizeMake(ScrollView::WINDOW_WIDTH, ScrollView::WINDOW_HEIGHT));
		this->setOpacity(25);
		bRet = true;
	} while (0);
	if (flag < 1) {
		auto sp = Sprite::create("res/level1.png");
		this->addChild(sp);
		sp->setPosition(Vec2(ScrollView::WINDOW_WIDTH / 2, ScrollView::WINDOW_HEIGHT / 2));
	}
	else {
		auto sp = Sprite::create("res/lock.png");
		this->addChild(sp);
		sp->setPosition(Vec2(ScrollView::WINDOW_WIDTH / 2, ScrollView::WINDOW_HEIGHT / 2));
	}

	return bRet;
}
void TestLayer::onEnter()
{
	CCLayer::onEnter();
	/*auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TestLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(TestLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(TestLayer::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(TestLayer::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);*/
	//CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}

void TestLayer::onExit()
{
	//CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	_eventDispatcher->removeEventListenersForTarget(this);
	CCLayer::onExit();
}

bool TestLayer::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
	
	return true;
}


void TestLayer::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
}

void TestLayer::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
}

void TestLayer::onTouchCancelled(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
}
