#include "HelloWorldScene.h"
#include"parentMode.h"
#include"cocos2d.h"
#include <string>
#include"ScrollViewScene.h"
#include"introduction.h"
using namespace std;
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
#pragma execution_character_set("utf-8") 
USING_NS_CC;
#define database UserDefault::getInstance()
Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	preloadMusic();
	isCut = false;
	dispatcher = Director::getInstance()->getEventDispatcher();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	totalTime1 = 0;
	label2 = Label::createWithBMFont("fonts/futura-48.fnt", "Loading");
	label2->setPosition(Vec2(visibleSize.width / 2,
		visibleSize.height - 500));
	//this->addChild(label2, 1);
	//±³¾°
	auto background = Sprite::create("background.png");
	float x = visibleSize.width / background->getContentSize().width;
	float y = visibleSize.height / background->getContentSize().height;
	background->setScale(x, y);
	background->setAnchorPoint(Vec2::ZERO);
	background->setPosition(Vec2::ZERO);
	this->addChild(background, 0);

	//µØÇò
	auto map = Sprite::create("map.png");
	//map->setAnchorPoint(Vec2(0.5, 0.5));
	map->setScale(visibleSize.height / map->getContentSize().height, visibleSize.height / map->getContentSize().height);
	auto iii = map->getBoundingBox().getMaxY() - map->getBoundingBox().getMinY();
	map->setPosition(Vec2(visibleSize.width / 2, iii/3));
	this->addChild(map);

	CCActionInterval*  mapActionBy = CCRotateBy::create(15, -360);
	map->runAction(CCRepeatForever::create(mapActionBy));

	//ÔÂÇò
	auto moon = Sprite::create("moon.png");
	moon->setScale(0.25*visibleSize.height / moon->getContentSize().height, 0.25*visibleSize.height / moon->getContentSize().height);
	moon->setAnchorPoint(Vec2(0.5, 0.5));
	moon->setPosition(Vec2(visibleSize.width - moon->getBoundingBox().size.width / 2 - 25, visibleSize.height - moon->getBoundingBox().size.height / 2 - 25));
	this->addChild(moon);

	moonLabel = Sprite::create("parent.png");
	moonLabel->setScale(0.2*visibleSize.height / moonLabel->getContentSize().height);
	moonLabel->setAnchorPoint(Vec2(0.5, 0.5));
	moonLabel->setPosition(Vec2(visibleSize.width - moon->getBoundingBox().size.width / 2 - 30, visibleSize.height - moon->getBoundingBox().size.height - 40));
	this->addChild(moonLabel);

	
	//auto parentMode_menu = MenuItemLabel::create(moonLabel, CC_CALLBACK_1(HelloWorld::parentMode_func, this));
	//parentMode_menu->setPosition(Vec2(visibleSize.width - moon->getBoundingBox().size.width / 2 - 30, visibleSize.height - moon->getBoundingBox().size.height - 40));
	//this->addChild(parentMode_menu);

	CCActionInterval*  girlActionBy = CCRotateBy::create(20, 360);
	moon->runAction(CCRepeatForever::create(girlActionBy));

	//UFO
	auto ufo = Sprite::create("plane.png");
	ufo->setScale(0.2*visibleSize.height / ufo->getContentSize().height);
	ufo->setAnchorPoint(Vec2(0.5, 0.5));
	ufo->setPosition(Vec2(ufo->getBoundingBox().size.width / 2 + 25, visibleSize.height - moon->getBoundingBox().size.height / 2 - 25));
	this->addChild(ufo);

	//CCActionInterval*  ufoActionBy = CCMoveBy::create(0.5f, Vec3(50, -50,0));
	//ufo->runAction(CCRepeatForever::create(ufoActionBy));

	cocos2d::Sprite* character = Sprite::create("girl/1.png");
	character->setScale(0.1*visibleSize.height/character->getContentSize().height);
	//character->setAnchorPoint(Vec2(0.5, 0));
	character->setPosition(Vec2(visibleSize.width / 2, map->getBoundingBox().size.height / 17.78 * 5 + map->getPosition().y + character->getBoundingBox().size.height/2));
	int i = map->getContentSize().height / 2 + character->boundingBox().size.height / 3;
	this->addChild(character, 5);

	Vector<SpriteFrame*> girlFrames;
	girlFrames.reserve(4);
	Rect br(0, 0, character->getContentSize().width, character->getContentSize().height);
	girlFrames.pushBack(SpriteFrame::create("girl/1.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/2.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/3.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/4.png", br));
	auto girl_move = Animation::createWithSpriteFrames(girlFrames, 0.3f);
	auto girl_animate = Animate::create(girl_move);
	character->runAction(RepeatForever::create(girl_animate));

	Schedule();

	//ufoLabel = MenuItemImage::create("exit.png", "exit.png", CC_CALLBACK_1(HelloWorld::quitgame, this));
	ufoLabel = Sprite::create("exit.png");
	ufoLabel->setScale(0.2*visibleSize.height/ufoLabel->getContentSize().height);
	//ufoLabel->setAnchorPoint(Vec2(0.5, 0.5));
	ufoLabel->setPosition(Vec2(ufo->getBoundingBox().size.width / 2 + 25, visibleSize.height - moon->getBoundingBox().size.height - 40));
	this->addChild(ufoLabel,10);

	//about = Sprite::create("xiaomada.png");
	//about->setScale(0.1);
	//about->setPosition(Vec2(visibleSize.width/2, visibleSize.height-about->getBoundingBox().getMaxY()+about->getBoundingBox().getMinY()));
	//this->addChild(about);
	info = Sprite::create("hint/info.png");
	info->setScale(0.4*visibleSize.height / info->getContentSize().height);
	info->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(info, 20);
	info->setVisible(false);
	//button of about us
	//auto aboutButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::clickAboutBtn, this));
	//auto aboutMenu = Menu::create(aboutButton, NULL);
	//aboutMenu->setPosition(Vec2(visibleSize.width - 20, 20));
	//this->addChild(aboutMenu, 10);

	startgame = MenuItemImage::create("gamescene/startgame.png", "gamescene/startgame.png", CC_CALLBACK_1(HelloWorld::goahead, this));
	startgame->setScale(0.4*visibleSize.height / startgame->getContentSize().height);
	startgame->setPosition(visibleSize.width - startgame->getBoundingBox().size.width / 2, startgame->getBoundingBox().size.height/2);
	this->addChild(startgame);


	//timerStr1 = Label::createWithTTF("0%", "fonts/Marker Felt.ttf", 40);
	//auto timerStrPos = Vec2(Director::getInstance()->getVisibleSize().width / 2, 100);
	//timerStr1->setColor(Color3B::BLACK);
	//timerStr1->setPosition(timerStrPos);
	//this->addChild(timerStr1, 1);
	auto click = Sprite::create("finger2.png");
	auto up_action = MoveBy::create(1.0f, Vec2(15.0f, 0.0f));
	click->runAction(RepeatForever::create(Sequence::create(up_action, up_action->reverse(), NULL)));
	this->addChild(click);
	click->setScale(0.15*visibleSize.height / click->getContentSize().height);
	click->setPosition(Vec2(moonLabel->getPosition().x-moonLabel->getBoundingBox().size.width/2-click->getBoundingBox().size.width/2,moonLabel->getPosition().y));


	testTouchEvent();
	testCustomEvent();
	playBgm();

	return true;


}
void HelloWorld::preloadMusic()
{
	//SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/music_on.mp3");
}
void HelloWorld::playBgm()
{
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("music/music_on.mp3", true);
}

void HelloWorld::clickAboutContent(cocos2d::Ref* pSender) {
	about->setVisible(false);
}
void HelloWorld::clickAboutBtn(cocos2d::Ref* pSender) {
	//if (about->isVisible()) about->setVisible(false);
	//else about->setVisible(true);
}
void HelloWorld::updateTime1(float dt){
	totalTime1 += dt;
	if (totalTime1 > 6) {
		
	}
	//char t[10];
	//char* who = "%";
	//int d = totalTime1 * 10;
	//Size visibleSize = Director::getInstance()->getVisibleSize();
	//Vec2 origin = Director::getInstance()->getVisibleOrigin();
	/*if (d % 11 > 0.9 && d % 11 < 1.1) {
		label1 = Label::createWithBMFont("fonts/futura-48.fnt", ".");
		label1->setPosition(Vec2(visibleSize.width / 2+100,
			visibleSize.height - 500));
		this->addChild(label1, 1);
	}
	else if (d % 11 > 3.9 && d % 11 < 4.1){
		label3 = Label::createWithBMFont("fonts/futura-48.fnt", ".");
		label3->setPosition(Vec2(visibleSize.width / 2 + 120,
			visibleSize.height - 500));
		this->addChild(label3, 1);
	}
	else if (d % 11 > 6.9 && d % 11 < 7.1) {
		label4 = Label::createWithBMFont("fonts/futura-48.fnt", ".");
		label4->setPosition(Vec2(visibleSize.width / 2 + 140,
			visibleSize.height - 500));
		this->addChild(label4, 1);
	}
	else if (d % 11 < 9.1 && d % 11 > 8.9) {
		this->removeChild(label1);
		this->removeChild(label3);
		this->removeChild(label4);
	}*/
	//sprintf(t, "%d%s", d, who);
	//timerStr1->setString(t);
}

void HelloWorld::Schedule() {
	if (totalTime1 < 6.1) {
		schedule(schedule_selector(HelloWorld::updateTime1), 0.1f);
		//auto progressSprite1 = Sprite::create("image/rge.png");
		//auto pT1 = ProgressTimer::create(progressSprite1);
		//pT1->setType(ProgressTimer::Type::BAR);
		//pT1->setMidpoint(Point(0, 0));
		//pT1->setBarChangeRate(Point(1, 0));
		//pT1->runAction(RepeatForever::create(ProgressFromTo::create(10, 0, 100)));
		//pT1->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, 100));
		//this->addChild(pT1);
	}
}
//void HelloWorld::parentMode_func(Ref *ref) {
//	this->stopAllActions();
//	auto scene = parentMode::createScene();
//	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
//}


void HelloWorld::testTouchEvent()
{
	streak = MotionStreak::create(0.5f, 10, 30, Color3B::WHITE, "Demo/flash.png");
	this->addChild(streak, 2);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event){
		touch_pos = touch->getLocation();
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		//abs(touch_pos.x - moonLabel->getPositionX()) < moonLabel->getContentSize().width / 2 && abs(touch_
		//pos.y - moonLabel->getPositionY()) < moonLabel->getContentSize().height / 2
		if (moonLabel->getBoundingBox().containsPoint(touch_pos)) {
				this->stopAllActions();
				auto scene = parentMode::createScene();
				CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
			}
			else if (startgame->getBoundingBox().containsPoint(touch_pos)){
				goahead(this);
			}
			else if (ufoLabel->getBoundingBox().containsPoint(touch_pos)) {
				quitgame(this);
			}
			else if (info->getBoundingBox().containsPoint(touch_pos)) {
				if (info->isVisible() == true) {
					info->setVisible(false);
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

void HelloWorld::testAccelerationEvent()
{
	Device::setAccelerometerEnabled(true);

	auto listener = EventListenerAcceleration::create([](Acceleration* acceleration, Event* event){
		log("X: %f; Y: %f; Z:%f; ", acceleration->x, acceleration->y, acceleration->z);
	});

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::testKeyboardEvent()
{
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = [&](EventKeyboard::KeyCode code, Event* event){
		if (code == EventKeyboard::KeyCode::KEY_A)
		{
			log("onKeyPressed--A");
		}
	};

	listener->onKeyReleased = [&](EventKeyboard::KeyCode code, Event* event){
		if (code == EventKeyboard::KeyCode::KEY_A)
		{
			log("onKeyReleased--A");
		}
	};

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::testMouseEvent()
{
	auto listener = EventListenerMouse::create();

	listener->onMouseDown = [&](Event* event){
		log("onMouseDown");
	};

	listener->onMouseMove = [&](Event* event){
		EventMouse* my_mouse = (EventMouse*)event;

	};

	listener->onMouseUp = [&](Event* event){
		log("onMouseUp");
	};

	listener->onMouseScroll = [&](Event* event){
		log("onMouseScroll");
	};

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::testCustomEvent()
{
	auto listener = EventListenerCustom::create("off", [](EventCustom* event){
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	});
	dispatcher->addEventListenerWithFixedPriority(listener, 1);
}

void HelloWorld::turnoff() {
	EventCustom e("off");

	e.setUserData(&touch_pos);

	dispatcher->dispatchEvent(&e);
}
void HelloWorld::goahead(Ref* ref) {
	if (!database->getBoolForKey("isExist")) {
		info->setVisible(true);
	}
	else {
		this->stopAllActions();
		auto scene = ScrollViewScene::create();
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1, scene, Color3B::GRAY));
	}
}
void HelloWorld::quitgame(Ref* ref) {
	Director::getInstance()->end();
}