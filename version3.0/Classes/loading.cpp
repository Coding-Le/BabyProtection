#include "loading.h"
#include "index.h"
#include "HelloWorldScene.h"
#define COCOS_DEBUG_1

USING_NS_CC;
using namespace cocos2d;

Scene* loading::createScene()
{
	auto scene = Scene::create();

	auto layer = new (std::nothrow) loading();

	scene->addChild(layer);

	return scene;
}

loading::loading() : numSprite(11), loadedSprite(0), timeAll(0), add(false) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//set the color of the background is white
	whiteLayer = LayerColor::create(ccc4(255, 255, 255, 255));
	this->addChild(whiteLayer, 1);

	/*loading*/
	//borderForloading
	borderForload = Sprite::create("loading/borderForload.png");
	Size borderForLoadingSize = borderForload->getContentSize();
	borderForload->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - borderForLoadingSize.height));
	float x = visibleSize.width / borderForLoadingSize.width / 2;
	borderForload->setScale(x, x);
	this->addChild(borderForload, 3);

	//timer
	auto progressContent = Sprite::create("loading/contentForload.jpg");
	progressLoading = ProgressTimer::create(progressContent);
	progressLoading->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - borderForLoadingSize.height));
	float xx = borderForload->getBoundingBox().size.width / progressContent->getContentSize().width;
	float yy = borderForload->getBoundingBox().size.height / progressContent->getContentSize().height;
	progressLoading->setScale(xx, yy);
	this->addChild(progressLoading, 2);

	progressLoading->setType(ProgressTimer::Type::BAR);//type of animation
	progressLoading->setBarChangeRate(Vec2(1, 0));
	progressLoading->setMidpoint(Vec2(0, 0));
	progressLoading->setPercentage(0.0f);

	//little girl

	girl = Sprite::create("index/stand.png");
	float xxx = borderForload->getBoundingBox().size.width / girl->getContentSize().width / 8;
	girl->setAnchorPoint(Point(0.5, 0));
	girl->setPosition(Vec2((visibleSize.width - borderForload->getBoundingBox().size.width) / 2, visibleSize.height / 2 - borderForLoadingSize.height + borderForload->getBoundingBox().size.height / 2));
	girl->setScale(xxx,xxx);
	this->addChild(girl, 3);

	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("index/walk1.png");
	animation->addSpriteFrameWithFile("index/walk2.png");
	animation->addSpriteFrameWithFile("index/walk3.png");
	animation->addSpriteFrameWithFile("index/walk4.png");
	animation->setDelayPerUnit(0.2f);
	animation->setRestoreOriginalFrame(true);
	auto action = Animate::create(animation);
	girl->runAction(RepeatForever::create(action));
	/*auto girlMove = MoveTo::create(4, ccp(visibleSize.width - (visibleSize.width - borderForload->getBoundingBox().size.width)/2, girl->getPosition().y));
	girl->runAction(girlMove);*/

	//loading
	Loading = Label::createWithTTF("Loading...", "fonts/impact.ttf", 42);
	Loading->setAnchorPoint(Point(0.5, 0.5));
	Loading->setColor(Color3B(207, 138, 69));
	Loading->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - borderForLoadingSize.height * 2));
	this->addChild(Loading, 3);
	auto out = FadeOut::create(0.5);
	auto in = FadeIn::create(0.5);
	Loading->runAction(RepeatForever::create(Sequence::create(out, in, NULL)));

	schedule(schedule_selector(loading::update), 0.01f);

	//loading
	Director::getInstance()->getTextureCache()->addImageAsync("index/walk1.png", CC_CALLBACK_1(loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("index/walk2.png", CC_CALLBACK_1(loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("index/walk3.png", CC_CALLBACK_1(loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("index/walk4.png", CC_CALLBACK_1(loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("index/stand.png", CC_CALLBACK_1(loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("index/background.png", CC_CALLBACK_1(loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("index/exit.png", CC_CALLBACK_1(loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("index/map.png", CC_CALLBACK_1(loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("index/moon.png", CC_CALLBACK_1(loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("index/parent.png", CC_CALLBACK_1(loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("index/plane.png", CC_CALLBACK_1(loading::loadingCallBack, this));

	//auto layer1 = new index();
	//addChild(layer1);

}

void loading::update(float delta) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float origin = (visibleSize.width - borderForload->getBoundingBox().size.width) / 2;
	float interval = progressLoading->getPercentage() / 100 * borderForload->getBoundingBox().size.width;
	girl->setPosition(Vec2(origin + interval, girl->getPosition().y));
	if (add == true) {
		auto time = ProgressFromTo::create(3.0f, progressLoading->getPercentage(), (float)(loadedSprite) * (100 / (float)(numSprite)));
		progressLoading->runAction(time);
	}
	add = false;
	if (loadedSprite == numSprite && progressLoading->getPercentage() >= 100) {
		if (timeAll >= 0.5) {
			this->gotoNewPage();
			this->unschedule(schedule_selector(loading::update));  
		}
		else{
			timeAll += delta;
		}
	}
}

void loading::loadingCallBack(cocos2d::Texture2D* texture) {
	loadedSprite++;
	add = true;
}

void loading::gotoNewPage(void) {
	this->stopAllActions();
	/*this->removeChild(girl);
	this->removeChild(borderForload);
	this->removeChild(progressLoading);
	this->removeChild(whiteLayer);
	this->removeChild(Loading);*/
	auto scene = HelloWorld::createScene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
}