#include "CTitleScene.h"
#include "CGameScene\CGameScene.h"

USING_NS_CC;

CTitleScene::CTitleScene()
{
}

// �V�[���̍쐬
Scene* CTitleScene::createScene()
{
	auto scene = Scene::create();
	auto layer = CTitleScene::create();

	scene->addChild(layer);

	return scene;
}

// ������
bool CTitleScene::init()
{
	if (!Layer::init()) {
		return false;
	}
	
	Size visibleCenter = Director::getInstance()->getVisibleSize()/2;

	// �^�C�g�����\���ł��Ă��邩�̃e�X�g
	auto label = Label::createWithTTF("Title", "fonts/Marker Felt.ttf", 24);
	label->setPosition(visibleCenter);
	this->addChild(label, 1);

	auto listener = EventListenerTouchOneByOne::create();

	// �^�b�`��������V�[�����Q�[���V�[���Ɉڂ�
	listener->onTouchBegan = [](Touch* touch, Event* event) {
		Director::getInstance()->replaceScene(CGameScene::createScene());
		return true;
	};

	// �C�x���g���X�i�[��o�^
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}
