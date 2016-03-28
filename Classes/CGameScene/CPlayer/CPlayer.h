#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#include "cocos2d.h"

class CPlayer : public  cocos2d::Sprite
{
public:
	CPlayer();

	virtual bool init() override;

	CREATE_FUNC(CPlayer);

private:
	cocos2d::Sprite*	m_Sprite;
};

#endif // __CPLAYER_H__
