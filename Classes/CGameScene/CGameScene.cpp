#include "CGameScene.h"
#include "CPlayer\CPlayer.h"

USING_NS_CC;

CGameScene::CGameScene()
{
}

// シーンの作成
Scene* CGameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = CGameScene::create();

	scene->addChild(layer);

	return scene;
}

// 初期化
bool CGameScene::init()
{
	if (!Layer::init()) {
		return false;
	}

	// ゲームシーンが表示できているかのテスト
	//Size visibleSize = Director::getInstance()->getVisibleSize() / 2;
	//auto label = Label::createWithTTF("Game", "fonts/Marker Felt.ttf", 24);
	//label->setPosition(visibleSize);
	//this->addChild(label, 1);

	// プレイヤーの初期化
	CPlayer* player = CPlayer::getInstance();

	player->init();
	this->addChild(player);

	return true;
}
