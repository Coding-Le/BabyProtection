#include "ScrollViewScene.h"
#include "ScrollView.h"
#include "TestLayer.h"
#include "parentMode.h"
ScrollViewScene::ScrollViewScene()
{
}

ScrollViewScene::~ScrollViewScene()
{
}

bool ScrollViewScene::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//ScrollView::setWindow(480, 320);
	bool bRet = false;
	do {
		CC_BREAK_IF(!CCScene::init());

		ScrollView *scrollView = ScrollView::create();
		Schedule();
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		for (int i = 0; i<10; ++i) {
			auto *layer = TestLayer::create();
			layer->addimage(i);
			layer->setAnchorPoint(Vec2::ZERO);
			layer->setTag(i);
			scrollView->addPage(layer);
		}

		this->addChild(scrollView, 1);
		ScrollView::setWindow(winSize.width * 0.25f, winSize.height * 0.5f, visibleSize.height / 2);
		scrollView->setPosition(Vec2(0, visibleSize.height / 2));
		//scrollView->setPosition(Vec2(0, visibleSize.height - ScrollView::WINDOW_HEIGHT));
		//ScrollView::setWindow(480, 320, visibleSize.height / 2);
		//scrollView->setPosition(Vec2(0, visibleSize.height / 2));
		//
		//ScrollView::WINDOW_HEIGHT / 2

		auto bg = Sprite::create("res/bg.png");
		float odds;
		float oddsY;
		oddsY = bg->getContentSize().height / visibleSize.height;
		odds = bg->getContentSize().width / visibleSize.width;
		bg->setScaleY(1 / oddsY);
		bg->setScaleX(1 / odds);
		this->addChild(bg, 0);
		bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

		bRet = true;
	} while (0);


	/*auto back = MenuItemImage::create("timeset/back.png", "timeset/back.png", CC_CALLBACK_1(ScrollViewScene::returnto, this));
	auto back_menu = Menu::create(back, NULL);
	back_menu->setPosition(Vec2(back->getContentSize().width, visibleSize.height - back->getContentSize().height));
	this->addChild(back_menu, 3);*/


	return bRet;
}

void ScrollViewScene::returnto(Ref* ref)
{
	this->stopAllActions();
	auto scene = parentMode::createScene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
}


void ScrollViewScene::girlwalk() {}


void ScrollViewScene::updateTime1(float dt){
	totalTime1 += dt;
	
}
void ScrollViewScene::Schedule() {
	schedule(schedule_selector(ScrollViewScene::updateTime1), 0.1f);
}