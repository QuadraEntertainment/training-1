#include "CGameScene.h"
#include "CPlayer\CPlayer.h"
#include "CBullet\CBullet.h"

#include "TagList.h"

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

	addListernerForControl();

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

// �e����
void CGameScene::bulletCreate()
{
	// �e�̏����ݒ�
	CBullet* bullet = CBullet::create();

	// �v���C���[�̈ʒu����e���o���悤�ɂ���
	Node* player = this->getChildByTag(eTAG_LIST_PLAYER);
	bullet->setPosition(player->getPosition());

	this->addChild(bullet, 1);
}

// ����
void CGameScene::addListernerForControl()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		// Z�L�[�����������A�e�𔭎˂���
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_Z) {
			bulletCreate();
		}

		CPlayer* player = (CPlayer*)this->getChildByTag(eTAG_LIST_PLAYER);

		// ���E�L�[�����������A�v���C���[�̈ړ����J�n����
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
			player->setMoveDirection(CPlayer::eMOVE_DIRECTION::RIGHT);
		}
		else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
			player->setMoveDirection(CPlayer::eMOVE_DIRECTION::LEFT);
		}
	};

	// ���E�L�[�𗣂������A�ړ�����߂�悤�ɂ���
	listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		CPlayer* player = (CPlayer*)this->getChildByTag(eTAG_LIST_PLAYER);
		CPlayer::eMOVE_DIRECTION direction = player->getMoveDirection();

		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW && direction == CPlayer::eMOVE_DIRECTION::RIGHT) {
			player->setMoveDirection(CPlayer::eMOVE_DIRECTION::NONE);
		}
		else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW && direction == CPlayer::eMOVE_DIRECTION::LEFT) {
			player->setMoveDirection(CPlayer::eMOVE_DIRECTION::NONE);
		}
	};

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
