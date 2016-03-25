#ifndef __CTITLE_SCENE_H__
#define __CTITLE_SCENE_H__

#include "cocos2d.h"

class CTitle : public cocos2d::Layer
{
public:
	CTitle();

	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(CTitle);
};

#endif // __TITLE_SCENE_H__
