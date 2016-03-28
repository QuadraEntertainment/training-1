#include "CTitleScene.h"
#include "CGameScene\CGameScene.h"

USING_NS_CC;

CTitleScene::CTitleScene()
{
}

// シーンの作成
Scene* CTitleScene::createScene()
{
	auto scene = Scene::create();
	auto layer = CTitleScene::create();

	scene->addChild(layer);

	return scene;
}

// 初期化
bool CTitleScene::init()
{
	if (!Layer::init()) {
		return false;
	}
	
	Size visibleCenter = Director::getInstance()->getVisibleSize()/2;

	// タイトルが表示できているかのテスト
	auto label = Label::createWithTTF("Title", "fonts/Marker Felt.ttf", 24);
	label->setPosition(visibleCenter);
	this->addChild(label, 1);

	auto listener = EventListenerTouchOneByOne::create();

	// タッチをしたらシーンをゲームシーンに移す
	listener->onTouchBegan = [](Touch* touch, Event* event) {
		Director::getInstance()->replaceScene(CGameScene::createScene());
		return true;
	};

	// イベントリスナーを登録
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}
