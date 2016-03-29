#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#include "cocos2d.h"

class CPlayer : public  cocos2d::Sprite
{
public:
	CPlayer();

	virtual bool init() override;

	virtual void update(float delta) override;

	void addListernerForControl();

	void move();

	void moveLimit();

	CREATE_FUNC(CPlayer);
private:
	// 移動方向
	enum class eMOVE_DIRECTION {
		NONE
		, RIGHT
		, LEFT
	};

	eMOVE_DIRECTION	m_MoveDirection;	// 移動方向
	float			m_Speed;			// 移動速度
};

#endif // __CPLAYER_H__
