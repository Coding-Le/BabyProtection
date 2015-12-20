#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	cocos2d::Sprite* about;

	void clickAboutContent(cocos2d::Ref* pSender);
	void clickAboutBtn(cocos2d::Ref* pSender);
	void parentMode_func(Ref *ref);
	void Schedule();
	void updateTime1(float dt);
	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);
	void preloadMusic();
	void playBgm();
	void playEffect();
	void testTouchEvent();
	void testKeyboardEvent();
	void testMouseEvent();
	void testCustomEvent();
	void testAccelerationEvent();
	void turnoff();
	void goahead(Ref* ref);
	void quitgame(Ref* ref);
private:
	float totalTime1;
	cocos2d::Label* timerStr1;
	cocos2d::Label* label2;
	cocos2d::Label* label1;
	cocos2d::Label* label3;
	cocos2d::Label* label4;
	cocos2d::Sprite* moonLabel;

	cocos2d::EventDispatcher* dispatcher;
	cocos2d::MotionStreak* streak;
	cocos2d::Vec2 touch_pos;
	bool isTouching;
	bool isCut;
	cocos2d::Sprite* rope;
	cocos2d::Sprite* man;
	cocos2d::Sprite* box;
	cocos2d::MenuItemImage* startgame;
	cocos2d::Sprite* ufoLabel;
	cocos2d::Sprite* info;
};

#endif
