#ifndef __TextTTF_H__
#define __TextTTF_H__
#include "cocos2d.h"
USING_NS_CC;
class TextTTF : public CCLayer
{
public:
	bool init();
	static CCScene* scene();
	//���ڴ��������¼�
	bool ccTouchBegan(CCTouch*, CCEvent*);
	//�����ڳ����д���һ���ı��ؼ�
	CCTextFieldTTF* textEdit;
	CREATE_FUNC(TextTTF);
};
#endif // __HELLOWORLD_SCENE_H__