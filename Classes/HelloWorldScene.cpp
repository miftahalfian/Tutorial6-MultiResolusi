#include "HelloWorldScene.h"
#include "AppDelegate.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	auto bg = Sprite::create("bg.png");
	bg->setPosition(Vec2(640, 384));
	this->addChild(bg);

	/*
	FYI, DrawNode adalah node yang digunakan
	untuk menggambar objek primitive
	seperti lingkaran, kotak, garis, dsb.
	*/

	auto dr = DrawNode::create();
	dr->drawDot(Vec2(300, 300), 100, Color4F::RED);
	dr->drawSolidRect(Vec2(100, 100), Vec2(500, 200), Color4F::BLUE);
	this->addChild(dr);
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(640, 768 - label->getContentSize().height));
    this->addChild(label, 1);

    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(640, 384));
	this->addChild(sprite, 0);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size designResolutionSize = AppDelegate::designResolutionSize;

	float addX = (visibleSize.width - designResolutionSize.width) / 2;
	float addY = (visibleSize.height - designResolutionSize.height) / 2;

	for (int i = 0; i < (int)this->getChildrenCount(); i++) {
		Vec2 pos_child = this->getChildren().at(i)->getPosition();

		this->getChildren().at(i)->setPosition(pos_child + Vec2(addX, addY));
	}
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
