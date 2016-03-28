#include "CPlayer.h"

USING_NS_CC;

CPlayer::CPlayer()
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

	this->initWithFile("Player.png");
	this->setPosition(Vec2(visibleCenter.width, this->getContentSize().height/2));

	return true;
}
