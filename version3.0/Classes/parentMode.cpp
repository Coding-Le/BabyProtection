#include"parentMode.h"
#include"Timeset.h"
#pragma execution_character_set("utf-8")
USING_NS_CC;
#define H_PI 1.570796327f
//#include"FlowWord.h"
#include "DropDownList.h"
#include"ScrollViewScene.h"
#include"HelloWorldScene.h"
#include"parentstudy.h"
#include"introduction.h"
#define database UserDefault::getInstance()
Scene* parentMode::createScene(){
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = parentMode::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool parentMode::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	dispatcher = Director::getInstance()->getEventDispatcher();

	
	//log("%s", FileUtils::getInstance()->getWritablePath().c_str());
	//auto path = FileUtils::getInstance()->getWritablePath() + "/UserDefault.xml";

	auto background = Sprite::create("parent_read/login.png");
	float x = visibleSize.width / background->getContentSize().width;
	float y = visibleSize.height / background->getContentSize().height;
	background->setScale(x, y);
	background->setAnchorPoint(Vec2::ZERO);
	background->setPosition(Vec2::ZERO);
	this->addChild(background);

	taglabel = Sprite::create("parentmode/11.png");
	float xx = visibleSize.width / taglabel->getContentSize().width;
	float yy = visibleSize.height / taglabel->getContentSize().height;
	taglabel->setScale(xx/2,yy);
	taglabel->setAnchorPoint(Vec2::ZERO);
	taglabel->setPosition(Vec2::ZERO);
	this->addChild(taglabel);



	auto panel = Sprite::create("parentmode/11.png");
	panel->setPosition(visibleSize.width / 5 * 3, visibleSize.height / 2);

	auto label2 = Label::createWithTTF("选择家长", "fonts/my_font3.ttf", 24);
	label2->setPosition(Vec2(panel->getPosition().x-panel->getContentSize().width/1.7+label2->getContentSize().width, panel->getPosition().y+panel->getContentSize().height/3));
	this->addChild(label2, 1);
	label2->setVisible(false);

	//auto label3 = Label::createWithTTF("联系方式", "fonts/my_font3.ttf", 24);
	//label3->setPosition(Vec2(panel->getPosition().x - panel->getContentSize().width / 1.7 + label2->getContentSize().width, panel->getPosition().y + panel->getContentSize().height / 12));
	//this->addChild(label3, 3);

	//auto label4 = Label::createWithTTF("家庭住址", "fonts/my_font3.ttf", 24);
	//label4->setPosition(Vec2(panel->getPosition().x - panel->getContentSize().width / 1.7 + label2->getContentSize().width, panel->getPosition().y-panel->getContentSize().height / 6));
	//this->addChild(label4, 3);

	auto level_1 = MenuItemImage::create(
		"my_button.png", "my_button3.png", "my_button2.png", CC_CALLBACK_1(parentMode::Level_1, this));
	auto menuWidth = visibleSize.width / 38 * 4.6;
	auto menuHeight = visibleSize.height / 19 * 2;
	level_1->setScale(menuWidth / level_1->getContentSize().width, menuHeight / level_1->getContentSize().height);
	//creat Level_2
	auto level_2 = MenuItemImage::create(
		"my_button.png", "my_button3.png", "my_button2.png", CC_CALLBACK_1(parentMode::Level_1, this));
	level_2->setEnabled(false);

	auto menu = Menu::create(level_1, NULL);
	menu->alignItemsHorizontallyWithPadding(level_1->getContentSize().width);
	menu->setPosition(Vec2(visibleSize.width/38*20.72,visibleSize.height/19*2.95));
	this->addChild(menu, 3);

	auto close_item = MenuItemImage::create("CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(parentMode::menuCloseCallback,
		this));
	close_item->setPosition(
		Vec2(origin.x + visibleSize.width - close_item->getContentSize().width / 2,
		origin.y + close_item->getContentSize().height / 2));
	// create menu, it's an autorelease object
	auto mymenu = Menu::create(close_item, NULL);
	mymenu->setPosition(Vec2::ZERO);
	this->addChild(mymenu, 1);
	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	//创建一个label作为下拉菜单的默认选项
	auto label = Label::createWithTTF("妈妈",
		"fonts/my_font3.ttf",
		36);
	label->setColor(Color3B::BLACK);
	label->setTextColor(Color4B::BLACK);
	//设置大小
	auto box_size = Size(visibleSize.width/38*5.15,
		visibleSize.height/19*1.05);

	//
	list_box = CustomDropDownListBox::DropDownList::Create(label,
		box_size,
		Size(visibleSize.width / 38 * 5.15,
		visibleSize.height / 19 * 1.05));


	//添加一堆label进去
	CCDictionary *strings = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
	const char *charchinese = ((CCString*)strings->objectForKey("parent1"))->getCString();
	auto labell0 = Label::create(charchinese, "Arial", 18);
	labell0->setColor(Color3B::BLACK);
	//auto labell0 = Label::createWithTTF();
	list_box->AddLabel(labell0);//不知道怎么把默认显示的label添加到选项里，只好再添加一个

	CCDictionary *strings1 = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
	const char *charchinese1 = ((CCString*)strings1->objectForKey("parent2"))->getCString();
	auto labell1 = Label::create(charchinese1, "Arial", 18);
	labell1->setColor(Color3B::BLACK);
	list_box->AddLabel(labell1);

	CCDictionary *strings2 = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
	const char *charchinese2 = ((CCString*)strings2->objectForKey("parent3"))->getCString();
	auto labell2 = Label::create(charchinese2, "Arial", 18);
	labell2->setColor(Color3B::BLACK);
	list_box->AddLabel(labell2);
	
	CCDictionary *strings3 = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
	const char *charchinese3 = ((CCString*)strings3->objectForKey("parent4"))->getCString();
	auto labell3 = Label::create(charchinese3, "Arial", 18);
	labell3->setColor(Color3B::BLACK);
	list_box->AddLabel(labell3);

	CCDictionary *strings4 = CCDictionary::createWithContentsOfFile("fonts/chinese.xml");
	const char *charchinese4 = ((CCString*)strings4->objectForKey("parent5"))->getCString();
	auto labell4 = Label::create(charchinese4, "Arial", 18);
	labell4->setColor(Color3B::BLACK);
	list_box->AddLabel(labell4);

	// 设置位置
	list_box->setPosition(
		Vec2(visibleSize.width/38*14.45, 
		visibleSize.height/19*13.85));
	this->addChild(list_box,
		4);
	//启动监听
	list_box->OpenListener();

	testTouchEvent();



	/*auto timesetLabel = MenuItemImage::create(
		"my_button.png", "my_button3.png", "my_button2.png", CC_CALLBACK_1(parentMode::timeset, this));
	auto timesetmenu = Menu::create(timesetLabel, NULL);
	timesetmenu->alignItemsHorizontallyWithPadding(timesetLabel->getContentSize().width / 3 * 2);
	timesetmenu->setPosition(Vec2(100, visibleSize.height / 4 * 3));
	this->addChild(timesetmenu, 3);

	auto messagelabel = MenuItemImage::create(
		"my_button.png", "my_button3.png", "my_button2.png", CC_CALLBACK_1(parentMode::message, this));
	auto messagemenu = Menu::create(messagelabel, NULL);
	messagemenu->alignItemsHorizontallyWithPadding(messagelabel->getContentSize().width / 3 * 2);
	messagemenu->setPosition(Vec2(100, visibleSize.height / 4 * 2));
	this->addChild(messagemenu, 3);

	auto parentstudylabel = MenuItemImage::create(
		"my_button.png", "my_button3.png", "my_button2.png", CC_CALLBACK_1(parentMode::parentstudy, this));
	auto parentstudymenu = Menu::create(parentstudylabel, NULL);
	parentstudymenu->alignItemsHorizontallyWithPadding(parentstudylabel->getContentSize().width / 3 * 2);
	parentstudymenu->setPosition(Vec2(100, visibleSize.height / 4));
	this->addChild(parentstudymenu, 3);*/



	auto back = MenuItemImage::create("timeset/back.png", "timeset/back.png", CC_CALLBACK_1(parentMode::returnto, this));
	back->setScale(0.2*visibleSize.height/back->getContentSize().height);
	auto back_menu = Menu::create(back, NULL);
	back_menu->setPosition(Vec2(back->getBoundingBox().size.width/2, visibleSize.height - back->getBoundingBox().size.height/2));
	this->addChild(back_menu, 3);

	//CCDictionary *xmlstrings = CCDictionary::createWithContentsOfFile(path.c_str());
	if (!database->getBoolForKey("isExist")){
		database->setBoolForKey("isExist", true);
		database->setStringForKey("babyName", "Child's name");
		database->setStringForKey("telNumber", "Tel number");
		database->setStringForKey("address", "Address");
		database->setStringForKey("password", "Password");
		database->setIntegerForKey("indexs", 0);
	}

	list_box->SetSelectedIndex(database->getIntegerForKey("indexs"));

	auto childname = database->getStringForKey("babyName");
	textEdit = TextFieldTTF::textFieldWithPlaceHolder(childname, "fonts/arial.ttf", 36);
	textEdit->setPosition(Vec2(visibleSize.width/38*27.95,visibleSize.height/19*14.35));
	this->addChild(textEdit, 10);
	setTouchMode(kCCTouchesOneByOne);
	setTouchEnabled(true);

	auto telNumber = database->getStringForKey("telNumber");
	textEdit2 = TextFieldTTF::textFieldWithPlaceHolder(telNumber, "fonts/arial.ttf", 36);
	textEdit2->setPosition(Vec2(visibleSize.width / 38 * 17.78, visibleSize.height / 19 * 10.79));
	this->addChild(textEdit2, 10);
	setTouchMode(kCCTouchesOneByOne);
	setTouchEnabled(true);

	auto address = database->getStringForKey("address");
	textEdit3 = TextFieldTTF::textFieldWithPlaceHolder(address, "fonts/arial.ttf", 36);
	textEdit3->setPosition(Vec2(visibleSize.width/38*20.58,visibleSize.height/19*6.85));
	this->addChild(textEdit3, 10);
	setTouchMode(kCCTouchesOneByOne);
	setTouchEnabled(true);

	auto password = database->getStringForKey("password");
	if (password != "Password") {
		for (int i = 0; i < password.length(); i++) {
			password.at(i) = '*';
		}
	}
	textEdit4 = TextFieldTTF::textFieldWithPlaceHolder(password, "fonts/arial.ttf", 36);
	textEdit4->setPosition(Vec2(visibleSize.width / 38 * 29.1, visibleSize.height / 19 * 10.79));
	this->addChild(textEdit4, 10);
	setTouchMode(kCCTouchesOneByOne);
	setTouchEnabled(true);

	return true;
}
void parentMode::returnto(Ref* ref)
{
	this->stopAllActions();
	auto scene = HelloWorld::createScene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
}

void parentMode::timeset(Ref* ref)
{
	this->stopAllActions();
	auto scene = Timeset::createScene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
}
void parentMode::message(Ref* ref)
{
	
}
void parentMode::parentstudy(Ref *ref) {
	this->stopAllActions();
	auto scene = parentstudy::createScene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
}


void parentMode::testTouchEvent()
{
	streak = MotionStreak::create(0.5f, 10, 30, Color3B::WHITE, "Demo/flash.png");
	this->addChild(streak, 2);
	//10.55 9.1 7.65 6.24 4.75
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event){
		touch_pos = touch->getLocation();
		//滑动拖尾效果
		if (touch_pos.x > 0 && touch_pos.x < visibleSize.width /2 *4.2/17.64) {
			if (touch_pos.y > visibleSize.height / 14.1*9.1 && touch_pos.y < visibleSize.height / 14.1*10.55) {

			}
			else if (touch_pos.y > visibleSize.height / 14.1*7.65 && touch_pos.y < visibleSize.height / 14.1*9.1) {
				timeset(this);
			}
			else if (touch_pos.y > visibleSize.height / 14.1*6.24 && touch_pos.y < visibleSize.height / 14.1*7.65) {
				parentstudy(this);
			}
			else if (touch_pos.y > visibleSize.height / 14.1*4.75 && touch_pos.y < visibleSize.height / 14.1*6.24) {
				this->stopAllActions();
				auto scene = introduction::createScene();
				CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1, scene, Color3B::GRAY));
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


void parentMode::CallbackShowMenu(Ref* sender)
{
	this->setPosition(-100, this->getPosition().y);
}

void parentMode::menuCloseCallback(Ref* pSender)
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

void parentMode::Level_1(Ref* ref)
{
	
	auto temp1 = textEdit->getString();
	if (temp1.length() > 1) {
		database->setStringForKey("babyName", temp1);
	}
	auto temp2 = textEdit2->getString();
	if (temp2.length() > 1) {
		database->setStringForKey("telNumber", temp2);
	}
	auto temp3 = textEdit3->getString();
	if (temp3.length() > 1) {
		database->setStringForKey("address", temp3);
	}
	auto temp4 = textEdit4->getString();
	if (temp4.length() > 1) {
		database->setStringForKey("password", temp4);
	}
	database->setIntegerForKey("indexs", list_box->GetSelectedIndex());
}

bool parentMode::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	bool isClicked = textEdit->boundingBox().containsPoint(touch->getLocation());
	//如果点中了控件
	if (isClicked)
	{
		//弹出软键盘
		textEdit->attachWithIME();
		textEdit->setTextColor(Color4B::BLACK);
		
	}
	bool isClicked2 = textEdit2->boundingBox().containsPoint(touch->getLocation());
	//如果点中了控件
	if (isClicked2)
	{
		//弹出软键盘
		textEdit2->attachWithIME();
		textEdit2->setTextColor(Color4B::BLACK);
		
	}
	bool isClicked3 = textEdit3->boundingBox().containsPoint(touch->getLocation());
	//如果点中了控件
	if (isClicked3)
	{
		//弹出软键盘
		textEdit3->attachWithIME();
		textEdit3->setTextColor(Color4B::BLACK);
	}
	//表示接受触摸消息
	bool isClicked4 = textEdit4->boundingBox().containsPoint(touch->getLocation());
	if (isClicked4)
	{
		//弹出软键盘
		textEdit4->attachWithIME();
		textEdit4->setTextColor(Color4B::BLACK);
	}
	return true;
}

void parentMode::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

void parentMode::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{

}
