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

	// プレイヤーの初期化
	CPlayer* player = CPlayer::create();

	this->addChild(player,0);

	return true;
}
