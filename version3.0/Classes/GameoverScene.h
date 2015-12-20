#ifndef GAME_OVER_
#define GAME_OVER_

#include "cocos2d.h"

class GameoverScene : public cocos2d::Layer
{
public:
	//static int kind;
	static void setKind(int k);
	static int kind;
	static cocos2d::Scene* createScene(int k);

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void menuBackCallback(cocos2d::Ref* pSender);
	void menuNextCallback(cocos2d::Ref* pSender);
	void menuAgainCallback(cocos2d::Ref* pSender);

	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event);


	// implement the "static create()" method manually
	CREATE_FUNC(GameoverScene);
};


#endif