#ifndef ScrollView_ScrollViewScene_h
#define ScrollView_ScrollViewScene_h

#include "cocos2d.h"

USING_NS_CC;

class ScrollViewScene : public CCScene
{

public:
	ScrollViewScene();
	~ScrollViewScene();
	virtual bool init();
	void returnto(Ref* ref);
	void girlwalk();
	void Schedule();
	void updateTime1(float dt);
	CREATE_FUNC(ScrollViewScene);
private:
	float totalTime1;
};

#endif