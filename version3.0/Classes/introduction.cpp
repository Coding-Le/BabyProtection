#include "introduction.h"
#include "parentMode.h"
#pragma execution_character_set("utf-8")
USING_NS_CC;
#define H_PI 1.570796327f
//#include "FlowWord.h"
#include "DropDownList.h"
#include "Timeset.h"
#include"HelloWorldScene.h"
#include"parentstudy.h"
Scene* introduction::createScene(){
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = introduction::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool introduction::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	dispatcher = Director::getInstance()->getEventDispatcher();

	auto background = Sprite::create("parent_read/about_us.png");
	auto x = visibleSize.width / background->getContentSize().width;
	auto y = visibleSize.height / background->getContentSize().height;
	background->setScale(x, y);
	background->setAnchorPoint(Vec2::ZERO);
	background->setPosition(Vec2::ZERO);
	this->addChild(background, 1);

	auto taglabel = Sprite::create("parentmode/44.png");
	float xx = visibleSize.width / taglabel->getContentSize().width;
	float yy = visibleSize.height / taglabel->getContentSize().height;
	taglabel->setScale(xx / 2, yy);
	taglabel->setAnchorPoint(Vec2::ZERO);
	taglabel->setPosition(Vec2::ZERO);
	this->addChild(taglabel, 5);

	auto back = MenuItemImage::create("timeset/back.png", "timeset/back.png", CC_CALLBACK_1(introduction::returnto, this));
	back->setScale(0.2*visibleSize.height / back->getContentSize().height);
	auto back_menu = Menu::create(back, NULL);
	back_menu->setPosition(Vec2(back->getBoundingBox().size.width / 2, visibleSize.height - back->getBoundingBox().size.height / 2));
	this->addChild(back_menu, 3);

	testTouchEvent();

	return true;
}


void introduction::CallbackShowMenu(Ref* sender)
{
	this->setPosition(-100, this->getPosition().y);
}


void introduction::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void introduction::returnto(Ref* ref)
{
	this->stopAllActions();
	auto scene = HelloWorld::createScene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
}

void introduction::testTouchEvent()
{
	streak = MotionStreak::create(0.5f, 10, 30, Color3B::WHITE, "Demo/flash.png");
	this->addChild(streak, 2);
	visibleSize = Director::getInstance()->getVisibleSize();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event){
		touch_pos = touch->getLocation();
		if (touch_pos.x > 0 && touch_pos.x < visibleSize.width / 2 * 4.2 / 17.64) {
			if (touch_pos.y > visibleSize.height / 14.1*9.1 && touch_pos.y < visibleSize.height / 14.1*10.55) {
				this->stopAllActions();
				auto scene = parentMode::createScene();
				CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
			}
			else if (touch_pos.y > visibleSize.height / 14.1*7.65 && touch_pos.y < visibleSize.height / 14.1*9.1) {
				this->stopAllActions();
				auto scene = Timeset::createScene();
				CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
			}
			else if (touch_pos.y > visibleSize.height / 14.1*6.24 && touch_pos.y < visibleSize.height / 14.1*7.65) {
				this->stopAllActions();
				auto scene = parentstudy::createScene();
				CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
			}
			else if (touch_pos.y > visibleSize.height / 14.1*4.75 && touch_pos.y < visibleSize.height / 14.1*6.24) {

			}
		}


		return true;
	};

	listener->onTouchMoved = [&](Touch* touch, Event* event){

	};

	listener->onTouchEnded = [&](Touch* touch, Event* event){
		log("onTouchEnded");
	};
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}


bool introduction::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	return true;
}

void introduction::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

void introduction::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{

}