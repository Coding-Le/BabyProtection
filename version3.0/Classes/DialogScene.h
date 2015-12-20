#ifndef __DIALOG_SCENE_H__
#define __DIALOG_SCENE_H__

#include "cocos2d.h"

class DialogScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
	CREATE_FUNC(DialogScene);
};

#endif // __HELLOWORLD_SCENE_H__
