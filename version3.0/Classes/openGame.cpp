#include "loading.h"
#include "openGame.h"
#include "HelloWorldScene.h"
#define COCOS_DEBUG_1
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
using namespace cocos2d;

Scene* openGame::createScene()
{
	auto scene = Scene::create();

	auto layer = new (std::nothrow) openGame();

	scene->addChild(layer);

	return scene;
}

openGame::openGame() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	time = 0;
	change1 = 0;
	change2 = 0;
	change3 = 0;
	change4 = 0;
	change5 = 0;
	preloadMusic();
	//set the color of the background is white
	whiteLayer = LayerColor::create(ccc4(255, 255, 255, 255));
	this->addChild(whiteLayer, 1);

	sprite1 = Sprite::create();
	sprite1->setAnchorPoint(Point(0.5, 0));
	this->addChild(sprite1, 2);
	Vector<SpriteFrame*> sprite1Animation;
	sprite1Animation.pushBack(SpriteFrame::create("openGame/sprite1.png", Rect(0, 0, 66, 74)));
	sprite1Animation.pushBack(SpriteFrame::create("openGame/sprite1.png", Rect(66, 0, 66, 74)));
	sprite1Animation.pushBack(SpriteFrame::create("openGame/sprite1.png", Rect(132, 0, 66, 74)));
	sprite1Animation.pushBack(SpriteFrame::create("openGame/sprite1.png", Rect(198, 0, 66, 74)));
	sprite1Animation.pushBack(SpriteFrame::create("openGame/sprite1.png", Rect(264, 0, 66, 74)));
	sprite1Animation.pushBack(SpriteFrame::create("openGame/sprite1.png", Rect(330, 0, 66, 74)));
	auto animationSprite1 = Animation::createWithSpriteFrames(sprite1Animation, 0.2f);
	auto animateSprite1 = Animate::create(animationSprite1);
	//sprite1->runAction(RepeatForever::create(animateSprite1));

	xiao = Sprite::create("openGame/small.png");
	xiao->setAnchorPoint(Point(0.5, 0.5));
	float xx = visibleSize.height / xiao->getContentSize().height / 4;
	xiao->setScale(xx);
	xiao->setPosition(Vec2(-489, visibleSize.height / 2));
	this->addChild(xiao, 2);
	auto xiaojump = JumpTo::create(3, ccp(visibleSize.width / 2 - xiao->getBoundingBox().size.width * 1.3, visibleSize.height / 2), 100, 3);
	xiao->runAction(xiaojump);

	horse = Sprite::create("openGame/horse.png");
	horse->setAnchorPoint(Point(0.5, 0.5));
	float yy = visibleSize.height / horse->getContentSize().height / 4;
	horse->setScale(yy);
	horse->setPosition(Vec2(-326, visibleSize.height / 2));
	this->addChild(horse, 2);
	auto horsejump = JumpTo::create(3, ccp(visibleSize.width / 2 , visibleSize.height / 2), 130, 4);
	horse->runAction(horsejump);

	da = Sprite::create("openGame/da.png");
	da->setAnchorPoint(Point(0.5, 0.5));
	float zz = visibleSize.height / da->getContentSize().height / 4;
	da->setScale(zz);
	da->setPosition(Vec2(-163, visibleSize.height / 2));
	this->addChild(da, 2);
	auto dajump = JumpTo::create(3, ccp(visibleSize.width / 2 + da->getBoundingBox().size.width * 1.3, visibleSize.height / 2), 120, 5);
	da->runAction(dajump);

	sprite1->setPosition(Vec2(0, visibleSize.height / 2 - xiao->getBoundingBox().size.height / 2));
	auto walkSprite1 = MoveTo::create(3.2, ccp(visibleSize.width / 2 + da->getBoundingBox().size.width * 2.2, visibleSize.height / 2 - xiao->getBoundingBox().size.height / 2));
	sprite1->runAction(walkSprite1);

	playBgm();

	schedule(schedule_selector(loading::update), 0.01f);

}

void openGame::update(float delta) {
	time += delta;
	if (time >= 3.2 && change1 == 0) {
		Size visibleSize = Director::getInstance()->getVisibleSize();
		this->removeChild(sprite1);

		sprite2 = Sprite::create();
		sprite2->setAnchorPoint(Point(0.5, 0));
		sprite2->setPosition(visibleSize.width / 2 + da->getBoundingBox().size.width * 2.2, visibleSize.height / 2 - xiao->getBoundingBox().size.height / 2);
		this->addChild(sprite2, 2);
		Vector<SpriteFrame*> sprite2Animation;
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(0, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(57, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(114, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(171, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(228, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(285, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(342, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(399, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(0, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(57, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(114, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(171, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(228, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(285, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(342, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(399, 0, 57, 68)));
		auto animationSprite2 = Animation::createWithSpriteFrames(sprite2Animation, 0.1f);
		auto animateSprite2 = Animate::create(animationSprite2);
		//sprite2->runAction(RepeatForever::create(animateSprite2));
		change1 = 1;
	}
	else if (time >= 5.6 && change2 == 0) {
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		this->removeChild(sprite2);
		sprite3 = Sprite::create();
		sprite3->setAnchorPoint(Point(0.5, 0));
		sprite3->setPosition(visibleSize.width / 2 + da->getBoundingBox().size.width * 2.2, visibleSize.height / 2 - xiao->getBoundingBox().size.height / 2);
		this->addChild(sprite3, 2);
		Vector<SpriteFrame*> sprite3Animation;
		sprite3Animation.pushBack(SpriteFrame::create("openGame/sprite3.png", Rect(0, 0, 67, 70)));
		sprite3Animation.pushBack(SpriteFrame::create("openGame/sprite3.png", Rect(67, 0, 67, 70)));
		sprite3Animation.pushBack(SpriteFrame::create("openGame/sprite3.png", Rect(134, 0, 67, 70)));
		sprite3Animation.pushBack(SpriteFrame::create("openGame/sprite3.png", Rect(201, 0, 67, 70)));
		auto animationSprite3 = Animation::createWithSpriteFrames(sprite3Animation, 0.2f);
		auto animateSprite3 = Animate::create(animationSprite3);
		//sprite3->runAction(animateSprite3);
		change2 = 1;
	}
	else if (time >= 6.3 && change3 == 0) {
		this->removeChild(whiteLayer);
		this->removeChild(sprite3);
		blackLayer = LayerColor::create(ccc4(0, 0, 0, 255));
		this->addChild(blackLayer, 3);
		change3 = 1;
	}
	else if (time >= 6.8 && change4 == 0) {
		Size visibleSize = Director::getInstance()->getVisibleSize();
		blackLayer->setLocalZOrder(1);
		light = Sprite::create("openGame/light.png");
		light->setAnchorPoint(Point(0.5, 1));
		light->setPosition(Vec2(visibleSize.width / 2, visibleSize.height));
		this->addChild(light, 1);

		auto lightrotate1 = RotateBy::create(1, 60);
		auto lightrotate2 = RotateBy::create(2, -120);
		auto lightrotate3 = RotateBy::create(1, 60);
		light->runAction(RepeatForever::create(Sequence::create(lightrotate1, lightrotate2, lightrotate3, NULL)));

		sprite2 = Sprite::create();
		sprite2->setAnchorPoint(Point(0.5, 0));
		sprite2->setPosition(visibleSize.width / 2 + da->getBoundingBox().size.width * 2.2, visibleSize.height / 2 - xiao->getBoundingBox().size.height / 2);
		this->addChild(sprite2, 2);
		Vector<SpriteFrame*> sprite2Animation;
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(0, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(57, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(114, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(171, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(228, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(285, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(342, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite22.png", Rect(399, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(0, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(57, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(114, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(171, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(228, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(285, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(342, 0, 57, 68)));
		sprite2Animation.pushBack(SpriteFrame::create("openGame/sprite2.png", Rect(399, 0, 57, 68)));
		auto animationSprite2 = Animation::createWithSpriteFrames(sprite2Animation, 0.1f);
		auto animateSprite2 = Animate::create(animationSprite2);
		//sprite2->runAction(RepeatForever::create(animateSprite2));
		sprite2->setOpacity(70);

		change4 = 1;
	}
	else if (time >= 8.5 && change5 == 0) {
		Size visibleSize = Director::getInstance()->getVisibleSize();
		this->removeChild(sprite2);

		sprite1 = Sprite::create();
		sprite1->setAnchorPoint(Point(0.5, 0));
		sprite1->setOpacity(70);
		sprite1->setPosition(visibleSize.width / 2 + da->getBoundingBox().size.width * 2.2, visibleSize.height / 2 - xiao->getBoundingBox().size.height / 2);
		this->addChild(sprite1, 2);
		Vector<SpriteFrame*> sprite1Animation;
		sprite1Animation.pushBack(SpriteFrame::create("openGame/sprite1.png", Rect(0, 0, 66, 74)));
		sprite1Animation.pushBack(SpriteFrame::create("openGame/sprite1.png", Rect(66, 0, 66, 74)));
		sprite1Animation.pushBack(SpriteFrame::create("openGame/sprite1.png", Rect(132, 0, 66, 74)));
		sprite1Animation.pushBack(SpriteFrame::create("openGame/sprite1.png", Rect(198, 0, 66, 74)));
		sprite1Animation.pushBack(SpriteFrame::create("openGame/sprite1.png", Rect(264, 0, 66, 74)));
		sprite1Animation.pushBack(SpriteFrame::create("openGame/sprite1.png", Rect(330, 0, 66, 74)));
		auto animationSprite1 = Animation::createWithSpriteFrames(sprite1Animation, 0.5f);
		auto animateSprite1 = Animate::create(animationSprite1);
		//sprite1->runAction(RepeatForever::create(animateSprite1));

		auto walkSprite1 = MoveTo::create(2, ccp(visibleSize.width, visibleSize.height / 2 - xiao->getBoundingBox().size.height / 2));
		sprite1->runAction(walkSprite1);
		change5 = 1;
	}
	else if (time >= 10) {
		this->unschedule(schedule_selector(loading::update));
		auto scene = loading::createScene();
		Director::sharedDirector()->replaceScene(scene);
	}
}
void openGame::preloadMusic()
{
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/music_on.mp3");
	
}
void openGame::playBgm()
{
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/music_on.mp3", true);
}