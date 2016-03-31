#ifndef __CBULLET_H__
#define __CBULLET_H__

#include "cocos2d.h"

class CBullet : public  cocos2d::Sprite
{
public:
	// 弾の種類
	enum class eBULLET_TYPE {
		PLAYER
	};

	CBullet();

	static CBullet* create(eBULLET_TYPE type);

	virtual bool init(eBULLET_TYPE type);

	virtual void update(float delta) override;

	void move(float delta);

	void objectAndBulletCircleCollision();

	const float getRadius();

	const eBULLET_TYPE getBulletType();

private:
	float m_Speed;				// 移動速度
	float m_Radius;				// 半径
	eBULLET_TYPE m_BulletType;	// 弾の種類
};

#endif // __CBULLET_H__
