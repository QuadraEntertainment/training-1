#include "CGameScene.h"
#include "CPlayer\CPlayer.h"
#include "CBullet\CBullet.h"

#include "TagList.h"

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

	addListernerForControl();

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

// 弾生成
void CGameScene::bulletCreate()
{
	// 弾の初期設定
	CBullet* bullet = CBullet::create();

	// プレイヤーの位置から弾を出すようにする
	Node* player = this->getChildByTag(eTAG_LIST_PLAYER);
	bullet->setPosition(player->getPosition());

	this->addChild(bullet, 1);
}

// 操作
void CGameScene::addListernerForControl()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		// Zキーを押した時、弾を発射する
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_Z) {
			bulletCreate();
		}

		CPlayer* player = (CPlayer*)this->getChildByTag(eTAG_LIST_PLAYER);

		// 左右キーを押した時、プレイヤーの移動を開始する
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
			player->setMoveDirection(CPlayer::eMOVE_DIRECTION::RIGHT);
		}
		else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
			player->setMoveDirection(CPlayer::eMOVE_DIRECTION::LEFT);
		}
	};

	// 左右キーを離した時、移動をやめるようにする
	listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		CPlayer* player = (CPlayer*)this->getChildByTag(eTAG_LIST_PLAYER);
		CPlayer::eMOVE_DIRECTION direction = player->getMoveDirection();

		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW && direction == CPlayer::eMOVE_DIRECTION::RIGHT) {
			player->setMoveDirection(CPlayer::eMOVE_DIRECTION::NONE);
		}
		else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW && direction == CPlayer::eMOVE_DIRECTION::LEFT) {
			player->setMoveDirection(CPlayer::eMOVE_DIRECTION::NONE);
		}
	};

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
