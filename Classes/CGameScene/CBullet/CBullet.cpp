#include "CBullet.h"

#include "TagList.h"

USING_NS_CC;

CBullet::CBullet()
	: m_Speed(500.0f)
{
}

CBullet* CBullet::create(CBullet::eBULLET_TYPE type)
{
	auto bullet = new CBullet();
	bullet->init(type);
	bullet->autorelease();

	return bullet;
}

// 初期化
bool CBullet::init(eBULLET_TYPE type)
{
	if (!Sprite::init()) {
		return false;
	}

	this->initWithFile("Bullet.png");
	this->setTag(static_cast<int>(TagList::eNODE_TAG_LIST::BULLET));

	m_Type = type;

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
CBullet::eBULLET_TYPE CBullet::getBulletType()
{
	return m_Type;
}
