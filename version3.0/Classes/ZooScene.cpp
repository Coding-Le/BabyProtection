#include "ZooScene.h"
#include "LostScene.h"
#include "LoadingScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

Scene* ZooScene::createScene()
{
	auto scene = Scene::create();
	auto layer = ZooScene::create();
	scene->addChild(layer);
	return scene;
}

bool ZooScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();
	Background = Sprite::create("zoo/horse.jpg");
	Peacock = Sprite::create("zoo/peacock/1.jpg");
	//CCLOG("width: %f, height: %f\n", Background->getContentSize().width, Background->getContentSize().height);
	this->addChild(Background);
	Background->setScaleX(visibleSize.height / Background->getContentSize().height);
	Background->setScaleY(visibleSize.height / Background->getContentSize().height);
	BGlen = Background->getBoundingBox().getMaxX() - Background->getBoundingBox().getMinX();
	Peacock->setScaleX(visibleSize.width / Peacock->getContentSize().width);
	Peacock->setScaleY(visibleSize.height / Peacock->getContentSize().height);
	Background->setPosition(Vec2(Background->getBoundingBox().getMaxX() - Background->getBoundingBox().getMidX(), Background->getBoundingBox().getMaxY() - Background->getBoundingBox().getMidY()));
	Peacock->setPosition(Background->getPosition().x + BGlen * 0.5 + Peacock->getBoundingBox().getMidX() - Peacock->getBoundingBox().getMinX(), Background->getPosition().y);
	this->addChild(Peacock);
	//CCLOG("width: %f, height: %f\n", Background->getBoundingBox().getMaxX(), Background->getBoundingBox().getMaxY());

	/*PeaTexture[0] = TextureCache::getInstance()->addImage("zoo/peacock/1.png");
	PeaTexture[1] = TextureCache::getInstance()->addImage("zoo/peacock/2.png");
	PeaTexture[2] = TextureCache::getInstance()->addImage("zoo/peacock/3.png");
	PeaTexture[3] = TextureCache::getInstance()->addImage("zoo/peacock/4.png");
	PeaTexture[4] = TextureCache::getInstance()->addImage("zoo/peacock/5.png");
	PeaTexture[5] = TextureCache::getInstance()->addImage("zoo/peacock/6.png");
	PeaTexture[6] = TextureCache::getInstance()->addImage("zoo/peacock/7.png");
	PeaTexture[7] = TextureCache::getInstance()->addImage("zoo/peacock/8.png");*/
	MovingPeacock = Sprite::create("zoo/peacock/1.png");
	this->addChild(MovingPeacock);
	MovingPeacock->setPosition(Peacock->getPosition());
	MovingPeacock->setPositionY(Peacock->getPositionY() + visibleSize.height * 0.05f);
	MovingPeacock->setScale(visibleSize.height * 0.45f / MovingPeacock->getContentSize().height);
	Rect prect(0, 0, MovingPeacock->getContentSize().width, MovingPeacock->getContentSize().height);
	WPV.pushBack(SpriteFrame::create("zoo/peacock/1.png", prect));
	WPV.pushBack(SpriteFrame::create("zoo/peacock/2.png", prect));
	WPV.pushBack(SpriteFrame::create("zoo/peacock/3.png", prect));
	WPV.pushBack(SpriteFrame::create("zoo/peacock/4.png", prect));
	WPV.pushBack(SpriteFrame::create("zoo/peacock/5.png", prect));
	WPV.pushBack(SpriteFrame::create("zoo/peacock/6.png", prect));
	WPV.pushBack(SpriteFrame::create("zoo/peacock/7.png", prect));
	WPV.pushBack(SpriteFrame::create("zoo/peacock/8.png", prect));

	Girl = Sprite:: create("baby/Girl/stand.png");
	float factor = visibleSize.height * 0.30 / Girl->getContentSize().height;
	Girl->setScaleX(factor);
	Girl->setScaleY(factor);
	this->addChild(Girl);
	Girl->setPosition(Vec2(visibleSize.width / 6, visibleSize.height * 0.11 + Girl->getBoundingBox().getMaxY() - Girl->getBoundingBox().getMidY()));
	Rect gr = Rect(0, 0, Girl->getContentSize().width, Girl->getContentSize().height);
	WGV.pushBack(SpriteFrame::create("baby/Girl/stand.png", gr));
	WGV.pushBack(SpriteFrame::create("baby/Girl/1.png", gr));
	WGV.pushBack(SpriteFrame::create("baby/Girl/2.png", gr));
	WGV.pushBack(SpriteFrame::create("baby/Girl/3.png", gr));
	WGV.pushBack(SpriteFrame::create("baby/Girl/4.png", gr));
	InvertGirl = SpriteFrame::create("baby/Girl/InvertStand.png", gr);
	InvertGirl->retain();
	isGirlInvert = false;
	BodyWidth = (Girl->getBoundingBox().getMaxX() - Girl->getBoundingBox().getMinX());
	BodyWidth *= 1.4f;
	/*auto GirlAction = Animation::createWithSpriteFrames(WGV, 0.20f);
	auto GirlAnimate = Animate::create(GirlAction);
	Girl->runAction(RepeatForever::create(GirlAnimate));*/
	//CCLOG("BodyMin:      %f\n", Girl->getBoundingBox().getMinX());
	//CCLOG("BodyMax:      %f\n", Girl->getBoundingBox().getMaxX());
	//CCLOG("ContentWidth: %f\n", Girl->getContentSize().width);
	//CCLOG("BodyWidth:    %f\n", BodyWidth);

	Mother = Sprite::create("baby/Mother/stand.png");
	float mF = visibleSize.height * 0.45 / Mother->getContentSize().height;
	Mother->setScaleX(mF);
	Mother->setScaleY(mF);
	this->addChild(Mother);
	Mother->setPosition(Vec2(visibleSize.width / 6 + BodyWidth, visibleSize.height * 0.12 + Mother->getBoundingBox().getMaxY() - Mother->getBoundingBox().getMidY()));
	//WMV.pushBack(Mother->getSpriteFrame());
	StandMother = SpriteFrame::create("baby/Mother/stand.png", gr);
	StandMother->retain();
	WMV.pushBack(SpriteFrame::create("baby/Mother/1.png", gr));
	WMV.pushBack(SpriteFrame::create("baby/Mother/2.png", gr));
	WMV.pushBack(SpriteFrame::create("baby/Mother/3.png", gr));
	WMV.pushBack(SpriteFrame::create("baby/Mother/4.png", gr));

	/*warning = Label::createWithTTF("Follow your parent!", "fonts/Marker Felt.ttf", 24);
	warning->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.7));
	this->addChild(warning);*/

	


	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ZooScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(ZooScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(ZooScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	star = Sprite::create("star.png");
	star->setScaleX(visibleSize.width * 0.05f / star->getContentSize().width);
	star->setScaleY(visibleSize.height * 0.08f / star->getContentSize().height);
	this->addChild(star);
	star->setPosition(Vec2(star->getBoundingBox().getMidX() - star->getBoundingBox().getMinX()+visibleSize.width * 0.02f, visibleSize.height - star->getBoundingBox().getMidY() + star->getBoundingBox().getMinY()- visibleSize.height * 0.02f));
	starNum = 0;
	grades = LabelTTF::create("0", "fonts/arial.ttf", 24);
	this->addChild(grades);
	grades->setPosition(Vec2(star->getPositionX(), star->getPositionY() - grades->getContentSize().height * 1.5f));
	grades->setColor(Color3B::RED);

	starTalk = Sprite::create("hint/0.png");
	//float h = star->getBoundingBox().getMaxY() - star->getBoundingBox().getMinY();
	starTalk->setScaleX(visibleSize.width * 0.15f / star->getContentSize().width);
	starTalk->setScaleY(visibleSize.height * 0.20f / star->getContentSize().width);
	starTalk->setAnchorPoint(Vec2(0.0f, 0.5f));
	this->addChild(starTalk);
	starTalk->setPosition(Vec2(star->getPositionX() + star->getBoundingBox().getMaxX() - star->getBoundingBox().getMidX(), star->getPositionY()));
	auto Ani = FadeOut::create(7.0f);
	starTalk->runAction(Ani);
	SimpleAudioEngine::getInstance()->playEffect("start.mp3", false);

	countTime = 0;
	this->schedule(schedule_selector(ZooScene::pretimer), 0.5f);

	steps = 0;
	atAnimal = false;
	countWord = 0;
	atPeacock = false;
	touchMother = false;
	peacockSeq = 2;
	beginLost = false;
	askMother = false;
	isGirlRun = false;
	touchDog = false;
	isDogTime = false;
	isDogExist = false;
	touchDog = false;
	isDogStay = false;
	isWarningMother = false;
	isMotherWalk = true;
	starTalk = 0;

	AnimalDia = cocos2d::ui::Scale9Sprite::create("phone.png");
	float scaled = AnimalDia->getContentSize().width / 148.0f;
	AnimalDia->setInsetLeft(20.0f * scaled);
	AnimalDia->setInsetBottom(20.0f * scaled);
	AnimalDia->setInsetTop(20.0f * scaled);
	AnimalDia->setInsetRight(20.0f * scaled);
	this->addChild(AnimalDia, 2);
	AnimalDia->setVisible(false);

	sentence = Dictionary::createWithContentsOfFile("zoo/zoo.xml");
	sentence->retain();
	return true;
}

bool ZooScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	return true;
}

void ZooScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

void ZooScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	Point touchPoint = touch->getLocation();
	if (Mother->getBoundingBox().containsPoint(touchPoint))
	{
		if (!touchMother && !atAnimal)
			touchMother = true;
		if (!touchMother && isDogStay)
			touchMother = true;
	}
	else if (isDogExist)
	{
		if (Dog->getBoundingBox().containsPoint(touchPoint))
		{
			touchDog = true;
		}
	}
}

void ZooScene::timer(float t)
{
	if (steps < 100)
	{
		if (!atAnimal)
		{
			if (!touchMother)
			{
				//warning->setVisible(true);
				if (Mother->getPositionX() - Girl->getPositionX() < visibleSize.width * 0.70f)
				{
					Mother->setPosition(Mother->getPosition().x + visibleSize.width * 0.02, Mother->getPosition().y);
				}
			    else
				{
					Mother->stopAllActions();
					Mother->setSpriteFrame(StandMother);
					isMotherWalk = false;
					if (!isWarningMother)
					{
						SimpleAudioEngine::getInstance()->playEffect("followMother.mp3", false);
						if (starTalk)
						{
							this->removeChild(starTalk);
						}
						starTalk = Sprite::create("hint/1.png");
						//float h = star->getBoundingBox().getMaxY() - star->getBoundingBox().getMinY();
						starTalk->setScaleX(visibleSize.width * 0.15f/ star->getContentSize().width);
						starTalk->setScaleY(visibleSize.height * 0.20f / star->getContentSize().width);
						starTalk->setAnchorPoint(Vec2(0.0f, 0.5f));
						this->addChild(starTalk);
						starTalk->setPosition(Vec2(star->getPositionX() + star->getBoundingBox().getMaxX() - star->getBoundingBox().getMidX(), star->getPositionY()));
						auto Ani = FadeOut::create(7.0f);
						starTalk->runAction(Ani);
						isWarningMother = true;
					}
					//Director::getInstance()->replaceScene(LoadingScene::createScene());
				}
			}
			else
			{
				isWarningMother = false;
				if (!isGirlRun)
				{
					auto GirlAction = Animation::createWithSpriteFrames(WGV, 0.20f);
					auto GirlAnimate = Animate::create(GirlAction);
					Girl->runAction(RepeatForever::create(GirlAnimate));
					isGirlRun = true;
				}
				//warning->setVisible(false);
				Background->setPosition(Background->getPosition().x - BGlen * 0.01, Background->getPosition().y);
				Peacock->setPosition(Peacock->getPosition().x - BGlen * 0.01, Background->getPosition().y);
				MovingPeacock->setPositionX(Peacock->getPositionX());
				steps++;
				if (Mother->getPosition().x - Girl->getPosition().y > BodyWidth * 1.5f)
				{
					Mother->setPosition(Mother->getPosition().x - visibleSize.width * 0.05, Mother->getPosition().y);
				}
				else
				{
					if (!isMotherWalk)
					{
						auto MotherAction = Animation::createWithSpriteFrames(WMV, 0.2f);
						auto WalkMother = Animate::create(MotherAction);
						Mother->runAction(RepeatForever::create(WalkMother));
						isMotherWalk = true;
					}
				}
				if (steps == 15 || steps == 60)
				{
					touchMother = false;
					Girl->stopAllActions();
					isGirlRun = false;
					Mother->stopAllActions();
					Girl->setSpriteFrame(WGV.at(0));
					Mother->setSpriteFrame(StandMother);
					atAnimal = true;
					countTime = 5;
					countWord++;
				}
			}
		}
		else
		{
			if (!isDogTime)
			{
				if (countTime == 5)
				{
					if (countWord == 1)
					{
						ShowAnimal("lu");
					}
					else if (countWord == 2)
					{
						ShowAnimal("horse");
					}
				}
				countTime--;
				if (countTime <= 0)
				{
					this->removeChild(Word);
					AnimalDia->setVisible(false);
					/*auto GirlAction = Animation::createWithSpriteFrames(WGV, 0.20f);
					auto GirlAnimate = Animate::create(GirlAction);
					Girl->runAction(RepeatForever::create(GirlAnimate));*/

					if (steps == 60)
						isDogTime = true;
					if (steps != 60)
					{
						auto MotherAction = Animation::createWithSpriteFrames(WMV, 0.2f);
						auto WalkMother = Animate::create(MotherAction);
						Mother->runAction(RepeatForever::create(WalkMother));
						atAnimal = false;
					}
				}
			}
			else
			{
				if (!isDogExist)
				{
					this->addDog();
					touchMother = false;
					isDogExist = true;
					Mother->stopAllActions();
					Mother->setSpriteFrame(StandMother);
				}
				else
				{
					if (!isDogStay)
					{
						Dog->setPosition(Dog->getPosition().x - visibleSize.width * 0.03, Dog->getPosition().y);
						if (abs(Dog->getPosition().x - Girl->getPosition().x) <= visibleSize.width * 0.04)
						{
							isDogStay = true;
							auto MotherAction = Animation::createWithSpriteFrames(WMV, 0.2f);
							auto WalkMother = Animate::create(MotherAction);
							Mother->runAction(RepeatForever::create(WalkMother));
						}
					}
					if (isDogStay)
					{
						if (Mother->getPositionX() - Girl->getPositionX() < visibleSize.width * 0.70f)
						{
							Mother->setPosition(Mother->getPosition().x + visibleSize.width * 0.02, Mother->getPosition().y);
						}
						else
						{
							Mother->stopAllActions();
							Mother->setSpriteFrame(StandMother);
							isMotherWalk = false;
							if (!isWarningMother)
							{
								SimpleAudioEngine::getInstance()->playEffect("followMother.mp3", false);
								if (starTalk)
								{
									this->removeChild(starTalk);
								}
								starTalk = Sprite::create("hint/1.png");
								//float h = star->getBoundingBox().getMaxY() - star->getBoundingBox().getMinY();
								starTalk->setScaleX(visibleSize.width * 0.15f / star->getContentSize().width);
								starTalk->setScaleY(visibleSize.height * 0.20f / star->getContentSize().width);
								starTalk->setAnchorPoint(Vec2(0.0f, 0.5f));
								this->addChild(starTalk);
								starTalk->setPosition(Vec2(star->getPositionX() + star->getBoundingBox().getMaxX() - star->getBoundingBox().getMidX(), star->getPositionY()));
								auto Ani = FadeOut::create(7.0f);
								starTalk->runAction(Ani);

								isWarningMother = true;
							}
							//Director::getInstance()->replaceScene(LoadingScene::createScene());
						}
						/*Mother->setPosition(Vec2(Mother->getPosition().x + visibleSize.width * 0.01, Mother->getPosition().y));
						if (Mother->getPosition().x > visibleSize.width || Dog->getPosition().x < 0)
						{
							Director::getInstance()->replaceScene(LoadingScene::createScene());
						}*/
						if (Dog->getPosition().x < 0)
						{
							Director::getInstance()->replaceScene(LoadingScene::createScene(starNum));
						}
						if (touchDog)
						{
							if (!isGirlInvert)
							{
								Girl->setSpriteFrame(InvertGirl);
								isGirlInvert = true;
							}
							Dog->setPosition(Vec2(Dog->getPosition().x - visibleSize.width * 0.02, Dog->getPosition().y));
							touchDog = false;
						}
						if (touchMother)
						{
							starNum++;
							grades->setString("1");
							Dog->setVisible(false);
							isDogTime = false;
							isDogExist = false;
							this->removeChild(Dog);
							atAnimal = false;
						}
					}
				}
			}
		}
	}
	else
	{
		if (peacockSeq == 2)
		{
			Girl->stopAllActions();
			auto PeacockAction = Animation::createWithSpriteFrames(WPV, 0.15f);
			auto PeacockAnimate = Animate::create(PeacockAction);
			MovingPeacock->runAction(Repeat::create(PeacockAnimate, 1));
			peacockSeq++;
		}
		if (peacockSeq <= 8)
		{
			Mother->setPosition(Mother->getPosition().x + visibleSize.width * 0.05, Mother->getPosition().y);
			peacockSeq++;
		}
		if (peacockSeq == 9)
		{
			Mother->stopAllActions();
			peacockSeq++;
		}
		if (peacockSeq >= 10 && peacockSeq <= 13)
		{
			peacockSeq++;
			if (peacockSeq > 13)
				askMother = true;
			auto crowd = Sprite::create("zoo/crowd.png");
			crowd->setScaleX(visibleSize.width / crowd->getContentSize().width);
			crowd->setScaleY(visibleSize.width / crowd->getContentSize().width);
			crowd->setTag(peacockSeq - 9);
			crowd->setPosition(Vec2(visibleSize.width *(0.5 - (peacockSeq - 10) * 0.02), 0 - crowd->getContentSize().height));
			this->addChild(crowd);
			auto Jump = MoveTo::create(0.5f, Vec2(crowd->getPosition().x, crowd->getBoundingBox().getMidY() - crowd->getBoundingBox().getMinY()));
			crowd->runAction(Jump);
		}
		if (askMother)
		{
			auto GirlAction = Animation::createWithSpriteFrames(WGV, 0.20f);
			auto GirlAnimate = Animate::create(GirlAction);
			Girl->runAction(RepeatForever::create(GirlAnimate));
			/*FlowWord* word = FlowWord::create();
			this->addChild(word);
			word->showWord("Where is Mother", Girl->getPosition());*/
			beginLost = true;
			askMother = false;
		}
		if (beginLost)
		{
			if (Girl->getPosition().x < visibleSize.width * 0.90f)
			{
				Girl->setPosition(Girl->getPosition().x + visibleSize.width * 0.05, Girl->getPosition().y);
			}
			else
			{
				Director::getInstance()->replaceScene(LoadingScene::createScene(starNum));
			}
		}
	}
}

void ZooScene::addDog()
{
	Dog = Sprite::create("zoo/dog/1.png");
	float factor = visibleSize.height * 0.11 / Dog->getContentSize().height;
	Dog->setScale(factor);
	Dog->setPosition(Vec2(visibleSize.width * 0.9f, (Dog->getBoundingBox().getMaxX() - Dog->getBoundingBox().getMinX()) / 2));
	this->addChild(Dog);
	Rect a(0, 0, Dog->getContentSize().width, Dog->getContentSize().height);
	WDV.pushBack(SpriteFrame::create("zoo/dog/1.png", a));
	WDV.pushBack(SpriteFrame::create("zoo/dog/2.png", a));
	WDV.pushBack(SpriteFrame::create("zoo/dog/3.png", a));
	WDV.pushBack(SpriteFrame::create("zoo/dog/4.png", a));
	auto DogAction = Animation::createWithSpriteFrames(WDV, 0.20f);
	auto DogAnimate = Animate::create(DogAction);
	Dog->runAction(RepeatForever::create(DogAnimate));
}

void ZooScene::ShowAnimal(std::string key)
{
	const char* content = ((String*)sentence->objectForKey(key))->getCString();
	Word = LabelTTF::create(content, "fonts/arial.ttf", 24);
	Word->setColor(cocos2d::Color3B::BLACK);
	AnimalDia->setContentSize(Size(Word->getContentSize().width + 50, Word->getContentSize().height + 40));
	AnimalDia->setPosition(Vec2(Mother->getPositionX() + visibleSize.width * 0.05f, Mother->getPositionY() + Mother->getBoundingBox().getMaxY() - Mother->getBoundingBox().getMidY() + AnimalDia->getContentSize().height * 0.5f));
	this->addChild(Word, 4);
	Word->setPosition(AnimalDia->getPosition());
	AnimalDia->setVisible(true);
}

void ZooScene::pretimer(float t)
{
	countTime++;
	if (countTime == 14 || touchMother)
	{
		countTime = 5;
		this->unschedule(schedule_selector(ZooScene::pretimer));
		auto MotherAction = Animation::createWithSpriteFrames(WMV, 0.2f);
		auto WalkMother = Animate::create(MotherAction);
		Mother->runAction(RepeatForever::create(WalkMother));
		this->schedule(schedule_selector(ZooScene::timer), 0.2f);
	}
}