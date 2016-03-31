#include "CBullet.h"

#include "CGameScene\CGameScene.h"

#include "TagList.h"

USING_NS_CC;

CBullet::CBullet()
	: m_Speed(500.0f)
	, m_Radius(0.0f)
	, m_BulletType(eBULLET_TYPE::PLAYER)
{
}

CBullet* CBullet::create(CBullet::eBULLET_TYPE type)
{
	auto bullet = new CBullet();

	if (bullet != nullptr && bullet->init(type)) {
		bullet->autorelease();
		return bullet;
	}
	else {
		bullet->removeFromParentAndCleanup(true);
		return nullptr;
	}
}

// 初期化
bool CBullet::init(eBULLET_TYPE type)
{
	if (!Sprite::init()) {
		return false;
	}

	this->initWithFile("Bullet.png");
	this->setTag(static_cast<int>(TagList::eNODE_TAG_LIST::BULLET));

	// 半径の計算（画像の縦横のサイズの平均値から直径を取り、/2で半径にする）
	m_Radius = (this->getContentSize().width + this->getContentSize().height) / 2 / 2;
	m_BulletType = type;

	this->scheduleUpdate();

	return true;
}

// 更新
void CBullet::update(float delta)
{
	// 移動
	move(delta);
	objectAndBulletCircleCollision();
}

// 移動
void CBullet::move(float delta)
{
	Vec2 pos = this->getPosition();

	pos.y += m_Speed * delta;

	this->setPosition(pos);
}

// 弾とオブジェクトによる、円と円の衝突判定
void CBullet::objectAndBulletCircleCollision()
{
	// 親（ゲームシーン）から子（敵）の情報を持ってくる
	auto parent = static_cast<CGameScene*>(Director::getInstance()->getRunningScene()->getChildren().at(1));
	Node* object = nullptr;

	// 弾の種類に応じて判定する対象を決める
	switch (m_BulletType)	
	{
	case CBullet::eBULLET_TYPE::PLAYER: object = parent->getChildByTag(static_cast<int>(TagList::eNODE_TAG_LIST::ENEMY));
	default:	break;
	}

	// オブジェクトがなければ終了
	if (object == nullptr)	return;

	Point bulletCenter = this->getPosition();
	Point objectCenter = object->getPosition();
	
	// 半径の計算（画像の縦横のサイズの平均値から直径を取り、/2で半径にする）
	float object_r = (object->getContentSize().width + object->getContentSize().height) / 2 / 2;

	// 円と円の衝突計算
	if (pow(bulletCenter.x - objectCenter.x, 2) +
		pow(bulletCenter.y - objectCenter.y, 2) <= pow(m_Radius + object_r, 2))
	{
		// オブジェクト削除
		object->removeFromParentAndCleanup(true);
		this->removeFromParentAndCleanup(true);
	}
}

// 半径取得
const float CBullet::getRadius()
{
	return m_Radius;
}

const CBullet::eBULLET_TYPE CBullet::getBulletType()
{
	return m_BulletType;
}
