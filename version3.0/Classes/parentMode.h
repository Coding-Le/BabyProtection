#include"cocos2d.h"
#include "DropDownList.h"
class parentMode : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void hintCallback(cocos2d::Ref* pSender);
	void testTouchEvent();
	void testKeyboardEvent();
	void testMouseEvent();
	void testCustomEvent();
	void testAccelerationEvent();
	void turnoff();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	CREATE_FUNC(parentMode);
	void Schedule();
	void updateTime1(float dt);
	void Level_1(Ref* ref);
	void timeset(Ref* ref);
	void parentstudy(Ref* ref);
	void message(Ref* ref);
	void menuCloseCallback(cocos2d::Ref* pSender);
	void CallbackShowMenu(Ref* sender);
	void returnto(Ref* ref);
private:
	cocos2d::Sprite* taglabel;
	cocos2d::EventDispatcher* dispatcher;
	cocos2d::MotionStreak* streak;
	cocos2d::Vec2 touch_pos;
	cocos2d::Size visibleSize;
	cocos2d::Sprite* test;
	cocos2d::LabelTTF* XV;
	cocos2d::LabelTTF* YV;
	cocos2d::LabelTTF* ZV;
	double X;
	double Y;
	double Z;
	cocos2d::TextFieldTTF* textEdit;
	cocos2d::TextFieldTTF* textEdit2;
	cocos2d::TextFieldTTF* textEdit3;
	cocos2d::TextFieldTTF* textEdit4;
	cocos2d::CustomDropDownListBox::DropDownList* list_box;
};