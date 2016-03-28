#include "CPlayer.h"

USING_NS_CC;

CPlayer::CPlayer()
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

	auto sprite = Sprite::create("Player.png");
	this->setPosition(Vec2(visibleCenter.width, sprite->getContentSize().height/2));

	this->addChild(sprite, 0);
	return true;
}
