#include "title.h"

USING_NS_CC;

CTitle::CTitle()
{
}

// シーンの作成
Scene* CTitle::createScene()
{
	auto scene = Scene::create();
	auto layer = CTitle::create();

	scene->addChild(layer);

	return scene;
}

// 初期化
bool CTitle::init()
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