#ifndef ScrollView_ScrollView_h
#define ScrollView_ScrollView_h

#include "cocos2d.h"

USING_NS_CC;



// 触摸误差
const int TOUCH_DELTA = 5;

class ScrollView : public CCLayer
{
private:
	// 按下点
	Point m_TouchDownPoint;
	// 抬起点 配合使用判断是否为点击事件
	Point m_TouchUpPoint;
	// 当前触摸点
	Point m_TouchCurPoint;

private:
	// 总页数
	int m_Page;
	// 当前显示页
	int m_CurPage;

private:
	// 存储所有页层
	CCArray *m_PageLayer;

private:
	// 跳转页
	void goToPage();
	float totalTime1;
	int myx;
public:
	static float WINDOW_WIDTH;
	static float WINDOW_HEIGHT;
	static float LOC_HEIGHT;
	static void setWindow(float w, float h, float l);
	void run();
	void Schedule();
	void updateTime1(float dt);
public:
	ScrollView();
	~ScrollView();

	virtual bool init();

	CREATE_FUNC(ScrollView);

public:
	// 初始化相关
	virtual void onEnter();
	virtual void onExit();

	// 触摸事件相关
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
	virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);

public:
	// 添加页
	void addPage(Layer *pPageLayer);
};

#endif