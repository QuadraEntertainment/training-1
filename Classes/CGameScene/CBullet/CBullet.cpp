#include "CBullet.h"

USING_NS_CC;

CBullet::CBullet()
	: m_Speed(5.0f)
{
}

// 初期化
bool CBullet::init()
{
	if (!Sprite::init()) {
		return false;
	}

	this->initWithFile("Bullet.png");

	this->scheduleUpdate();

	return true;
}

// 更新
void CBullet::update(float delta)
{
	// 移動
	move();
}

// 移動
void CBullet::move()
{
	Vec2 pos = this->getPosition();

	pos.y += m_Speed;

	this->setPosition(pos);
}