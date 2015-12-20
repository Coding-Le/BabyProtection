#ifndef _LOADING_H
#define _LOADING_H

#include "cocos2d.h"

class loading : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	loading();
	void update(float delta);
	void loadingCallBack(cocos2d::Texture2D* texture);
	void gotoNewPage();
private:
	cocos2d::ProgressTimer* progressLoading;
	cocos2d::Sprite* girl;
	cocos2d::Sprite* borderForload;
	cocos2d::LayerColor* whiteLayer;
	cocos2d::Label* Loading;
	cocos2d::Action* girlMove;
	float timeAll;
	bool add;
	int numSprite;
	int loadedSprite;
};
#endif