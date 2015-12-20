#include "LostScene.h"
#include "GameoverScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
#define database UserDefault::getInstance()
int LostScene::starNum = 0;

Scene* LostScene::createScene(int s)
{
	auto scene = Scene::create();
	LostScene::starNum = s;
	auto layer = LostScene::create();
	scene->addChild(layer);
	return scene;
}

bool LostScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();

	Background = Sprite::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/1.jpg"));
	Background->setScaleX(visibleSize.width / Background->getContentSize().width);
	Background->setScaleY(visibleSize.height / Background->getContentSize().height);
	Background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(Background);
	Rect bgrect(0, 0, Background->getContentSize().width, Background->getContentSize().height);
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/1.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/2.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/3.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/4.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/5.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/6.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/7.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/8.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/9.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/10.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/11.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/12.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/13.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/14.jpg"), bgrect));
	WBV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("lost/background/15.jpg"), bgrect));
	auto BgAction = Animation::createWithSpriteFrames(WBV, 0.20f);
	auto BgAnimate = Animate::create(BgAction);
	Background->runAction(RepeatForever::create(BgAnimate));

	Girl = Sprite::createWithTexture(TextureCache::getInstance()->getTextureForKey("baby/Girl/stand.png"));
	float factor = visibleSize.height * 0.30f / Girl->getContentSize().height;
	Girl->setScaleX(factor);
	Girl->setScaleY(factor);
	this->addChild(Girl);
	Girl->setPosition(Vec2(visibleSize.width / 5, visibleSize.height * 0.11 + Girl->getBoundingBox().getMaxY() - Girl->getBoundingBox().getMidY()));
	Rect gr = Rect(0, 0, Girl->getContentSize().width, Girl->getContentSize().height);
	WGV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("baby/Girl/stand.png"), gr));
	WGV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("baby/Girl/1.png"), gr));
	WGV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("baby/Girl/2.png"), gr));
	WGV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("baby/Girl/3.png"), gr));
	WGV.pushBack(SpriteFrame::createWithTexture(TextureCache::getInstance()->getTextureForKey("baby/Girl/4.png"), gr));
	Texture2D* temp;
    temp = TextureCache::getInstance()->getTextureForKey("lost/badguy/c1.png");
    WCV.pushBack(SpriteFrame::createWithTexture(temp, Rect(0,0,temp->getContentSize().width, temp->getContentSize().height)));
    temp = TextureCache::getInstance()->getTextureForKey("lost/badguy/c2.png");
    WCV.pushBack(SpriteFrame::createWithTexture(temp, Rect(0, 0, temp->getContentSize().width, temp->getContentSize().height)));
    temp = TextureCache::getInstance()->getTextureForKey("lost/badguy/c3.png");
    WCV.pushBack(SpriteFrame::createWithTexture(temp, Rect(0, 0, temp->getContentSize().width, temp->getContentSize().height)));
    temp = TextureCache::getInstance()->getTextureForKey("lost/badguy/c4.png");
    WCV.pushBack(SpriteFrame::createWithTexture(temp, Rect(0, 0, temp->getContentSize().width, temp->getContentSize().height)));
	auto GirlAction = Animation::createWithSpriteFrames(WGV, 0.20f);
	auto GirlAnimate = Animate::create(GirlAction);
	Girl->runAction(RepeatForever::create(GirlAnimate));

	countTime = 0;
	this->schedule(schedule_selector(LostScene::timer), 0.2f);
	cache[0] = TextureCache::getInstance()->getTextureForKey("lost/uncle/stand.png");
	//cache[0] = TextureCache::getInstance()->addImage("lost/uncle/stand.png");
	cache[1] = TextureCache::getInstance()->getTextureForKey("lost/uncle/1.png");
	cache[2] = TextureCache::getInstance()->getTextureForKey("lost/uncle/2.png");
	cache[3] = TextureCache::getInstance()->getTextureForKey("lost/uncle/3.png");
	cache[4] = TextureCache::getInstance()->getTextureForKey("lost/uncle/4.png");
	isCount = true;
	isMoveClose = true;

	star = Sprite::create("star.png");
	star->setScaleX(visibleSize.width * 0.05f / star->getContentSize().width);
	star->setScaleY(visibleSize.height * 0.08f / star->getContentSize().height);
	this->addChild(star);
	star->setPosition(Vec2(star->getBoundingBox().getMidX() - star->getBoundingBox().getMinX() + visibleSize.width * 0.02f, visibleSize.height - star->getBoundingBox().getMidY() + star->getBoundingBox().getMinY() - visibleSize.height * 0.02f));
	starTalk = 0;
	char num[10];
	snprintf(num, 9, "%d", LostScene::starNum);
	grades = LabelTTF::create(num, "fonts/arial.ttf", 24);
	this->addChild(grades);
	grades->setPosition(Vec2(star->getPositionX(), star->getPositionY() - grades->getContentSize().height * 1.5f));
	grades->setColor(Color3B::RED);

	Dialog = ui::Scale9Sprite::create("Dia.png");
	float scaled = Dialog->getContentSize().width / 285.0f;
	Dialog->setInsetLeft(20.0f * scaled);
	Dialog->setInsetBottom(20.0f * scaled);
	Dialog->setInsetRight(25.0f * scaled);
	Dialog->setInsetTop(20.0f * scaled);
	Dialog->setAnchorPoint(Vec2(1.0f, 0.0f));
	this->addChild(Dialog, 2);
	//CCLOG("%f %f\n", Dialog->getContentSize().width, Dialog->getContentSize().height);
	Dialog->setVisible(false);

	Girldia = ui::Scale9Sprite::create("Girldia.png");
	scaled = Girldia->getContentSize().width / 480.0f;
	Girldia->setInsetLeft(20.0f * scaled);
	Girldia->setInsetBottom(20.0f * scaled);
	Girldia->setInsetTop(20.0f * scaled);
	Girldia->setInsetRight(20.0f * scaled);
	this->addChild(Girldia, 2);
	Girldia->setVisible(false);
	Girldia->setAnchorPoint(Vec2(0.0f, 0.0f));
	Word = 0;
	sentence = Dictionary::createWithContentsOfFile("lost/lost.xml");
	sentence->retain();
	countWord = 0;
	Device::setAccelerometerEnabled(true);
	auto listener1 = EventListenerAcceleration::create(CC_CALLBACK_2(LostScene::didAccelerate, this));
	//在事件监听器中注册
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
	PhoneDia = cocos2d::ui::Scale9Sprite::create("phone.png");
	scaled = PhoneDia->getContentSize().width / 148.0f;
	PhoneDia->setInsetLeft(20.0f * scaled);
	PhoneDia->setInsetBottom(20.0f * scaled);
	PhoneDia->setInsetTop(20.0f * scaled);
	PhoneDia->setInsetRight(20.0f * scaled);
	this->addChild(PhoneDia, 2);
	PhoneDia->setVisible(false);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(LostScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(LostScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(LostScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	isReject = false;
	touchStranger = false;
	isStrangerTime = false;
	leaveStranger = false;
	countPerson = 0;
	Uncle = 0;
	countGirlWord = 0;
	touchCop = false;
	isGirlRun = true;
	phoneEdit = 0;
	isWin = false;
	return true;
}

bool LostScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	if (phoneEdit)
	{
		if (phoneEdit->boundingBox().containsPoint(touch->getLocation()))
		{
			phoneEdit->attachWithIME();
		}
	}
	return true;
}

void LostScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

void LostScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	if (!isCount)
	{
		if (isStrangerTime)
		{
			if (Uncle->getBoundingBox().containsPoint(touch->getLocation()))
			{
				//isReject = true;
				touchStranger = true;
			}
		}
		if (countTime == 41)
		{
			if (Cop->getBoundingBox().containsPoint(touch->getLocation()))
			{
				touchCop = true;
				this->removeChild(Finger);
			}
		}
	}
}

void LostScene::didAccelerate(Acceleration* acc, Event* event)
{
	if (!isCount)
	{
		if (abs(acc->x) >= 0.5 || abs(acc->y) >= 0.5)
		{
			if (isStrangerTime)
			{
				isReject = true;
				//Dialog->setVisible(true);
			}
		}
	}
}


void LostScene::timer(float t)
{
	if (countTime == 10 || countTime == 20 || countTime == 30)
	{
		InitStranger();
		countPerson++;
	}
	if (countTime == 40)
	{
		InitCop();
		countTime++;
		isCount = false;
	}
	if (isCount)
	{
		countTime++;
	}
	else
	{
		if (countTime == 11 || countTime == 21 || countTime == 31)
		{
			if (isMoveClose)
			{
				MoveClose();
			}
			else
			{
				if (countWord <= 34)
				{
					ShowWord();
				}
				else if (countWord == 35)
				{
					this->removeChild(Word);
					Dialog->setVisible(false);
					countWord++;
				}
				else if (countWord <= 45)
				{
					Remind();
				}
				else
				{
					ContactStranger();
				}
			}
		}
		else if (countTime == 41)
		{
			if (!touchCop && isGirlRun)
			{
				Girl->stopAllActions();
				Girl->setSpriteFrame(WGV.at(0));
				isGirlRun = false;
			}
			if (touchCop)
			{
				if (Cop->getPositionX() - Girl->getPositionX() > visibleSize.width * 0.25f)
				{
					if (!isGirlRun)
					{
						auto GirlAction = Animation::createWithSpriteFrames(WGV, 0.20f);
						auto GirlAnimate = Animate::create(GirlAction);
						Girl->runAction(RepeatForever::create(GirlAnimate));
						isGirlRun = true;
					}
					Girl->setPositionX(Girl->getPositionX() + visibleSize.width * 0.02f);
				}
				else
				{
					if (isGirlRun)
					{
						Girl->stopAllActions();
						Girl->setSpriteFrame(WGV.at(0));
						isGirlRun = false;
					}
					if (countWord == 0)
					{
						const char* content = ((String*)sentence->objectForKey("Girl4"))->getCString();
						if (Word)
						{
							this->removeChild(Word);
						}
						Word = LabelTTF::create(content, "fonts/arial.ttf", 24);
						Word->setColor(cocos2d::Color3B::BLACK);
						Word->setAnchorPoint(Vec2(0.0f, 1.0f));
						Size extendsize(Word->getContentSize().width + 50, Word->getContentSize().height + 40);
						Girldia->setContentSize(extendsize);
						//CCLOG("%f\n", Girl->getPosition().x);
						Girldia->setPosition(Vec2(Girl->getPosition().x + Girl->getBoundingBox().getMaxX() - Girl->getBoundingBox().getMidX(), Girl->getPosition().y + Girl->getBoundingBox().getMaxY() - Girl->getBoundingBox().getMidY()));
						Girldia->setVisible(true);
						this->addChild(Word, 3);
						Size temp = Girldia->getContentSize();
						Word->setPosition(Vec2(Girldia->getPosition().x + (temp.width - Word->getContentSize().width) / 2, Girldia->getPosition().y + temp.height * 0.80f));
						if (countWord == 0)
						{
							SimpleAudioEngine::getInstance()->playEffect("GirlAsk.mp3", false);
						}
						countWord++;
					}
					else if (countWord < 8)
					{
						countWord++;
					}
					else if (countWord == 8)
					{
						Girldia->setVisible(false);
						this->removeChild(Word);
						Word = 0;
						countWord++;
					}
					else if (countWord == 9)
					{
						if (Word)
						{
							this->removeChild(Word);
						}
						const char* content = ((String*)sentence->objectForKey("Cop1"))->getCString();
						Word = LabelTTF::create(content, "fonts/arial.ttf", 24);
						Word->setColor(cocos2d::Color3B::BLACK);
						Size extendsize(Word->getContentSize().width + 50, Word->getContentSize().height + 40);
						Dialog->setContentSize(extendsize);
						Dialog->setPosition(Vec2(Cop->getPosition().x - Cop->getBoundingBox().getMaxX() + Cop->getBoundingBox().getMidX(), Cop->getPosition().y + Cop->getBoundingBox().getMaxY() - Cop->getBoundingBox().getMidY()));
						Dialog->setVisible(true);
						this->addChild(Word, 3);
						Word->setAnchorPoint(Vec2(1.0f, 0.5f));
						Size temp = Dialog->getContentSize();
						Word->setPosition(Vec2(Dialog->getPosition().x - (temp.width - Word->getContentSize().width) / 2, Dialog->getPosition().y + (temp.height * 0.50f)));
						SimpleAudioEngine::getInstance()->playEffect("lost/cop1.mp3", false);
						countWord++;
					}
					else if (countWord < 18)
					{
						countWord++;
					}
					else if (countWord == 18)
					{
						Dialog->setVisible(false);
						this->removeChild(Word);
						Word = 0;
						countWord++;
						std::string content = ((String*)sentence->objectForKey("PhoneAsk"))->_string;
						phoneEdit = TextFieldTTF::textFieldWithPlaceHolder(content, "fonts/arial.ttf", 36);
						phoneEdit->setTextColor(Color4B::BLACK);
						phoneEdit->setPosition(Vec2((Girl->getPositionX() + Cop->getPositionX()) / 2, Girl->getPositionY()*2.0f));
						PhoneDia->setContentSize(Size(phoneEdit->getContentSize().width + 50, phoneEdit->getContentSize().height + 40));
						PhoneDia->setPosition(phoneEdit->getPosition());
						PhoneDia->setVisible(true);
						this->addChild(phoneEdit, 4);
					}
					else
					{
						if (!isWin)
						{
							checkPhone();
						}
						else
						{
							this->removeChild(phoneEdit);
							this->removeChild(PhoneDia);
							countWord = 0;
							this->unschedule(schedule_selector(LostScene::timer));
							this->schedule(schedule_selector(LostScene::WinRemind), 0.2f);
							countTime = 0;
						}
					}
				}
			}
		}
	}
}

void LostScene::MoveClose()
{
	Girl->setPosition(Vec2(Girl->getPosition().x + visibleSize.width * 0.02, Girl->getPosition().y));
	Uncle->setPosition(Vec2(Uncle->getPosition().x - visibleSize.width * 0.02, Uncle->getPosition().y));
	if (Uncle->getPosition().x - Girl->getPosition().x <= visibleSize.width * 0.25)
	{
		isMoveClose = false;
		Girl->stopAllActions();
		Girl->setSpriteFrame(WGV.at(0));
		Uncle->stopAllActions();
		Uncle->setSpriteFrame(SpriteFrame::createWithTexture(cache[0], Rect(0, 0, cache[0]->getContentSize().width, cache[0]->getContentSize().height)));
	}
}

void LostScene::ShowWord()
{
	if (countWord < 17)
	{
		if (Word)
		{
			this->removeChild(Word);
		}
		std::string key;
		std::string baseFolder;
		if (countPerson == 1)
		{
			key = "Uncle1";
			baseFolder = "lost/uncle/";
		}
		else if (countPerson == 2)
		{
			key = "Badguy1";
			baseFolder = "lost/badguy/";
		}
		else if (countPerson == 3)
		{
			baseFolder = "lost/woman/";
			key = "Woman1";
		}
		const char* content = ((String*)sentence->objectForKey(key))->getCString();
		Word = LabelTTF::create(content, "fonts/arial.ttf", 24);
		Word->setColor(cocos2d::Color3B::BLACK);
		if (countWord == 0)
		{
			SimpleAudioEngine::getInstance()->playEffect((baseFolder + "1.mp3").c_str(), false);
		}
		countWord++;
	}
	else if (countWord >= 17)
	{
		if (Word)
		{
			this->removeChild(Word);
		}
		std::string key;
		std::string baseFolder;
		if (countPerson == 1)
		{
			baseFolder = "lost/uncle/";
			key = "Uncle2";
		}
		else if (countPerson == 2)
		{
			baseFolder = "lost/badguy/";
			key = "Badguy2";
		}
		else if (countPerson == 3)
		{
			key = "Woman2";
			baseFolder = "lost/woman/";
		}
		const char* content = ((String*)sentence->objectForKey(key))->getCString();
		Word = LabelTTF::create(content, "fonts/arial.ttf", 24);
		Word->setColor(cocos2d::Color3B::BLACK);
		if (countWord == 17)
		{
			SimpleAudioEngine::getInstance()->playEffect((baseFolder + "2.mp3").c_str(), false);
			
			if (countPerson == 2)
			{
				auto CandyAction = Animation::createWithSpriteFrames(WCV, 0.10f);
				auto CandyAnimate = Animate::create(CandyAction);
				Uncle->runAction(Repeat::create(CandyAnimate, 1));
			}
		}
		countWord++;
	}
	Size extendsize(Word->getContentSize().width + 50, Word->getContentSize().height + 40);
	Dialog->setContentSize(extendsize);
	Dialog->setPosition(Vec2(Uncle->getPosition().x - Uncle->getBoundingBox().getMaxX() + Uncle->getBoundingBox().getMidX(), Uncle->getPosition().y + Uncle->getBoundingBox().getMaxY() - Uncle->getBoundingBox().getMidY()));
	Dialog->setVisible(true);
	this->addChild(Word, 3);
	Word->setAnchorPoint(Vec2(1.0f, 0.5f));
	Size temp = Dialog->getContentSize();
	Word->setPosition(Vec2(Dialog->getPosition().x - (temp.width - Word->getContentSize().width)/2, Dialog->getPosition().y + (temp.height * 0.50f)));
}

void LostScene::ContactStranger()
{
	if (!isStrangerTime)
	{
		isStrangerTime = true;
	}
	else
	{
		if (touchStranger)
		{
			Director::getInstance()->replaceScene(GameoverScene::createScene(countPerson - 1));
		}
		else if (isReject)
		{
			if (countGirlWord == 0)
			{
				//Dialog->setVisible(false);
				LostScene::starNum++;
				char num[10];
				snprintf(num, 9, "%d", LostScene::starNum);
				grades->setString(std::string(&(num[0])));
				std::string key;
				std::string baseFolder;
				if (countPerson == 1)
				{
					baseFolder = "lost/uncle/";
					key = "Girl1";
				}
				else if (countPerson == 2)
				{
					baseFolder = "lost/badguy/";
					key = "Girl2";
				}
				else if (countPerson == 3)
				{
					baseFolder = "lost/woman/";
					key = "Girl3";
				}
				const char* content = ((String*)sentence->objectForKey(key))->getCString();
				if (Word)
				{
					this->removeChild(Word);
				}
				Word = LabelTTF::create(content, "fonts/arial.ttf", 24);
				Word->setColor(cocos2d::Color3B::BLACK);
				Word->setAnchorPoint(Vec2(0.0f, 1.0f));
				Size extendsize(Word->getContentSize().width + 50, Word->getContentSize().height + 40);
				Girldia->setContentSize(extendsize);
				Girldia->setPosition(Vec2(Girl->getPosition().x + Girl->getBoundingBox().getMaxX() - Girl->getBoundingBox().getMidX(), Girl->getPosition().y + Girl->getBoundingBox().getMaxY() - Girl->getBoundingBox().getMidY()));
				Girldia->setVisible(true);
				this->addChild(Word, 3);
				Size temp = Girldia->getContentSize();
				Word->setPosition(Vec2(Girldia->getPosition().x + (temp.width - Word->getContentSize().width) / 2, Girldia->getPosition().y + temp.height * 0.80f));
				SimpleAudioEngine::getInstance()->playEffect((baseFolder + "answer.mp3").c_str(), false);
				countGirlWord++;
			}
			else if (countGirlWord < 18)
			{
				countGirlWord++;
			}
			else if (countGirlWord == 18)
			{
				if (Word)
				{
					this->removeChild(Word);
					Word = 0;
				}
				Girldia->setVisible(false);
				countGirlWord++;
			}
			else if (countGirlWord == 19)
			{
				if (!leaveStranger)
				{
					auto GirlAction = Animation::createWithSpriteFrames(WGV, 0.20f);
					auto GirlAnimate = Animate::create(GirlAction);
					Girl->runAction(RepeatForever::create(GirlAnimate));
					auto UncleAction = Animation::createWithSpriteFrames(WUV, 0.2f);
					auto WalkUncle = Animate::create(UncleAction);
					Uncle->runAction(RepeatForever::create(WalkUncle));
					auto BgAction = Animation::createWithSpriteFrames(WBV, 0.20f);
					auto BgAnimate = Animate::create(BgAction);
					Background->runAction(RepeatForever::create(BgAnimate));
					leaveStranger = true;
				}
				else
				{
					if (Uncle != 0 && Uncle->getPositionX() > 0)
					{
						Uncle->setPositionX(Uncle->getPositionX() - visibleSize.width * 0.10);
					}
					else if (Girl->getPositionX() > visibleSize.width / 5)
					{
						if (Uncle != 0)
						{
							this->removeChild(Uncle);
							Uncle = 0;
						}
						Girl->setPositionX(Girl->getPositionX() - visibleSize.width * 0.15);
					}
					else
					{
						if (countPerson < 3)
						{
							std::string baseFolder;
							if (countPerson == 1)
							{
								baseFolder = "lost/badguy/";
							}
							else if (countPerson == 2)
							{
								baseFolder = "lost/woman/";
							}
							for (int i = 0; i < 5; i++)
							{
								TextureCache::getInstance()->removeTexture(cache[i]);
							}
							cache[0] = TextureCache::getInstance()->getTextureForKey(baseFolder + "stand.png");
							cache[1] = TextureCache::getInstance()->getTextureForKey(baseFolder + "1.png");
							cache[2] = TextureCache::getInstance()->getTextureForKey(baseFolder + "2.png");
							cache[3] = TextureCache::getInstance()->getTextureForKey(baseFolder + "3.png");
							cache[4] = TextureCache::getInstance()->getTextureForKey(baseFolder + "4.png");

						}
						else if (countPerson == 3)
						{
							for (int i = 0; i < 5; i++)
								TextureCache::getInstance()->removeTexture(cache[i]);
							//TextureCache::getInstance()->removeUnusedTextures();
						}
						isCount = true;
						this->removeChild(Uncle);
						isMoveClose = true;
						isReject = false;
						touchStranger = false;
						isStrangerTime = false;
						leaveStranger = false;
						countWord = 0;
						countGirlWord = 0;
					}
				}
			}
		}
	}
}

void LostScene::InitStranger()
{
	Uncle = Sprite::createWithTexture(cache[0]);
	float factor = visibleSize.height * 0.45 / Uncle->getContentSize().height;
	Uncle->setScaleX(factor);
	Uncle->setScaleY(factor);
	this->addChild(Uncle, 1);
	Uncle->setPosition(Vec2(visibleSize.width * 0.9f, visibleSize.height * 0.10f + Uncle->getBoundingBox().getMaxY() - Uncle->getBoundingBox().getMidY()));
	//Rect urect = Rect(0, 0, Girl->getContentSize().width, Girl->getContentSize().height);
	WUV.clear();
	for (int i = 1; i < 5; i++)
	{
		WUV.pushBack(SpriteFrame::createWithTexture(cache[i], Rect(0,0,cache[i]->getContentSize().width, cache[i]->getContentSize().height)));
	}
	auto UncleAction = Animation::createWithSpriteFrames(WUV, 0.2f);
	auto WalkUncle = Animate::create(UncleAction);
	Uncle->runAction(RepeatForever::create(WalkUncle));
	isCount = false;
	countTime++;
	Background->stopAllActions();
}

void LostScene::InitCop()
{
	Background->stopAllActions();
	Cop = Sprite::create("lost/cop.png");
	float factor = visibleSize.height * 0.45 / Cop->getContentSize().height;
	Cop->setScaleX(factor);
	Cop->setScaleY(factor);
	this->addChild(Cop, 1);
	Cop->setPosition(Vec2(visibleSize.width * 0.9f, visibleSize.height * 0.10f + Cop->getBoundingBox().getMaxY() - Cop->getBoundingBox().getMidY()));
	Finger = Sprite::create("finger.png");
	Finger->setAnchorPoint(Vec2(0.5f, 0.0f));
	float scaled = (Cop->getBoundingBox().getMaxX() - Cop->getBoundingBox().getMinX()) / Finger->getContentSize().width;
	Finger->setScaleX(scaled);
	Finger->setScaleY(scaled);
	this->addChild(Finger);
	auto temp = MoveBy::create(0.1f, Vec2(0.0f, 5.0f));
	Finger->setPosition(Vec2(Cop->getPositionX(), Cop->getPositionY() + Cop->getBoundingBox().getMaxY() - Cop->getBoundingBox().getMidY()));
	Finger->runAction(RepeatForever::create(Sequence::create(temp, temp->reverse(), NULL)));
}

void LostScene::checkPhone()
{
	//isCount = true;
	if (phoneEdit->getString() == database->getStringForKey("telNumber"))
	{
		isWin = true;
		//isCount = true;
	}
}

void LostScene::WinRemind(float t)
{
	if (countTime == 0)
	{
		const char* content = ((String*)sentence->objectForKey("Cop2"))->getCString();
		Word = LabelTTF::create(content, "fonts/arial.ttf", 24);
		Word->setColor(cocos2d::Color3B::BLACK);
		Size extendsize(Word->getContentSize().width + 50, Word->getContentSize().height + 40);
		Dialog->setContentSize(extendsize);
		Dialog->setPosition(Vec2(Cop->getPosition().x - Cop->getBoundingBox().getMaxX() + Cop->getBoundingBox().getMidX(), Cop->getPosition().y + Cop->getBoundingBox().getMaxY() - Cop->getBoundingBox().getMidY()));
		Dialog->setVisible(true);
		this->addChild(Word, 3);
		Word->setAnchorPoint(Vec2(1.0f, 0.5f));
		Size temp = Dialog->getContentSize();
		Word->setPosition(Vec2(Dialog->getPosition().x - (temp.width - Word->getContentSize().width) / 2, Dialog->getPosition().y + (temp.height * 0.50f)));
		SimpleAudioEngine::getInstance()->playEffect("lost/cop2.mp3", false);
		countTime++;
	}
	else if (countTime < 25)
	{
		countTime++;
	}
	else if (countTime == 25)
	{
		//TextureCache::getInstance()->removeAllTextures();
		//Director::getInstance()->end();
		Director::getInstance()->replaceScene(GameoverScene::createScene(3));
	}
}

void LostScene::Remind()
{
	if (countWord == 36)
	{
		std::string baseFolder = "lost/";
		if (countPerson == 1 || countPerson == 3)
		{
			baseFolder += "woman/";
		}
		else
		{
			baseFolder += "badguy/";
		}
		baseFolder += "hint.mp3";
		SimpleAudioEngine::getInstance()->playEffect(baseFolder.c_str(), false);
		if (starTalk)
		{
			this->removeChild(starTalk);
		}
		std::string num = "hint/";
		if (countPerson == 1)
		{
			num += "3.png";
		}
		else if (countPerson == 2)
		{
			num += "4.png";
		}
		else if (countPerson == 3)
		{
			num += "5.png";
		}
		starTalk = Sprite::create(num);
		//float h = star->getBoundingBox().getMaxY() - star->getBoundingBox().getMinY();
		starTalk->setScaleX(visibleSize.width * 0.15f / star->getContentSize().width);
		starTalk->setScaleY(visibleSize.height * 0.20f / star->getContentSize().width);
		starTalk->setAnchorPoint(Vec2(0.0f, 0.5f));
		this->addChild(starTalk);
		starTalk->setPosition(Vec2(star->getPositionX() + star->getBoundingBox().getMaxX() - star->getBoundingBox().getMidX(), star->getPositionY()));
		auto Ani = FadeOut::create(7.0f);
		starTalk->runAction(Ani);
		countWord++;
	}
	else
	{
		countWord++;
	}
}