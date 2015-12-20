#ifndef _DIALOG_LAYER_H
#define _DIALOT_LAYER_H

#include "cocos2d.h"

class DialogLayer : public cocos2d::Layer
{
public:
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(DialogLayer);
	//virtual bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	//virtual void onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	//virtual void onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	//void onEnter();
	cocos2d::Menu *menu;
	//void registerWithTouchDispatcher();
};


#endif