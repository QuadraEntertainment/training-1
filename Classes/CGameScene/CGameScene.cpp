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

	// �Q�[���V�[�����\���ł��Ă��邩�̃e�X�g
	//Size visibleSize = Director::getInstance()->getVisibleSize() / 2;
	//auto label = Label::createWithTTF("Game", "fonts/Marker Felt.ttf", 24);
	//label->setPosition(visibleSize);
	//this->addChild(label, 1);

	// �v���C���[�̏�����
	CPlayer* player = CPlayer::getInstance();

	player->init();
	this->addChild(player);

	return true;
}
