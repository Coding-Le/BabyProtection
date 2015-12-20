#include "TextTTF.h"
#include"cocos2d.h"
CCScene* TextTTF::scene()
{
	CCScene* scene = CCScene::create();
	TextTTF* layer = TextTTF::create();
	scene->addChild(layer);
	return scene;
}
bool TextTTF::init()
{
	//初始化父类层
	CCLayer::init();
	//得到窗口的尺寸
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	//创建文本框
	//第一个参数：文本框中显示的内容
	//第二个参数：字体
	//第三个参数：文本的大小
	textEdit = CCTextFieldTTF::textFieldWithPlaceHolder("Please input your name:",
		"Arial", 36);
	//设置文本框的位置
	textEdit->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	//添加文本框到层上
	addChild(textEdit);
	//当触摸到控件的时候弹出软键盘
	setTouchMode(kCCTouchesOneByOne);
	setTouchEnabled(true);
	return true;
}
bool TextTTF::ccTouchBegan(CCTouch* touch, CCEvent* ev)
{
	//用于判断是否点中了控件
	bool isClicked = textEdit->boundingBox().containsPoint(touch->getLocation());
	//如果点中了控件
	if (isClicked)
	{
		//弹出软键盘
		textEdit->attachWithIME();
	}
	//表示接受触摸消息
	return true;
}
