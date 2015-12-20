#include "HelloScene.h"
#pragma execution_character_set("utf-8") 
USING_NS_CC;

Scene* Hello::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Hello::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Hello::init()
{
	//////////////////////////////
	// 1. super init first

	if (!Layer::init())
	{
		return false;
	}
	totalTime1 = 0;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//标题
	auto label = Label::createWithBMFont("fonts/futura-48.fnt", "BabyProtection");
	//label->setTextColor(Color4B::ORANGE);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);



	//设置两个按钮，一个跳转，一个给出信息
	auto myitem1 = MenuItemLabel::create(Label::createWithSystemFont("Start", "Cobel", label->getContentSize().height), CC_CALLBACK_1(Hello::start, this));
	auto myitem2 = MenuItemLabel::create(Label::createWithTTF("About us", "fonts/KR Wreath Of Hearts.ttf", label->getContentSize().height*0.5), CC_CALLBACK_1(Hello::Move, this));

	//将两个按钮加到页面中
	auto menu1 = Menu::create(myitem1, NULL);
	menu1->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	menu1->alignItemsVerticallyWithPadding(label->getContentSize().height / 2);
	this->addChild(menu1, 1);
	auto menu2 = Menu::create(myitem2, NULL);
	menu2->setPosition(Director::getInstance()->getVisibleSize().width - 100, Director::getInstance()->getVisibleSize().height - 600);
	//menu2->alignItemsVerticallyWithPadding(label->getContentSize().height / 2);
	this->addChild(menu2, 1);


	//背景图片
	auto bgsprite = Sprite::create("gamescene/beginscene.png");
	float odds;
	float oddsY;
	oddsY = bgsprite->getContentSize().height / visibleSize.height;
	odds = bgsprite->getContentSize().width / visibleSize.width;
	bgsprite->setScaleY(1 / oddsY);
	bgsprite->setScaleX(1 / odds);
	bgsprite->setPosition(Vec2(visibleSize / 2) + origin);
	this->addChild(bgsprite, 0);


	timerStr1 = Label::createWithTTF("0%", "fonts/Marker Felt.ttf", 40);
	auto timerStrPos = Vec2(Director::getInstance()->getVisibleSize().width / 2, 100);
	//Point(Director::getInstance()->getVisibleSize().width / 5 * 4, Director::getInstance()->getVisibleSize().height / 5 * 2);
	timerStr1->setColor(Color3B::BLACK);
	timerStr1->setPosition(timerStrPos);
	this->addChild(timerStr1, 1);

	return true;
}

void Hello::updateTime1(float dt){
	totalTime1 += dt;
	if (totalTime1 > 10) {
		
	}
	char t[10];
	char* who = "%";
	int d = totalTime1 * 10;
	sprintf(t, "%d%s", d, who);
	timerStr1->setString(t);
}

void Hello::Schedule() {
	schedule(schedule_selector(Hello::updateTime1), 0.1f);
	auto progressSprite1 = Sprite::create("image/rge.png");
	auto pT1 = ProgressTimer::create(progressSprite1);
	pT1->setType(ProgressTimer::Type::BAR);
	pT1->setMidpoint(Point(0, 0));
	pT1->setBarChangeRate(Point(1, 0));
	pT1->runAction(RepeatForever::create(ProgressFromTo::create(10, 0, 100)));
	pT1->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, 100));
	this->addChild(pT1);
}

void Hello::start(Ref *ref) {
	//加一个Loading字样
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto label2 = Label::createWithBMFont("fonts/futura-48.fnt", "Loading...");
	//label2->setColor(Color3B::RED);
	label2->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - 500));
	this->addChild(label2, 1);
	//调用计时器
	Schedule();
}

void Hello::mymove(Ref *ref) {
	auto moveSprite = Sprite::create("image/elizabeth.png");
	moveSprite->setPosition(Director::getInstance()->getVisibleSize().width / 5, Director::getInstance()->getVisibleSize().height / 5);
	this->addChild(moveSprite, 1);
	auto actionTo = JumpTo::create(8, Point(Director::getInstance()->getVisibleSize().width / 5 * 4, Director::getInstance()->getVisibleSize().height / 5), 150, 8);
	auto action1 = RotateTo::create(8, 180);
	auto action4 = ScaleTo::create(2.0f, 2.0f);
	auto action2 = TintTo::create(2, 255, 0, 255);
	auto ac = Spawn::create(actionTo, action1, NULL);
	auto action3 = FadeOut::create(2.0f);
	//顺序执行以上两个动作之后，移除精灵.
	auto action = Sequence::create(action4, ac, action3, CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, moveSprite)), NULL);
	moveSprite->runAction(action);
}

void Hello::Move(Ref *ref){
	//这部分逻辑不是很清晰，点完about us该出现什么？
}
