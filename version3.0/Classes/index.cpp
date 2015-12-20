#include "index.h"
#define COCOS_DEBUG_1

USING_NS_CC;
using namespace cocos2d;
Scene* index::createScene()
{
	auto scene = Scene::create();

	auto layer = new (std::nothrow) index();

	scene->addChild(layer);

	return scene;
}
index::index() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//±³¾°
	auto background = Sprite::create("index/background.png");
	float x = visibleSize.width / background->getContentSize().width;
	float y = visibleSize.height / background->getContentSize().height;
	background->setScale(x, y);
	background->setAnchorPoint(Vec2::ZERO);
	background->setPosition(Vec2::ZERO);
	this->addChild(background, 0);

	//µØÇò
	auto map = Sprite::create("index/map.png");
	float xx = visibleSize.width / map->getContentSize().width / 2;
	map->setScale(x, x);
	map->setPosition(Vec2(visibleSize.width / 2, 0));
	this->addChild(map);

	CCActionInterval*  mapActionBy = CCRotateBy::create(15, -360);
	map->runAction(CCRepeatForever::create(mapActionBy));

	//ÔÂÇò
	auto moon = Sprite::create("index/moon.png");
	moon->setScale(0.15f, 0.15f);
	moon->setAnchorPoint(Vec2(0.5, 0.5));
	moon->setPosition(Vec2(visibleSize.width - moon->getBoundingBox().size.width / 2 - 25, visibleSize.height - moon->getBoundingBox().size.height / 2 - 25));
	this->addChild(moon);


	//auto parentMode_menu = MenuItemLabel::create(moonLabel, CC_CALLBACK_1(HelloWorld::parentMode_func, this));
	//parentMode_menu->setPosition(Vec2(visibleSize.width - moon->getBoundingBox().size.width / 2 - 30, visibleSize.height - moon->getBoundingBox().size.height - 40));
	//this->addChild(parentMode_menu);

	CCActionInterval*  girlActionBy = CCRotateBy::create(20, 360);
	moon->runAction(CCRepeatForever::create(girlActionBy));
	//UFO
	auto ufo = Sprite::create("index/plane.png");
	ufo->setScale(0.2f, 0.2f);
	ufo->setAnchorPoint(Vec2(0.5, 0.5));
	ufo->setPosition(Vec2(ufo->getBoundingBox().size.width / 2 + 25, visibleSize.height - moon->getBoundingBox().size.height / 2 - 25));
	this->addChild(ufo);

	//CCActionInterval*  ufoActionBy = CCMoveBy::create(0.5f, Vec3(50, -50,0));
	//ufo->runAction(CCRepeatForever::create(ufoActionBy));

	cocos2d::Sprite* character = Sprite::create("index/stand.png");
	character->setScale(0.25);
	//character->setAnchorPoint(Vec2(0.5, 0));
	character->setPosition(Vec2(visibleSize.width / 2, map->getContentSize().height / 2 + character->boundingBox().size.height / 3));
	int i = map->getContentSize().height / 2 + character->boundingBox().size.height / 3;
	this->addChild(character, 5);
	Vector<SpriteFrame*> girlFrames;
	girlFrames.reserve(4);
	girlFrames.pushBack(SpriteFrame::create("index/walk1.png", Rect(0, 0, 500, 940)));
	girlFrames.pushBack(SpriteFrame::create("index/walk2.png", Rect(0, 0, 500, 940)));
	girlFrames.pushBack(SpriteFrame::create("index/walk3.png", Rect(0, 0, 500, 940)));
	girlFrames.pushBack(SpriteFrame::create("index/walk4.png", Rect(0, 0, 500, 940)));
	auto girl_move = Animation::createWithSpriteFrames(girlFrames, 0.3f);
	auto girl_animate = Animate::create(girl_move);
	character->runAction(RepeatForever::create(girl_animate));

	auto ufoLabel = Sprite::create("index/exit.png");
	ufoLabel->setScale(0.07f);
	ufoLabel->setAnchorPoint(Vec2(0.5, 0.5));
	ufoLabel->setPosition(Vec2(ufo->getBoundingBox().size.width / 2 + 25, visibleSize.height - moon->getBoundingBox().size.height - 40));
	this->addChild(ufoLabel);
}