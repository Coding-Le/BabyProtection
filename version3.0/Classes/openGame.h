#ifndef _OPENGAME_H
#define _OPENGAME_H

#include "cocos2d.h"

class openGame : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	openGame();
	void update(float delta);
	void preloadMusic();
	void playBgm();
	void playEffect();
private:
	cocos2d::Sprite* sprite1;
	cocos2d::Sprite* sprite2;
	cocos2d::Sprite* sprite3;
	cocos2d::Sprite* xiao;
	cocos2d::Sprite* horse;
	cocos2d::Sprite* da;
	cocos2d::Sprite* light;
	float time;
	cocos2d::LayerColor* whiteLayer;
	cocos2d::LayerColor* blackLayer;
	int change1;
	int change2;
	int change3;
	int change4;
	int change5;

};
#endif