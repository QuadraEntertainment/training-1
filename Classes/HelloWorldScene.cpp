#include "HelloWorldScene.h"

USING_NS_CC;

HelloWorld::HelloWorld()
	: m_TestSprite(nullptr)	// 初期化
{
}

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
	if (!Layer::init())
	{
		return false;
	}

	// 画面サイズ
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// 画面の半分のサイズ
	Size visibleCenter = Size(visibleSize.width / 2, visibleSize.height / 2);

	// 端末左下の位置
	Vec2 origin = Director::getInstance()->getVisibleOrigin( );

	// 端末ごとのサイズ差によるズレを考慮した画面サイズ
	Vec2 visibleSizeOrigin(visibleSize.width + origin.x, visibleSize.height + origin.y);
	Vec2 visibleCenterOrigin(visibleCenter.width + origin.x, visibleCenter.height + origin.y);

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(visibleSizeOrigin.x - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(visibleCenterOrigin.x,
		visibleSizeOrigin.y - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleCenterOrigin.x, visibleCenterOrigin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	m_TestSprite = Sprite::create("Koala.jpg");

	m_TestSprite->setPosition(Vec2(m_TestSprite->getContentSize().width / 2 + origin.x, visibleCenterOrigin.y));

	this->addChild(m_TestSprite, 0);

	// ボタンを押すと、テスト画像を消す処理を行う
	auto buttonItem = MenuItemImage::create(
		"ButtonPlay.png",
		"ButtonStop.png",
		CC_CALLBACK_1(HelloWorld::deleteTestSprite, this));

	buttonItem->setPosition(Vec2(visibleSizeOrigin.x - buttonItem->getContentSize().width / 2, visibleCenterOrigin.y));
	
	//メニューを作成 自動解放オブジェクト
	auto button_menu = Menu::create(buttonItem, nullptr);

	button_menu->setPosition(Point::ZERO);
	
	// メニューを追加
	this->addChild(button_menu, 1);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::deleteTestSprite(Ref* pSender)
{
	if (m_TestSprite == nullptr)	return;

	// 親クラスからオブジェクトを削除
	m_TestSprite->removeFromParentAndCleanup(true);
	m_TestSprite = nullptr;
}
