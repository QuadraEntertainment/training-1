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

	playerCreate();

	return true;
}

// プレイヤー生成
void CGameScene::playerCreate()
{
	// プレイヤーの初期設定
	CPlayer* player = CPlayer::create();

	Size visibleCenter = Director::getInstance()->getVisibleSize() / 2;
	player->setPosition(Vec2(visibleCenter.width, player->getContentSize().height/2));
	this->addChild(player, 0);
}
