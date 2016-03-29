#include "CPlayer.h"

USING_NS_CC;

CPlayer::CPlayer()
	: m_Speed(5.0f)
	, m_MoveDirection(eMOVE_DIRECTION_NONE)
{
}

// ������
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

// �X�V
void CPlayer::update(float delta)
{
	// �ړ�
	move();

	// �ړ�����
	moveLimit();
}

// ����
void CPlayer::control()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerKeyboard::create();

	// ���E�L�[�����������A�ړ����J�n����
	listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
			m_MoveDirection = eMOVE_DIRECTION_RIGHT;
		}
		else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
			m_MoveDirection = eMOVE_DIRECTION_LEFT;
		}
	};

	// ���E�L�[�𗣂������A�ړ�����߂�悤�ɂ���
	listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW && m_MoveDirection == eMOVE_DIRECTION_RIGHT) {
			m_MoveDirection = eMOVE_DIRECTION_NONE;
		}
		else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW && m_MoveDirection == eMOVE_DIRECTION_LEFT) {
			m_MoveDirection = eMOVE_DIRECTION_NONE;
		}
	};

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	this->scheduleUpdate();
}

// �ړ�
void CPlayer::move()
{
	switch (m_MoveDirection)
	{
	case eMOVE_DIRECTION_RIGHT:	this->runAction(MoveBy::create(0.0f, Vec2(m_Speed, 0.0f))); break;
	case eMOVE_DIRECTION_LEFT:	this->runAction(MoveBy::create(0.0f, Vec2(-m_Speed, 0.0f))); break;
	default:	break;
	}
}

// �ړ�����
void CPlayer::moveLimit()
{
	Vec2 pos = this->getPosition();
	Vec2 centerSize = this->getContentSize() / 2;

	pos.x = std::min(pos.x, Director::getInstance()->getVisibleSize().width - centerSize.x);
	pos.x = std::max(pos.x, 0.0f + centerSize.x);

	this->setPosition(pos);
}
