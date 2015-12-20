#include"beforezoo.h"
#pragma execution_character_set("utf-8") 
#include "ui\UIScale9Sprite.h"
#include"ZooScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
//#include"FlowWorld.h"
#define database UserDefault::getInstance()
Scene* beforezoo::createScene(){
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = beforezoo::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
bool beforezoo::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	totalTime1 = 0;
	chinese = 0;

	auto bgsprite = Sprite::create("gamescene/beginscene.png");
	float odds;
	float oddsY;
	oddsY = bgsprite->getContentSize().height / visibleSize.height;
	odds = bgsprite->getContentSize().width / visibleSize.width;
	bgsprite->setScaleY(1 / oddsY);
	bgsprite->setScaleX(1 / odds);
	bgsprite->setPosition(Vec2(visibleSize / 2) + origin);
	this->addChild(bgsprite, 0);


	girl1 = Sprite::create("gamescene/girl.png");
	girl1->setScale(visibleSize.height*0.35 / girl1->getContentSize().height);
	mother1 = Sprite::create("gamescene/mother.png");
	mother1->setScale(visibleSize.height*0.4 / mother1->getContentSize().height);
	girl1->setPosition(Vec2(visibleSize.width / 2 - girl1->getBoundingBox().size.width/2, girl1->getBoundingBox().size.height/2));
	addChild(girl1);
	mother1->setPosition(Vec2(visibleSize.width / 2 + mother1->getBoundingBox().size.width / 2, mother1->getBoundingBox().size.height / 2));
	addChild(mother1);

	motherwidth = mother1->getBoundingBox().size.width;
	motherheight = mother1->getBoundingBox().size.height;
	Schedule();

	back = MenuItemImage::create("gamescene/remember2.png", "gamescene/remember2.png", CC_CALLBACK_1(beforezoo::returnto, this));
	back_menu = Menu::create(back, NULL);
	back_menu->setPosition(Vec2(girl1->getPosition().x, girl1->getPosition().y + girl1->getBoundingBox().size.height*0.75));
	this->addChild(back_menu, 3);
	back_menu->setVisible(false);
	//auto click = Sprite::create("finger2.png");
	//auto up_action = MoveBy::create(1.0f, Vec2(15.0f, 0.0f));
	//click->runAction(RepeatForever::create(Sequence::create(up_action, up_action->reverse(), NULL)));
	//this->addChild(click);
	//click->setScale(0.15*Director::getInstance()->getVisibleSize().height / click->getContentSize().height);
	//click->setPosition(Vec2(back->getPosition().x-back->getBoundingBox().size.width/2-click->getBoundingBox().size.width/2,back->getPosition().y));
	click = Sprite::create("finger.png");
	auto up_action = MoveBy::create(1.0f, Vec2(0.0f, 15.0f));
	click->runAction(RepeatForever::create(Sequence::create(up_action, up_action->reverse(), NULL)));
	this->addChild(click);
	click->setScale(0.15*Director::getInstance()->getVisibleSize().height / click->getContentSize().height);
	click->setPosition(Vec2(girl1->getPosition().x, girl1->getPosition().y + girl1->getBoundingBox().size.height*0.85 + click->getContentSize().height / 4));
	click->setVisible(false);

	return true;
}
void beforezoo::hintCallback(cocos2d::Ref* pSender) {}

void beforezoo::Schedule() {
	schedule(schedule_selector(beforezoo::updateTime1), 1.0f);
}
void beforezoo::preloadMusic()
{
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/dia/1.mp3");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/dia/2.mp3");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/dia/3.mp3");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/dia/5.mp3");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/dia/6.mp3");
}


void beforezoo::updateTime1(float dt){
	totalTime1 += dt;
	ccColor3B c;
	c.r = 0;
	c.g = 0;
	c.b = 0;
	if (totalTime1 > 1 && totalTime1 < 2.1) {
		if (!chinese) {
			SimpleAudioEngine::getInstance()->playBackgroundMusic("music/dia/1.mp3", false);
			CCDictionary *strings = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
			const char *charchinese = ((CCString*)strings->objectForKey("dia1"))->getCString();
			auto childname = database->getStringForKey("babyName");
			childname = childname + charchinese;
			chinese = CCLabelTTF::create(childname, "Arial", 22);
			chinese->setColor(c);
			chinese->setPosition(Vec2(mother1->getPosition().x + motherwidth, mother1->getPosition().y + motherheight*0.7));
			addChild(chinese, 1);

			

			std::string d = "dia_1.png";
			//label = Label::createWithTTF("1", "fonts/Marker Felt.ttf", 24);
			//label->setColor(Color3B::BLACK);
			sprite = ui::Scale9Sprite::create(d);
			Size extendsize = CCSizeMake(242, 183);
			sprite->setContentSize(extendsize);
			//this->addChild(label, 1);
			//label->setPosition(Vec2(mother1->getPosition().x + motherwidth/4*3, mother1->getPosition().y + motherheight / 2));
			sprite->setPosition(chinese->getPosition());
			this->addChild(sprite, 0);
		}
	}
	else if (totalTime1 >  7 && totalTime1 < 8.1) {
		SimpleAudioEngine::getInstance()->playBackgroundMusic("music/dia/2.mp3", false);
		chinese->setVisible(false);
		this->removeChild(chinese);
		this->removeChild(sprite);
		CCDictionary *strings = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
		const char *charchinese = ((CCString*)strings->objectForKey("dia2"))->getCString();
		chinese = CCLabelTTF::create(charchinese, "Arial", 22);
		chinese->setColor(c);
		chinese->setPosition(Vec2(mother1->getPosition().x + motherwidth, mother1->getPosition().y + motherheight*0.7));
		addChild(chinese, 1);

		

		std::string d = "dia_1.png";
		//label = Label::createWithTTF("1", "fonts/Marker Felt.ttf", 24);
		//label->setColor(Color3B::BLACK);
		sprite = ui::Scale9Sprite::create(d);
		Size extendsize = CCSizeMake(242, 183);
		sprite->setContentSize(extendsize);
		//this->addChild(label, 1);
		//label->setPosition(Vec2(mother1->getPosition().x + motherwidth/4*3, mother1->getPosition().y + motherheight / 2));
		sprite->setPosition(chinese->getPosition());
		this->addChild(sprite, 0);
	}
	else if (totalTime1 > 14 && totalTime1 < 15.1) {
		chinese->setVisible(false);
		this->removeChild(sprite);
		this->removeChild(chinese);
		CCDictionary *strings = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
		const char *charchinese = ((CCString*)strings->objectForKey("dia3"))->getCString();
		chinese = CCLabelTTF::create(charchinese, "Arial", 22);
		chinese->setColor(c);
		chinese->setPosition(Vec2(mother1->getPosition().x + motherwidth, mother1->getPosition().y + motherheight*0.7));
		addChild(chinese, 1);

		std::string d = "dia_1.png";
		//label = Label::createWithTTF("1", "fonts/Marker Felt.ttf", 24);
		//label->setColor(Color3B::BLACK);
		sprite = ui::Scale9Sprite::create(d);
		Size extendsize = CCSizeMake(242, 183);
		sprite->setContentSize(extendsize);
		//this->addChild(label, 1);
		//label->setPosition(Vec2(mother1->getPosition().x + motherwidth/4*3, mother1->getPosition().y + motherheight / 2));
		sprite->setPosition(chinese->getPosition());
		this->addChild(sprite, 0);
	}
	else if (totalTime1 > 17 && totalTime1 < 18.1) {
		SimpleAudioEngine::getInstance()->playBackgroundMusic("music/dia/3.mp3", false);
		chinese->setVisible(false);
		this->removeChild(sprite);
		this->removeChild(chinese);
		CCDictionary *strings = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
		const char *charchinese = ((CCString*)strings->objectForKey("dia4"))->getCString();
		chinese = CCLabelTTF::create(charchinese, "Arial", 22);
		chinese->setColor(c);
		chinese->setPosition(Vec2(mother1->getPosition().x + motherwidth, mother1->getPosition().y + motherheight*0.7));
		addChild(chinese, 1);

		

		std::string d = "dia_1.png";
		//label = Label::createWithTTF("1", "fonts/Marker Felt.ttf", 24);
		//label->setColor(Color3B::BLACK);
		sprite = ui::Scale9Sprite::create(d);
		Size extendsize = CCSizeMake(242, 183);
		sprite->setContentSize(extendsize);
		//this->addChild(label, 1);
		//label->setPosition(Vec2(mother1->getPosition().x + motherwidth/4*3, mother1->getPosition().y + motherheight / 2));
		sprite->setPosition(chinese->getPosition());
		this->addChild(sprite, 0);
	}
	else if (totalTime1 > 24 && totalTime1 < 25.1) {
		SimpleAudioEngine::getInstance()->playBackgroundMusic("music/dia/6.mp3", false);
		chinese->setVisible(false);
		this->removeChild(sprite);
		this->removeChild(chinese);
		CCDictionary *strings = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
		const char *charchinese = ((CCString*)strings->objectForKey("dia5"))->getCString();
		chinese = CCLabelTTF::create(charchinese, "Arial", 22);
		chinese->setColor(c);
		chinese->setPosition(Vec2(mother1->getPosition().x + motherwidth, mother1->getPosition().y + motherheight*0.7));
		addChild(chinese, 1);

		

		std::string d = "dia_1.png";
		//label = Label::createWithTTF("1", "fonts/Marker Felt.ttf", 24);
		//label->setColor(Color3B::BLACK);
		sprite = ui::Scale9Sprite::create(d);
		Size extendsize = CCSizeMake(242, 183);
		sprite->setContentSize(extendsize);
		//this->addChild(label, 1);
		//label->setPosition(Vec2(mother1->getPosition().x + motherwidth/4*3, mother1->getPosition().y + motherheight / 2));
		sprite->setPosition(chinese->getPosition());
		this->addChild(sprite, 0);
	}
	else if (totalTime1 > 31 && totalTime1 < 32.1) {
		chinese->setVisible(false);
		this->removeChild(sprite);
		this->removeChild(chinese);
		CCDictionary *strings = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
		const char *charchinese = ((CCString*)strings->objectForKey("dia6"))->getCString();
		chinese = CCLabelTTF::create(charchinese, "Arial", 22);
		chinese->setColor(c);
		chinese->setPosition(Vec2(mother1->getPosition().x + motherwidth, mother1->getPosition().y + motherheight*0.7));
		addChild(chinese, 1);

		std::string d = "dia_1.png";
		//label = Label::createWithTTF("1", "fonts/Marker Felt.ttf", 24);
		//label->setColor(Color3B::BLACK);
		sprite = ui::Scale9Sprite::create(d);
		Size extendsize = CCSizeMake(242, 183);
		sprite->setContentSize(extendsize);
		//this->addChild(label, 1);
		//label->setPosition(Vec2(mother1->getPosition().x + motherwidth/4*3, mother1->getPosition().y + motherheight / 2));
		sprite->setPosition(chinese->getPosition());
		this->addChild(sprite, 0);
	}
	else if (totalTime1 > 33 && totalTime1 < 34.1) {
		chinese->setVisible(false);
		this->removeChild(sprite);
		this->removeChild(chinese);
		CCDictionary *strings = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
		const char *charchinese = ((CCString*)strings->objectForKey("dia7"))->getCString();
		auto telnumber = database->getStringForKey("telNumber");
		telnumber = charchinese+telnumber;
		chinese = CCLabelTTF::create(telnumber, "Arial", 22);
		chinese->setColor(c);
		chinese->setPosition(Vec2(mother1->getPosition().x + motherwidth, mother1->getPosition().y + motherheight*0.7));
		addChild(chinese, 1);

		std::string d = "dia_1.png";
		//label = Label::createWithTTF("1", "fonts/Marker Felt.ttf", 24);
		//label->setColor(Color3B::BLACK);
		sprite = ui::Scale9Sprite::create(d);
		Size extendsize = CCSizeMake(242, 183);
		sprite->setContentSize(extendsize);
		//this->addChild(label, 1);
		//label->setPosition(Vec2(mother1->getPosition().x + motherwidth/4*3, mother1->getPosition().y + motherheight / 2));
		sprite->setPosition(chinese->getPosition());
		this->addChild(sprite, 0);
	}
	else if (totalTime1 > 37 && totalTime1 < 38.1) {
		chinese->setVisible(false);
		this->removeChild(sprite);
		this->removeChild(chinese);
		auto telnumber = database->getStringForKey("telNumber");
		CCDictionary *strings = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
		const char *charchinese = ((CCString*)strings->objectForKey("dia8"))->getCString();
		telnumber = telnumber + charchinese;
		chinese = CCLabelTTF::create(telnumber, "Arial", 22);
		chinese->setColor(c);
		chinese->setPosition(Vec2(mother1->getPosition().x + motherwidth, mother1->getPosition().y + motherheight*0.7));
		addChild(chinese, 1);

		SimpleAudioEngine::getInstance()->playBackgroundMusic("music/dia/5.mp3", false);

		std::string d = "dia_1.png";
		//label = Label::createWithTTF("1", "fonts/Marker Felt.ttf", 24);
		//label->setColor(Color3B::BLACK);
		sprite = ui::Scale9Sprite::create(d);
		Size extendsize = CCSizeMake(242, 183);
		sprite->setContentSize(extendsize);
		//this->addChild(label, 1);
		//label->setPosition(Vec2(mother1->getPosition().x + motherwidth/4*3, mother1->getPosition().y + motherheight / 2));
		sprite->setPosition(chinese->getPosition());
		this->addChild(sprite, 0);
	}
	else if (totalTime1 > 39) {
		click->setVisible(true);
		back_menu->setVisible(true);

	}
}

void beforezoo::returnto(Ref* ref)
{
	if (click->isVisible() == true) {
		SimpleAudioEngine::getInstance()->stopBackgroundMusic(false);
		this->stopAllActions();
		auto scene = ZooScene::createScene();
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
	}
}