#include "CPlayer.h"

USING_NS_CC;

CPlayer::CPlayer()
	: m_Sprite(nullptr)
{
}

// ������
bool CPlayer::init()
{
	if (!Sprite::init()) {
		return false;
	}

	// �v���C���[�̉摜�\��
	Size visibleCenter = Director::getInstance()->getVisibleSize()/2;

	m_Sprite = Sprite::create("Player.png");
	m_Sprite->setPosition(Vec2(visibleCenter.width, m_Sprite->getContentSize().height/2));

	this->addChild(m_Sprite, 0);

	return true;
}
