#include "DialogScene.h"
//#include "extensions/cocos-ext.h"
#include "ui\UIScale9Sprite.h"
USING_NS_CC;


Scene* DialogScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = DialogScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool DialogScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
										   CC_CALLBACK_1(DialogScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

	auto girl = Sprite::create("2.png");
	girl->setScaleX(0.3);
	girl->setScaleY(0.3);
	this->addChild(girl);
	girl->setPosition(Vec2(480, 270));
    
    auto label = Label::createWithTTF("you are here to\n experience the interesting game", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    /*label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));*/

    // add the label as a child to this layer
    //this->addChild(label, 1);

    // add "HelloWorld" splash screen"
	std::string d = "dia_1.png";
	auto sprite = ui::Scale9Sprite::create(d);
	Size extendsize = CCSizeMake(label->getContentSize().width + 20, label->getContentSize().height + 20);
	sprite->setContentSize(extendsize);
	this->addChild(label, 1);
	label->setPosition(girl->getPosition().x + girl->getBoundingBox().getMaxX() / 2 - label->getContentSize().width / 2, girl->getPosition().y + girl->getBoundingBox().getMaxY() /2 - label->getContentSize().height / 2);
    // position the sprite on the center of the screen
	sprite->setPosition(label->getPosition());

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


void DialogScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
