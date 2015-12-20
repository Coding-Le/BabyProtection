#include"cocos2d.h"
class beforezoo : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void hintCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(beforezoo);
	void Schedule();
	void returnto(Ref* ref);
	void updateTime1(float dt);
	void preloadMusic();
	void playBgm();
	void playEffect();
private:
	cocos2d::MenuItemImage* hint;
	cocos2d::Menu* hint_menu;
	float totalTime1;
	float motherwidth;
	float motherheight;
	cocos2d::Sprite* girl1;
	cocos2d::Sprite* mother1;
	cocos2d::ui::Scale9Sprite* sprite;
	cocos2d::CCLabelTTF*  chinese;
	cocos2d::MenuItemImage* back;
	cocos2d::Menu* back_menu;
	cocos2d::Sprite* click;
};