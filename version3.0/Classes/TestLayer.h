#ifndef ScrollView_TestLayer_h
#define ScrollView_TestLayer_h

#include "cocos2d.h"

USING_NS_CC;

class TestLayer : public CCLayerColor
{
public:
	TestLayer();
	~TestLayer();

	virtual bool init();

	CREATE_FUNC(TestLayer);

	// 初始化相关
	virtual void onEnter();
	virtual void onExit();
	void run();
	void Schedule();
	void updateTime1(float dt);
	// 触摸事件相关
	bool addimage(int flag);
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
	virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);
private:
	float totalTime1;
};

#endif