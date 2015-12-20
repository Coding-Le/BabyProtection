#include "ScrollView.h"
#include "ScrollViewScene.h"
#include"beforezoo.h"
float ScrollView::WINDOW_WIDTH = 480;
float ScrollView::WINDOW_HEIGHT = 320;
float ScrollView::LOC_HEIGHT = 400;

void ScrollView::setWindow(float w, float h, float l)
{
	WINDOW_WIDTH = w;
	WINDOW_HEIGHT = h;
	LOC_HEIGHT = l;
}

ScrollView::ScrollView()
{
	m_Page = 0;
	m_CurPage = 0;
	m_PageLayer = CCArray::createWithCapacity(5);
	m_PageLayer->retain();
}

ScrollView::~ScrollView()
{
	m_PageLayer->removeAllObjects();
	m_PageLayer->release();
}

bool ScrollView::init()
{
	bool bRet = false;

	do {
		CC_BREAK_IF(!CCLayer::init());

		bRet = true;
	} while (0);

	return bRet;
}

void ScrollView::onEnter()
{
	CCLayer::onEnter();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ScrollView::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(ScrollView::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(ScrollView::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(ScrollView::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void ScrollView::onExit()
{
	_eventDispatcher->removeEventListenersForTarget(this);
	//CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}

bool ScrollView::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
	m_TouchDownPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	m_TouchCurPoint = m_TouchDownPoint;

	return true;
}

void ScrollView::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
	// 移动
	CCPoint touchPoint = Director::sharedDirector()->convertToGL(pTouch->getLocationInView());
	CCPoint posPoint = CCPointMake(getPositionX() + touchPoint.x - m_TouchCurPoint.x, getPositionY());
	setPosition(posPoint);
	m_TouchCurPoint = touchPoint;
}

void ScrollView::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{

	m_TouchUpPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	// 计算按下和抬起的偏移量
	float offset = (m_TouchUpPoint.x - m_TouchDownPoint.x) * (m_TouchUpPoint.x - m_TouchDownPoint.x) + (m_TouchUpPoint.y - m_TouchDownPoint.y) * (m_TouchUpPoint.y - m_TouchDownPoint.y);

	if (offset < (TOUCH_DELTA * TOUCH_DELTA)) {
		// 点击
		// 向子Layer发送Click消息
		//CCLOG("SHOW: ");
		/*for (int i = 0; i <= m_Page; i++)
		{
		Rect r = ((CCLayer*)m_PageLayer->objectAtIndex(m_CurPage))->getBoundingBox();
		Vec2 p = ((CCLayer*)m_PageLayer->objectAtIndex(m_CurPage))->getPosition();
		CCLOG("box%d: %f %f\n", i, p.x, p.y);
		if (r.containsPoint(m_TouchCurPoint))
		{
		((CCLayer*)m_PageLayer->objectAtIndex(m_CurPage))->onTouchBegan(pTouch, pEvent);
		}
		}*/
		if (m_TouchCurPoint.y >= ScrollView::LOC_HEIGHT && m_TouchCurPoint.y <= ScrollView::LOC_HEIGHT + ScrollView::WINDOW_HEIGHT)
		{
			int index = (int)(m_TouchUpPoint.x / ScrollView::WINDOW_WIDTH);
			index += m_CurPage;
			if (index < m_Page) {
				((CCLayer*)m_PageLayer->objectAtIndex(index))->onTouchBegan(pTouch, pEvent);
				if (index == 0) {
					run();
				}
				/*ScrollViewScene::click_flag = 1;
				ScrollViewScene::touch_pos_x = pTouch->getLocation().x;
				ScrollViewScene::touch_pos_y = pTouch->getLocation().y;*/
				
			}
		}

	}
	else {
		// 滑动结束
		int offset = getPositionX() - m_CurPage * (-ScrollView::WINDOW_WIDTH);
		if (offset > ScrollView::WINDOW_WIDTH / 2) {
			// 上一页
			if (m_CurPage > 0) {
				--m_CurPage;
			}
		}
		else if (offset < -ScrollView::WINDOW_WIDTH / 2) {
			// 下一页
			if (m_CurPage < (m_Page - 1)) {
				++m_CurPage;
			}
		}

		// 执行跳转动画
		goToPage();
	}
}

void ScrollView::onTouchCancelled(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
}

void ScrollView::goToPage()
{
	MoveTo *moveTo = MoveTo::create(0.2f, CCPointMake(-m_CurPage * ScrollView::WINDOW_WIDTH, ScrollView::LOC_HEIGHT));
	this->runAction(moveTo);
}

void ScrollView::addPage(cocos2d::Layer *pPageLayer)
{
	if (pPageLayer) {
		// 设置成一页大小
		pPageLayer->setContentSize(CCSizeMake(ScrollView::WINDOW_WIDTH, WINDOW_HEIGHT));
		pPageLayer->setPosition(ccp(ScrollView::WINDOW_WIDTH * m_Page, 0));
		this->addChild(pPageLayer);
		// 添加到页
		m_PageLayer->addObject(pPageLayer);
		m_Page = m_PageLayer->count();
	}
}


void ScrollView::Schedule() {
	schedule(schedule_selector(ScrollView::updateTime1), 0.1f);
}

void ScrollView::updateTime1(float dt){
	totalTime1 += dt;
	if (totalTime1 > 3.6) {
		this->stopAllActions();
		auto scene = beforezoo::createScene();
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1, scene, Color3B::GRAY));
	}
}

void ScrollView::run() {
	cocos2d::Sprite* character = Sprite::create("girl/1.png");
	character->setScale(0.5);
	//character->setAnchorPoint(Vec2(0.5, 0));
	//CCPoint* newnode = CCPoint::convertToNodeSpace(Vec2(character->getContentSize().width, character->getContentSize().height / 2));
	//character->setPosition(Vec2(character->getContentSize().width, character->getContentSize().height / 2));
	character->setPosition(ccp(-360, -360));
	character->setAnchorPoint(ccp(0, 0));
	this->addChild(character, 5);

	Vector<SpriteFrame*> girlFrames;
	girlFrames.reserve(12);
	Rect br(0, 0, character->getContentSize().width, character->getContentSize().height);
	girlFrames.pushBack(SpriteFrame::create("girl/1.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/2.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/3.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/4.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/1.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/2.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/3.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/4.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/1.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/2.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/3.png", br));
	girlFrames.pushBack(SpriteFrame::create("girl/4.png", br));
	auto girl_move = Animation::createWithSpriteFrames(girlFrames, 0.3f);
	auto moveto = MoveTo::create(3.6, Vec2(Director::getInstance()->getVisibleSize().width/2, character->getPosition().y));
	auto girl_animate = Animate::create(girl_move);
	auto action = Spawn::create(moveto, girl_animate, NULL);
	character->runAction(Repeat::create(action, 3.6));
	Schedule();
	this->stopAllActions();
	auto scene = beforezoo::createScene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1, scene, Color3B::GRAY));
}