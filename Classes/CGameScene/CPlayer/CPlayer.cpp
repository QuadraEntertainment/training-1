#include "CPlayer.h"

USING_NS_CC;

CPlayer::CPlayer()
	: m_Speed(5.0f)
	, m_MoveDirection(eMOVE_DIRECTION::NONE)
{
}

// 初期化
bool CPlayer::init()
{
	if (!Sprite::init()) {
		return false;
	}

	this->initWithFile("Player.png");

	control();

	this->scheduleUpdate();

	return true;
}

// 更新
void CPlayer::update(float delta)
{
	// 移動
	move();

	// 移動制限
	moveLimit();
}

// ����
void CPlayer::control()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerKeyboard::create();

	// 左右キーを押した時、移動を開始する
	listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
			m_MoveDirection = eMOVE_DIRECTION::RIGHT;
		}
		else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
			m_MoveDirection = eMOVE_DIRECTION::LEFT;
		}
	};

	// 左右キーを離した時、移動をやめるようにする
	listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW && m_MoveDirection == eMOVE_DIRECTION::RIGHT) {
			m_MoveDirection = eMOVE_DIRECTION::NONE;
		}
		else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW && m_MoveDirection == eMOVE_DIRECTION::LEFT) {
			m_MoveDirection = eMOVE_DIRECTION::NONE;
		}
	};

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	this->scheduleUpdate();
}

// 移動
void CPlayer::move()
{
	switch (m_MoveDirection)
	{
	case eMOVE_DIRECTION_RIGHT:	this->runAction(MoveBy::create(0.0f, Vec2(m_Speed, 0.0f))); break;
	case eMOVE_DIRECTION_LEFT:	this->runAction(MoveBy::create(0.0f, Vec2(-m_Speed, 0.0f))); break;
	default:	break;
	}
}

// 移動制限
void CPlayer::moveLimit()
{
	Vec2 pos = this->getPosition();
	Vec2 centerSize = this->getContentSize() / 2;

	pos.x = std::min(pos.x, Director::getInstance()->getVisibleSize().width - centerSize.x);
	pos.x = std::max(pos.x, 0.0f + centerSize.x);

	this->setPosition(pos);
}
