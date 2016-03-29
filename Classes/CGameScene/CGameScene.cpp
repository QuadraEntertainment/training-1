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

	playerCreate();

	return true;
}

// �v���C���[����
void CGameScene::playerCreate()
{
	// �v���C���[�̏����ݒ�
	CPlayer* player = CPlayer::create();

	Size visibleCenter = Director::getInstance()->getVisibleSize() / 2;
	player->setPosition(Vec2(visibleCenter.width, player->getContentSize().height/2));
	this->addChild(player, 0);
}
