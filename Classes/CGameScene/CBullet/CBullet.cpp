#include "CBullet.h"

USING_NS_CC;

CBullet::CBullet()
	: m_Speed(500.0f)
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
	move(delta);
}

// 移動
void CBullet::move(float delta)
{
	Vec2 pos = this->getPosition();

	pos.y += m_Speed * delta;

	this->setPosition(pos);
}
