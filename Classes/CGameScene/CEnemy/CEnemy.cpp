#include "CEnemy.h"
#include "TagList.h"

USING_NS_CC;

CEnemy::CEnemy()
	: m_Radius(0.0f)
{
}

// 初期化　
bool CEnemy::init()
{
	if (!Sprite::init()) {
		return false;
	}

	this->initWithFile("Enemy.png");
	this->setTag(static_cast<int>(TagList::eNODE_TAG_LIST::ENEMY));

	// 半径の計算（画像の縦横のサイズの平均値）
	m_Radius = (this->getContentSize().width + this->getContentSize().height) / 2 / 2;

	return true;
}

// 半径取得
const float CEnemy::getRadius()
{
	return m_Radius;
}
