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
	//��ʼ�������
	CCLayer::init();
	//�õ����ڵĳߴ�
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	//�����ı���
	//��һ���������ı�������ʾ������
	//�ڶ�������������
	//�������������ı��Ĵ�С
	textEdit = CCTextFieldTTF::textFieldWithPlaceHolder("Please input your name:",
		"Arial", 36);
	//�����ı����λ��
	textEdit->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	//�����ı��򵽲���
	addChild(textEdit);
	//���������ؼ���ʱ�򵯳�������
	setTouchMode(kCCTouchesOneByOne);
	setTouchEnabled(true);
	return true;
}
bool TextTTF::ccTouchBegan(CCTouch* touch, CCEvent* ev)
{
	//�����ж��Ƿ�����˿ؼ�
	bool isClicked = textEdit->boundingBox().containsPoint(touch->getLocation());
	//��������˿ؼ�
	if (isClicked)
	{
		//����������
		textEdit->attachWithIME();
	}
	//��ʾ���ܴ�����Ϣ
	return true;
}