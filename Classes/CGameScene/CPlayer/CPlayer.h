#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#include "cocos2d.h"

class CPlayer : public  cocos2d::Sprite
{
public:
	CPlayer();

	virtual bool init() override;

	virtual void update(float delta) override;

	void control();

	void move();

	void moveLimit();

	CREATE_FUNC(CPlayer);
private:
	// ˆÚ“®•ûŒü
	enum eMOVE_DIRECTION{
		eMOVE_DIRECTION_NONE
		, eMOVE_DIRECTION_RIGHT
		, eMOVE_DIRECTION_LEFT
	};

	eMOVE_DIRECTION	m_MoveDirection;	// ˆÚ“®•ûŒü
	float			m_Speed;			// ˆÚ“®‘¬“x
};

#endif // __CPLAYER_H__
