#ifndef ScrollView_ScrollView_h
#define ScrollView_ScrollView_h

#include "cocos2d.h"

USING_NS_CC;



// �������
const int TOUCH_DELTA = 5;

class ScrollView : public CCLayer
{
private:
	// ���µ�
	Point m_TouchDownPoint;
	// ̧��� ���ʹ���ж��Ƿ�Ϊ����¼�
	Point m_TouchUpPoint;
	// ��ǰ������
	Point m_TouchCurPoint;

private:
	// ��ҳ��
	int m_Page;
	// ��ǰ��ʾҳ
	int m_CurPage;

private:
	// �洢����ҳ��
	CCArray *m_PageLayer;

private:
	// ��תҳ
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
	// ��ʼ�����
	virtual void onEnter();
	virtual void onExit();

	// �����¼����
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
	virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);

public:
	// ����ҳ
	void addPage(Layer *pPageLayer);
};

#endif