#include"cocos2d.h"
class Timeset : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void hintCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(Timeset);
	void Schedule();
	void updateTime1(float dt);
	void Level_1(Ref* ref);
	void returnto(Ref* ref);
	void testTouchEvent();
	void menuCloseCallback(cocos2d::Ref* pSender);
	void CallbackShowMenu(Ref* sender);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
private:
	cocos2d::Sprite* taglabel;
	cocos2d::EventDispatcher* dispatcher;
	cocos2d::MotionStreak* streak;
	cocos2d::Vec2 touch_pos;
	cocos2d::Size visibleSize;
	cocos2d::Sprite* shadow;
	cocos2d::Sprite* timeshadow;
	cocos2d::Sprite* testshadow;
	float x;
	float y;
	float flag;
	float flag2;
};