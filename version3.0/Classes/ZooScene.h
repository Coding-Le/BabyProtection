#ifndef ZOO_SCENE_
#define ZOO_SCENE_

#include "cocos2d.h"
#include "ui\UIScale9Sprite.h"

class ZooScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ZooScene);
	void timer(float t);
	void pretimer(float t);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void addDog();
private:
	void ShowAnimal(std::string animal);
	cocos2d::Sprite* Girl;
	cocos2d::Sprite* Mother;
	cocos2d::SpriteFrame* StandMother;
	cocos2d::Sprite* Background;
	cocos2d::Sprite* Peacock;
	cocos2d::Sprite* MovingPeacock;
	cocos2d::Sprite* Dog;
	cocos2d::SpriteFrame* InvertGirl;
	cocos2d::Vector<cocos2d::SpriteFrame *> WGV;
	cocos2d::Vector<cocos2d::SpriteFrame*> WMV;
	cocos2d::Vector<cocos2d::SpriteFrame*> WPV;
	//cocos2d::Texture2D* PeaTexture[8];
	cocos2d::Vector<cocos2d::SpriteFrame *> WDV;
	cocos2d::Label* warning;
	int peacockSeq;
	bool isWarningMother;
	bool isMotherWalk;
	float BGlen;
	int steps;
	int countTime;
	int countWord;
	bool atAnimal;
	bool atPeacock;
	float BodyWidth;
	bool touchMother;
	bool beginLost;
	bool askMother;
	bool isGirlRun;
	bool touchDog;
	bool isDogTime;
	bool isDogExist;
	bool isDogStay;
	bool isGirlInvert;
	bool isAnimalShow;
	int starNum;
	cocos2d::Sprite* star;
	cocos2d::Sprite* starTalk;
	cocos2d::LabelTTF* grades;
	cocos2d::Size visibleSize;
	cocos2d::ui::Scale9Sprite* AnimalDia;
	cocos2d::Dictionary* sentence;
	cocos2d::LabelTTF* Word;
};


#endif