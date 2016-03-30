#ifndef __CBULLET_H__
#define __CBULLET_H__

#include "cocos2d.h"

class CBullet : public  cocos2d::Sprite
{
public:
	CBullet();

	virtual bool init() override;

	virtual void update(float delta) override;

	void move(float delta);

	CREATE_FUNC(CBullet);

private:
	float			m_Speed;			// 移動速度
};

#endif // __CBULLET_H__
