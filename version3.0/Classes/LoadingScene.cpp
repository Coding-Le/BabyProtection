#include "LoadingScene.h"
#include "LostScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

int LoadingScene::starNum = 0;

Scene* LoadingScene::createScene(int s)
{
	auto scene = Scene::create();
	LoadingScene::starNum = s;
	auto layer = LoadingScene::create();
	scene->addChild(layer);
	return scene;
}

bool LoadingScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto sprite = Sprite::create("loadinglost.jpg");
	sprite->setScaleX(visibleSize.width / sprite->getContentSize().width);
	sprite->setScaleY(visibleSize.height / sprite->getContentSize().height);

	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite, 0);
	totalNum = 39;
	loadedNum = 0;
	star = Sprite::create("star.png");
	star->setScaleX(visibleSize.width * 0.05f / star->getContentSize().width);
	star->setScaleY(visibleSize.height * 0.08f / star->getContentSize().height);
	this->addChild(star);
	star->setPosition(Vec2(star->getBoundingBox().getMidX() - star->getBoundingBox().getMinX() + visibleSize.width * 0.02f, visibleSize.height - star->getBoundingBox().getMidY() + star->getBoundingBox().getMinY() - visibleSize.height * 0.02f));
	char num[10];
	snprintf(num, 9, "%d", LoadingScene::starNum);
	grades = LabelTTF::create(num, "fonts/arial.ttf", 24);
	this->addChild(grades);
	grades->setPosition(Vec2(star->getPositionX(), star->getPositionY() - grades->getContentSize().height * 1.5f));
	grades->setColor(Color3B::RED);
	canLeave = true;
	if (LoadingScene::starNum == 0)
	{
		canLeave = false;
		countTime = 0;
		this->schedule(schedule_selector(LoadingScene::decideLeave), 0.5f);
		SimpleAudioEngine::getInstance()->playEffect("lost/dog.mp3");
		auto starTalk = Sprite::create("hint/2.png");
		//float h = star->getBoundingBox().getMaxY() - star->getBoundingBox().getMinY();
		starTalk->setScaleX(visibleSize.width * 0.15f / star->getContentSize().width);
		starTalk->setScaleY(visibleSize.height * 0.20f / star->getContentSize().width);
		starTalk->setAnchorPoint(Vec2(0.0f, 0.5f));
		this->addChild(starTalk);
		starTalk->setPosition(Vec2(star->getPositionX() + star->getBoundingBox().getMaxX() - star->getBoundingBox().getMidX(), star->getPositionY()));
		auto Ani = FadeOut::create(7.0f);
		starTalk->runAction(Ani);
	}

	loading();
	return true;
}

void LoadingScene::loading()
{
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/1.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/2.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/3.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/4.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/5.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/6.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/7.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/8.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/9.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/10.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/11.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/12.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/13.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/14.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/background/15.jpg", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));

	TextureCache::sharedTextureCache()->addImageAsync("baby/Girl/stand.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("baby/Girl/1.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("baby/Girl/2.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("baby/Girl/3.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("baby/Girl/4.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));

	TextureCache::sharedTextureCache()->addImageAsync("lost/uncle/stand.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/uncle/1.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/uncle/2.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/uncle/3.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/uncle/4.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));

	TextureCache::sharedTextureCache()->addImageAsync("lost/badguy/stand.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/badguy/1.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/badguy/2.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/badguy/3.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/badguy/4.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/badguy/c1.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/badguy/c2.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/badguy/c3.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/badguy/c4.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));

	TextureCache::sharedTextureCache()->addImageAsync("lost/woman/stand.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/woman/1.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/woman/2.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/woman/3.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
	TextureCache::sharedTextureCache()->addImageAsync("lost/woman/4.png", CC_CALLBACK_0(LoadingScene::loadedCallBack, this));
}

void LoadingScene::loadedCallBack()
{
	loadedNum++;
	if (loadedNum == totalNum && canLeave)
	{
		Director::getInstance()->replaceScene(LostScene::createScene(LoadingScene::starNum));
	}
}

void LoadingScene::decideLeave(float t)
{
	countTime++;
	if (countTime == 10)
	{
		canLeave = true;
		if (loadedNum == totalNum)
			Director::getInstance()->replaceScene(LostScene::createScene(LoadingScene::starNum));
	}
}