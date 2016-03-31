#ifndef __CGAME_SCENE_H__
#define __CGAME_SCENE_H__

#include "cocos2d.h"
#include "CBullet\CBullet.h"
#include "CEnemy\CEnemy.h"

class CPlayer;

class CGameScene : public  cocos2d::Layer
{
public:
	CGameScene();

	static cocos2d::Scene* createScene();

	virtual bool init() override;

	virtual void update(float delta) override;
	
	void addListernerForControl();

	void playerCreate();

	void enemyCreate();

	void bulletCreate(CBullet::eBULLET_TYPE type);

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	
	void enemyAndBulletCollision();

	CREATE_FUNC(CGameScene);

private:
	CPlayer*	m_Player;
	CEnemy*		m_Enemy;
};

#endif // __CGAME_SCENE_H__
