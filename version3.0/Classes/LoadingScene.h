#ifndef LOADING_SCENE_
#define LOADING_SCENE_

#include "cocos2d.h"

class LoadingScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene(int s);
	static int starNum;
	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(LoadingScene);
	void loading();
	void loadedCallBack();
private:
	int totalNum;
	int loadedNum;
	bool canLeave;
	void decideLeave(float t);
	int countTime;
	cocos2d::Sprite* star;
	cocos2d::LabelTTF* grades;
};


#endif