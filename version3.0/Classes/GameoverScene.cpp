#include "GameoverScene.h"
#include "ZooScene.h"
#include "ScrollViewScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

int GameoverScene::kind = 0;

Scene* GameoverScene::createScene(int k)
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	GameoverScene::setKind(k);
	// 'layer' is an autorelease object
	auto layer = GameoverScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameoverScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	std::string music = "gameover/";
	std::string bgPic = "gameover/";
	switch (GameoverScene::kind)
	{
	case 0:
		music += "uncle.mp3";
		bgPic += "uncle.png";
		break;
	case 1:
		music += "badguy.mp3";
		bgPic += "badguy.png";
		break;
	case 2:
		music += "woman.mp3";
		bgPic += "woman.png";
		break;
	case 3:
		music += "win.mp3";
		bgPic += "win.png";
		break;
	default:
		music += "uncle.mp3";
		bgPic += "uncle.png";
	}

	auto bg = Sprite::create(bgPic);
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(visibleSize.height / bg->getContentSize().height);
	this->addChild(bg);
	bg->setPosition(Vec2(visibleSize.width * 0.50f, visibleSize.height * 0.50f));


	auto BackItem = MenuItemImage::create("icon/back.png", "icon/back1.png", CC_CALLBACK_1(GameoverScene::menuBackCallback, this));
	BackItem->setScale(visibleSize.height * 0.10f / BackItem->getContentSize().height);
	BackItem->setPosition(Vec2(BackItem->getBoundingBox().getMaxX() - BackItem->getBoundingBox().getMidX() + 40.0f, visibleSize.height - BackItem->getBoundingBox().getMaxX() + BackItem->getBoundingBox().getMidX() - 40));

	auto AgainItem = MenuItemImage::create("icon/again.png", "icon/again1.png", CC_CALLBACK_1(GameoverScene::menuAgainCallback, this));
	AgainItem->setScaleX(visibleSize.width * 0.10f / AgainItem->getContentSize().width);
	AgainItem->setScaleY(visibleSize.height * 0.10f / AgainItem->getContentSize().height);
	Rect temp = AgainItem->getBoundingBox();
	AgainItem->setAnchorPoint(Vec2(0.0f, 1.0f));
	AgainItem->setPosition(Vec2(visibleSize.width * 0.65f, visibleSize.height * 0.42f));

	auto NextItem = MenuItemImage::create("icon/next.png", "icon/next1.png", CC_CALLBACK_1(GameoverScene::menuNextCallback, this));
	NextItem->setScaleX(visibleSize.width * 0.10f / NextItem->getContentSize().width);
	NextItem->setScaleY(visibleSize.height * 0.10f / NextItem->getContentSize().height);
	NextItem->setAnchorPoint(Vec2(1.0f, 1.0f));
	NextItem->setPosition(Vec2(visibleSize.width * 0.92f, visibleSize.height * 0.42f));

	// create menu, it's an autorelease object
	auto menu = Menu::create(BackItem, AgainItem, NextItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto listenerkeyPad = EventListenerKeyboard::create();
	listenerkeyPad->onKeyReleased = CC_CALLBACK_2(GameoverScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);

	SimpleAudioEngine::getInstance()->playEffect(music.c_str(), false);
	return true;
}

void GameoverScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void GameoverScene::setKind(int k)
{
	GameoverScene::kind = k;
}

void GameoverScene::menuBackCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(ScrollViewScene::create());
}

void GameoverScene::menuAgainCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(ZooScene::createScene());
}

void GameoverScene::menuNextCallback(cocos2d::Ref* pSender)
{
	//Director::getInstance()->replaceScene(ZooScene::createScene());
}

void GameoverScene::onKeyReleased(EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{
	if (keycode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		Director::getInstance()->end();
	}
}