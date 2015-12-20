#ifndef LOST_SCENE_
#define LOST_SCENE_

#include "cocos2d.h"
#include "ui\UIScale9Sprite.h"

class LostScene : public cocos2d::Layer
{
public:
	static int starNum;
	static cocos2d::Scene* createScene(int s);
	virtual bool init();
	void timer(float t);
	virtual void didAccelerate(cocos2d::Acceleration* acc, cocos2d::Event* event);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	CREATE_FUNC(LostScene);
private:
	void MoveClose();
	void ShowWord();
	void ContactStranger();
	void InitStranger();
	void InitCop();
	void checkPhone();
	cocos2d::Sprite* Background;
	cocos2d::Sprite* Girl;
	cocos2d::Sprite* Uncle;
	cocos2d::Sprite* Finger;
	cocos2d::Sprite* Cop;
	cocos2d::Vector<cocos2d::SpriteFrame *> WGV;
	cocos2d::Vector<cocos2d::SpriteFrame *> WUV;
	cocos2d::Vector<cocos2d::SpriteFrame *> WSV;
	cocos2d::Vector<cocos2d::SpriteFrame *> WBV;
	cocos2d::Vector<cocos2d::SpriteFrame *> WCV;
	cocos2d::Size visibleSize;
	int countTime;
	int countPerson;
	bool isCount;
	int countWord;
	int countGirlWord;
	bool isMoveClose;
	bool isReleaseLabel;
	bool isReject;
	bool touchStranger;
	bool touchCop;
	bool isStrangerTime;
	bool leaveStranger;
	bool isGirlRun;
	bool isWin;
	bool isWinRemind;
	void WinRemind(float t);
	void Remind();
	cocos2d::TextFieldTTF* phoneEdit;
	cocos2d::ui::Scale9Sprite* Dialog;
	cocos2d::ui::Scale9Sprite* Girldia;
	cocos2d::ui::Scale9Sprite* PhoneDia;
	cocos2d::LabelTTF* Word;
	cocos2d::Texture2D* cache[6];
	cocos2d::Dictionary* sentence;
	cocos2d::Sprite* star;
	cocos2d::Sprite* starTalk;
	cocos2d::LabelTTF* grades;
};

#endif