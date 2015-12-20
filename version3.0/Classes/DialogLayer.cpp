#include "DialogLayer.h"
USING_NS_CC;

bool DialogLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto label = Label::createWithTTF("Sure to quit?", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.7));
	this->addChild(label);
	
	
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(DialogLayer::menuCloseCallback, this));

	closeItem->setPosition(Vec2(visibleSize.width / 2,
		visibleSize.height / 4));

	// create menu, it's an autorelease object
	menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	menu->setEnabled(true);

	/*auto quitMenuItem = MenuItemFont::create("Yes", DialogLayer::menuCloseCallback);
	quitMenuItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.3));

	auto menu = Menu::create(quitMenuItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);*/
	//this->setSwallowsTouches(true);
	this->setTouchEnabled(true);
	return true;
}

/*bool DialogLayer::onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	menu->onTouchBegan(pTouch, pEvent);
	return true;
}

void DialogLayer::onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	menu->onTouchMoved(pTouch, pEvent);
}

void DialogLayer::onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	//this->removeFromParent();
	//return true;
	menu->onTouchEnded(pTouch, pEvent);
}

/*void DialogLayer::registerWithTouchDispatcher()
{
	TouchDispatcher::sharedDispatcher()->addTargetedDelegate
}*/

/*void DialogLayer::onEnter()
{
	//CCDirector::sharedDirector()->getTouchDispatcher()->
}*/

void DialogLayer::menuCloseCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();
}