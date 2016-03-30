#include "CPlayer.h"
#include "CGameScene\CBullet\CBullet.h"

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

// 移動
void CPlayer::move()
{
	Vec2 pos = this->getPosition();

	switch (m_MoveDirection)
	{
	case eMOVE_DIRECTION::RIGHT:	pos.x += m_Speed;	break;
	case eMOVE_DIRECTION::LEFT:		pos.x -= m_Speed;	break;
	default:	break;
	}

	this->setPosition(pos);
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

// 移動方向取得
CPlayer::eMOVE_DIRECTION CPlayer::getMoveDirection()
{
	return m_MoveDirection;
}

// 移動方向設定
void CPlayer::setMoveDirection(eMOVE_DIRECTION direction)
{
	m_MoveDirection = direction;
}
