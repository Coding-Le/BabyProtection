#include"Timeset.h"
#include"parentMode.h"
#pragma execution_character_set("utf-8")
USING_NS_CC;
#define H_PI 1.570796327f
//#include"FlowWord.h"
#include"HelloWorldScene.h"
#include"parentstudy.h"
#include "DropDownList.h"
#include"introduction.h"
Scene* Timeset::createScene(){
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Timeset::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool Timeset::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	dispatcher = Director::getInstance()->getEventDispatcher();

	auto background = Sprite::create("parent_read/background.png");
	x = visibleSize.width / background->getContentSize().width;
	y = visibleSize.height / background->getContentSize().height;
	background->setScale(x, y);
	background->setAnchorPoint(Vec2::ZERO);
	background->setPosition(Vec2::ZERO);
	this->addChild(background);
	flag = 0;
	flag2 = 0;
	timeshadow = Sprite::create("parent_read/time_shadow.png");
	timeshadow->setScale(visibleSize.width / 38 * 4.3 / timeshadow->getContentSize().width * 120 / 80, visibleSize.height / 19 * 1.9 / timeshadow->getContentSize().height * 50 / 36);
	timeshadow->setPosition(visibleSize.width / 38 * 26.53, visibleSize.height / 19 * 9.1);
	addChild(timeshadow);

    
	shadow = Sprite::create("parent_read/shadow.png");
	shadow->setScale(visibleSize.width / 38 * 6.5 * 200 / 120 / shadow->getContentSize().width, visibleSize.height / 19 * 1.95 * 80 / 32 / shadow->getContentSize().height);
	shadow->setPosition(visibleSize.width / 38 * 25.55, visibleSize.height / 19 * 4.9);
	addChild(shadow);

	taglabel = Sprite::create("parentmode/22.png");
	float xx = visibleSize.width / taglabel->getContentSize().width;
	float yy = visibleSize.height / taglabel->getContentSize().height;
	taglabel->setScale(xx / 2, yy);
	taglabel->setAnchorPoint(Vec2::ZERO);
	taglabel->setPosition(Vec2::ZERO);
	this->addChild(taglabel);
	/*auto panel = Sprite::create("timeset/set.png");
	panel->setPosition(visibleSize.width / 2, visibleSize.height-panel->getContentSize().height/2);
	this->addChild(panel, 2);

	auto label2 = Label::createWithTTF("游戏时间", "fonts/my_font3.ttf", 48);
	label2->setPosition(Vec2(visibleSize.width / 2-panel->getContentSize().width/2-label2->getContentSize().width/2, visibleSize.height - panel->getContentSize().height*2));
	this->addChild(label2, 3);


	auto label3 = Label::createWithTTF("护眼模式", "fonts/my_font3.ttf", 48);
	label3->setPosition(Vec2(visibleSize.width / 2 - panel->getContentSize().width / 2 - label3->getContentSize().width / 2, panel->getPosition().y - panel->getContentSize().height * 5));
	this->addChild(label3, 3);

	auto level_1 = MenuItemImage::create("timeset/5.png", "timeset/5.png", CC_CALLBACK_1(Timeset::Level_1, this));
	auto menu = Menu::create(level_1, NULL);
	menu->setPosition(Vec2(label2->getPosition().x+1.5*level_1->getContentSize().width, label2->getPosition().y));
	this->addChild(menu, 3);

	auto level_2 = MenuItemImage::create("timeset/20.png", "timeset/20.png", CC_CALLBACK_1(Timeset::Level_1, this));
	auto menu2 = Menu::create(level_2, NULL);
	menu2->setPosition(Vec2(label2->getPosition().x + 1.5*level_1->getContentSize().width, label2->getPosition().y - panel->getContentSize().height));
	this->addChild(menu2, 3);

	auto level_3 = MenuItemImage::create("timeset/no.png", "timeset/no.png", CC_CALLBACK_1(Timeset::Level_1, this));
	auto menu3 = Menu::create(level_3, NULL);
	menu3->setPosition(Vec2(label2->getPosition().x + 1.5*level_1->getContentSize().width, label2->getPosition().y - 2*panel->getContentSize().height));
	this->addChild(menu3, 3);

	auto level_4 = MenuItemImage::create("timeset/open.png", "timeset/open.png", CC_CALLBACK_1(Timeset::Level_1, this));
	auto menu4 = Menu::create(level_4, NULL);
	menu4->setPosition(Vec2(label2->getPosition().x + 1.7*level_1->getContentSize().width, label3->getPosition().y));
	this->addChild(menu4, 3);

	auto level_5 = MenuItemImage::create("timeset/close.png", "timeset/close.png", CC_CALLBACK_1(Timeset::Level_1, this));
	auto menu5 = Menu::create(level_5, NULL);
	menu5->setPosition(Vec2(label2->getPosition().x + 2.7*level_5->getContentSize().width, label3->getPosition().y));
	this->addChild(menu5, 3);*/


	auto back = MenuItemImage::create("timeset/back.png", "timeset/back.png", CC_CALLBACK_1(Timeset::returnto, this));
	back->setScale(0.2*visibleSize.height / back->getContentSize().height);
	auto back_menu = Menu::create(back, NULL);
	back_menu->setPosition(Vec2(back->getBoundingBox().size.width / 2, visibleSize.height - back->getBoundingBox().size.height / 2));
	this->addChild(back_menu, 3);

	auto close_item = MenuItemImage::create("CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(Timeset::menuCloseCallback,
		this));
	close_item->setPosition(
		Vec2(origin.x + visibleSize.width - close_item->getContentSize().width / 2,
		origin.y + close_item->getContentSize().height / 2));
	// create menu, it's an autorelease object
	auto mymenu = Menu::create(close_item, NULL);
	mymenu->setPosition(Vec2::ZERO);
	this->addChild(mymenu, 1);
	
	testTouchEvent();



	return true;
}
void Timeset::Level_1(Ref* ref)
{

}

void Timeset::returnto(Ref* ref)
{
	this->stopAllActions();
	auto scene = HelloWorld::createScene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
}

void Timeset::CallbackShowMenu(Ref* sender)
{
	this->setPosition(-100, this->getPosition().y);
}

void Timeset::menuCloseCallback(Ref* pSender)
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

void Timeset::testTouchEvent()
{
	streak = MotionStreak::create(0.5f, 10, 30, Color3B::WHITE, "Demo/flash.png");
	this->addChild(streak, 2);
	visibleSize = Director::getInstance()->getVisibleSize();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event){
		touch_pos = touch->getLocation();
		auto high = visibleSize.height*y;
		auto length = visibleSize.width*x;
		if (touch_pos.x > 0 && touch_pos.x < visibleSize.width / 2 * 4.2 / 17.64) {
			if (touch_pos.y > visibleSize.height / 14.1*9.1 && touch_pos.y < visibleSize.height / 14.1*10.55) {
				this->stopAllActions();
				auto scene = parentMode::createScene();
				CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
			}
			else if (touch_pos.y > visibleSize.height / 14.1*7.65 && touch_pos.y < visibleSize.height / 14.1*9.1) {

			}
			else if (touch_pos.y > visibleSize.height / 14.1*6.24 && touch_pos.y < visibleSize.height / 14.1*7.65) {
				this->stopAllActions();
				auto scene = parentstudy::createScene();
				CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
			}
			else if (touch_pos.y > visibleSize.height / 14.1*4.75 && touch_pos.y < visibleSize.height / 14.1*6.24) {
				this->stopAllActions();
				auto scene = introduction::createScene();
				CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
			}
		}


		if (touch_pos.y >= visibleSize.height / 19 * 4 && touch_pos.y <= visibleSize.height / 19 * 6) {
			if (touch_pos.x >= visibleSize.width / 38 * 14 && touch_pos.x <= visibleSize.width / 38 * 20.5) {
				if (flag == 0) {
					flag = 1;
					testshadow = Sprite::create("parent_read/eye.png");
					testshadow->setScale(visibleSize.width / testshadow->getContentSize().width, visibleSize.height / testshadow->getContentSize().height);
					testshadow->setAnchorPoint(Vec2::ZERO);
					testshadow->setPosition(Vec2::ZERO);
					this->addChild(testshadow);
				}
				shadow->setVisible(false);
				this->removeChild(shadow);
				shadow = Sprite::create("parent_read/shadow.png");
				shadow->setPosition(visibleSize.width/38*17.25,visibleSize.height/19*4.9);
				shadow->setScale(visibleSize.width / 38 * 6.5 * 200 / 120 / shadow->getContentSize().width, visibleSize.height / 19 * 1.95 * 80 / 32 / shadow->getContentSize().height);
				addChild(shadow);
			}
			else if (touch_pos.x >= visibleSize.width / 38 * 22.3 && touch_pos.x <= visibleSize.width / 38 * 28.8) {
				if (flag == 1) {
					testshadow->setVisible(false);
					this->removeChild(testshadow);
					flag = 0;
				}
				shadow->setVisible(false);
				this->removeChild(shadow);
				shadow = Sprite::create("parent_read/shadow.png");
				timeshadow->setScale(visibleSize.width/38*4.3/timeshadow->getContentSize().width*120/80,visibleSize.height/19*1.9/timeshadow->getContentSize().height*50/36);
				shadow->setScale(visibleSize.width/38*6.5*200/120/shadow->getContentSize().width, visibleSize.height/19*1.95*80/32/shadow->getContentSize().height);
				shadow->setPosition(visibleSize.width/38*25.55, visibleSize.height/19*4.9);
				addChild(shadow);
			}
		}
		else if (touch_pos.y >= visibleSize.height / 19 * 11.5 && touch_pos.y <= visibleSize.height / 19 * 13.3) {
			if (touch_pos.x >= visibleSize.width / 38 * 13.95 && touch_pos.x <= visibleSize.width / 38 * 18.1) {
				timeshadow->setVisible(false);
				this->removeChild(timeshadow);
				timeshadow = Sprite::create("parent_read/time_shadow.png");
				timeshadow->setScale(visibleSize.width/38*4.3/timeshadow->getContentSize().width*120/80,visibleSize.height/19*1.9/timeshadow->getContentSize().height*50/36);
				timeshadow->setPosition(visibleSize.width/38*15.95,visibleSize.height/19*12.35);
				addChild(timeshadow);
			}
			else if (touch_pos.x >= visibleSize.width / 38 * 19.05 && touch_pos.x <= visibleSize.width / 38 * 23.25) {
				timeshadow->setVisible(false);
				this->removeChild(timeshadow);
				timeshadow = Sprite::create("parent_read/time_shadow.png");
				timeshadow->setScale(visibleSize.width / 38 * 4.3 / timeshadow->getContentSize().width * 120 / 80, visibleSize.height / 19 * 1.9 / timeshadow->getContentSize().height * 50 / 36);
				timeshadow->setPosition(visibleSize.width / 38 * 21.1, visibleSize.height / 19 * 12.35);
				addChild(timeshadow);
			}
			else if (touch_pos.x >= visibleSize.width / 38 * 24.5 && touch_pos.x <= visibleSize.width / 38 * 28.75) {
				timeshadow->setVisible(false);
				this->removeChild(timeshadow);
				timeshadow = Sprite::create("parent_read/time_shadow.png");
				timeshadow->setScale(visibleSize.width / 38 * 4.3 / timeshadow->getContentSize().width * 120 / 80, visibleSize.height / 19 * 1.9 / timeshadow->getContentSize().height * 50 / 36);
				timeshadow->setPosition(visibleSize.width / 38 * 26.53, visibleSize.height / 19 * 12.35);
				addChild(timeshadow);
			}
		}
		else if (touch_pos.y >= visibleSize.height / 19 * 8.3 && touch_pos.y <= visibleSize.height / 19 * 10.05) {
			if (touch_pos.x >= visibleSize.width / 38 * 13.95 && touch_pos.x <= visibleSize.width / 38 * 18.1) {
				timeshadow->setVisible(false);
				this->removeChild(timeshadow);
				timeshadow = Sprite::create("parent_read/time_shadow.png");
				timeshadow->setScale(visibleSize.width / 38 * 4.3 / timeshadow->getContentSize().width * 120 / 80, visibleSize.height / 19 * 1.9 / timeshadow->getContentSize().height * 50 / 36);
				timeshadow->setPosition(visibleSize.width / 38 * 15.95, visibleSize.height / 19 * 9.1);
				addChild(timeshadow);
			}
			else if (touch_pos.x >= visibleSize.width / 38 * 19.05 && touch_pos.x <= visibleSize.width / 38 * 23.25) {
				timeshadow->setVisible(false);
				this->removeChild(timeshadow);
				timeshadow = Sprite::create("parent_read/time_shadow.png");
				timeshadow->setScale(visibleSize.width / 38 * 4.3 / timeshadow->getContentSize().width * 120 / 80, visibleSize.height / 19 * 1.9 / timeshadow->getContentSize().height * 50 / 36);
				timeshadow->setPosition(visibleSize.width / 38 * 21.1, visibleSize.height / 19 * 9.1);
				addChild(timeshadow);
			} 
			else if (touch_pos.x >= visibleSize.width / 38 * 24.5 && touch_pos.x <= visibleSize.width / 38 * 28.75) {
				timeshadow->setVisible(false);
				this->removeChild(timeshadow);
				timeshadow = Sprite::create("parent_read/time_shadow.png");
				timeshadow->setScale(visibleSize.width / 38 * 4.3 / timeshadow->getContentSize().width * 120 / 80, visibleSize.height / 19 * 1.9 / timeshadow->getContentSize().height * 50 / 36);
				timeshadow->setPosition(visibleSize.width / 38 * 26.53, visibleSize.height / 19 * 9.1);
				addChild(timeshadow);
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

bool Timeset::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	return true;
}

void Timeset::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

void Timeset::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{

}