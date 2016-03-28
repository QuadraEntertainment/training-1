#include "CPlayer.h"

USING_NS_CC;

CPlayer::CPlayer()
	: m_Sprite(nullptr)
{
}

// 初期化
bool CPlayer::init()
{
	if (!Sprite::init()) {
		return false;
	}

	// プレイヤーの画像表示
	Size visibleCenter = Director::getInstance()->getVisibleSize()/2;

	m_Sprite = Sprite::create("Player.png");
	m_Sprite->setPosition(Vec2(visibleCenter.width, m_Sprite->getContentSize().height/2));

	this->addChild(m_Sprite, 0);

	return true;
}
