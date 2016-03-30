﻿#include "CGameScene.h"

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
	enemyCreate();

	addListernerForControl();

	return true;
}

// プレイヤー生成
void CGameScene::playerCreate()
{
	// プレイヤーの初期設定
	m_Player = CPlayer::create();

	Size visibleCenter = Director::getInstance()->getVisibleSize() / 2;

	m_Player->setPosition(Vec2(visibleCenter.width, m_Player->getContentSize().height/2));

	this->addChild(m_Player, 0);
}

// 敵生成
void CGameScene::enemyCreate()
{
	// 弾の初期設定
	m_Enemy = CEnemy::create();

	Size visibleSize = Director::getInstance()->getVisibleSize();

	m_Enemy->setPosition(Vec2(visibleSize.width/2, visibleSize.height - m_Enemy->getContentSize().height/2));

	this->addChild(m_Enemy, 0);
}


// 弾生成
void CGameScene::bulletCreate(CBullet::eBULLET_TYPE type)
{
	// 弾の初期設定
	CBullet* bullet = CBullet::create(type);

	// プレイヤーの位置から弾を出すようにする
	bullet->setPosition(m_Player->getPosition());

	this->addChild(bullet, 1);
}

// 操作
void CGameScene::addListernerForControl()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(CGameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(CGameScene::onKeyReleased, this);

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

// キー操作（押した時）
void CGameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	// Zキーを押した時、弾を発射する
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_Z) {
		bulletCreate(CBullet::eBULLET_TYPE::PLAYER);
	}

	// 左右キーを押した時、プレイヤーの移動を開始する
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		m_Player->setMoveDirection(CPlayer::eMOVE_DIRECTION::RIGHT);
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		m_Player->setMoveDirection(CPlayer::eMOVE_DIRECTION::LEFT);
	}
}

// キー操作（離した時）
void CGameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	// 左右キーを離した時、移動をやめるようにする
	CPlayer::eMOVE_DIRECTION direction = m_Player->getMoveDirection();

	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW && direction == CPlayer::eMOVE_DIRECTION::RIGHT) {
		m_Player->setMoveDirection(CPlayer::eMOVE_DIRECTION::NONE);
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW && direction == CPlayer::eMOVE_DIRECTION::LEFT) {
		m_Player->setMoveDirection(CPlayer::eMOVE_DIRECTION::NONE);
	}
}
