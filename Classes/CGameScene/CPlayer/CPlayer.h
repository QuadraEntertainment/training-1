#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#include "cocos2d.h"

class CPlayer : public  cocos2d::Sprite
{
public:
	// 移動方向
	enum class eMOVE_DIRECTION {
		NONE
		, RIGHT
		, LEFT
	};

	CPlayer();

	virtual bool init() override;

	virtual void update(float delta) override;

	void move();

	void moveLimit();

	eMOVE_DIRECTION getMoveDirection();

	void setMoveDirection(eMOVE_DIRECTION direction);

	CREATE_FUNC(CPlayer);

private:
	eMOVE_DIRECTION	m_MoveDirection;	// 移動方向
	float			m_Speed;			// 移動速度
};

#endif // __CPLAYER_H__
