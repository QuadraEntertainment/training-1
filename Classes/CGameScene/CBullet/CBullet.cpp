#include "CBullet.h"

#include "CGameScene\CGameScene.h"
#include "CGameScene\CEnemy\CEnemy.h"

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

	if (bullet && bullet->init(type)) {
		bullet->autorelease();
		return bullet;
	}

	CC_SAFE_DELETE(bullet);
	return nullptr;
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
	case CBullet::eBULLET_TYPE::PLAYER: object = parent->getChildByTag(static_cast<int>(TagList::eNODE_TAG_LIST::ENEMY));	break;
	default:	break;
	}

	// オブジェクトがなければ終了
	if (object == nullptr)	return;

	Point bulletCenter = this->getPosition();
	Point objectCenter = object->getPosition();
	
	float object_r = 0.0f;

	// 半径取得
	switch (m_BulletType)
	{
	case CBullet::eBULLET_TYPE::PLAYER: {
		auto o = dynamic_cast<CEnemy*>(object);
		if (o != nullptr){
			object_r = o->getRadius();
		}
	} break;
	default:	break;
	}

	if (object_r <= 0.0f)	return;

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
float CBullet::getRadius() const
{
	return m_Radius;
}

CBullet::eBULLET_TYPE CBullet::getBulletType() const
{
	return m_BulletType;
}
