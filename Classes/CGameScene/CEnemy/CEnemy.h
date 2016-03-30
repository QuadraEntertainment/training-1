#ifndef __CENEMY_H__
#define __CENEMY_H__

#include "cocos2d.h"

class CEnemy : public  cocos2d::Sprite
{
public:
	virtual bool init() override;

	CREATE_FUNC(CEnemy);
};

#endif // __CENEMY_H__
