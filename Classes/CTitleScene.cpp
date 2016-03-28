#include "CTitleScene.h"

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
	
	Size visibleSize = Director::getInstance()->getVisibleSize()/2;

	// タイトルが表示できているかのテスト
	auto label = Label::createWithTTF("Title", "fonts/Marker Felt.ttf", 24);
	label->setPosition(visibleSize);
	this->addChild(label, 1);

	return true;
}
