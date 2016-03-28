#include "CGameScene.h"

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

	Size visibleSize = Director::getInstance()->getVisibleSize() / 2;

	// �^�C�g�����\���ł��Ă��邩�̃e�X�g
	auto label = Label::createWithTTF("Game", "fonts/Marker Felt.ttf", 24);
	label->setPosition(visibleSize);
	this->addChild(label, 1);

	return true;
}
