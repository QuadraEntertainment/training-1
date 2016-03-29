#ifndef __CGAME_SCENE_H__
#define __CGAME_SCENE_H__

#include "cocos2d.h"

class CGameScene : public  cocos2d::Layer
{
public:
	CGameScene();

	static cocos2d::Scene* createScene();

	virtual bool init() override;
	
	void addListernerForControl();

	void playerCreate();

	void bulletCreate();

	CREATE_FUNC(CGameScene);
};

#endif // __CGAME_SCENE_H__
