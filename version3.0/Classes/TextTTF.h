#ifndef __TextTTF_H__
#define __TextTTF_H__
#include "cocos2d.h"
USING_NS_CC;
class TextTTF : public CCLayer
{
public:
	bool init();
	static CCScene* scene();
	//用于处理触摸事件
	bool ccTouchBegan(CCTouch*, CCEvent*);
	//用于在程序中创建一个文本控件
	CCTextFieldTTF* textEdit;
	CREATE_FUNC(TextTTF);
};
#endif // __HELLOWORLD_SCENE_H__