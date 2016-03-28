#ifndef __CTITLE_SCENE_H__
#define __CTITLE_SCENE_H__

#include "cocos2d.h"

class CTitleScene : public  cocos2d::Layer
{
public:
	CTitleScene();

	static cocos2d::Scene* createScene();

	virtual bool init() override;

	CREATE_FUNC(CTitleScene);
};

#endif // __TITLE_SCENE_H__
