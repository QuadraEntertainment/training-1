#ifndef __CENEMY_H__
#define __CENEMY_H__

#include "cocos2d.h"

class CEnemy : public  cocos2d::Sprite
{
public:
	virtual bool init() override;

	float getRadius();

	CREATE_FUNC(CEnemy);

private:
	float		m_Radius;	// 半径
};

#endif // __CENEMY_H__
