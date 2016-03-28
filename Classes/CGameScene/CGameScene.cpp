#include "CGameScene.h"
#include "CPlayer\CPlayer.h"

USING_NS_CC;

CGameScene::CGameScene()
{
}

// �V�[���̍쐬
Scene* CGameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = CGameScene::create();

	scene->addChild(layer);

	return scene;
}

// ������
bool CGameScene::init()
{
	if (!Layer::init()) {
		return false;
	}

	// �v���C���[�̏�����
	CPlayer* player = CPlayer::create();

	this->addChild(player,0);

	return true;
}
