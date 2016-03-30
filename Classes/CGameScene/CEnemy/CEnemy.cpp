#include "CEnemy.h"
#include "TagList.h"

USING_NS_CC;

// 初期化　
bool CEnemy::init()
{
	if (!Sprite::init()) {
		return false;
	}

	this->initWithFile("Enemy.png");

	// 半径の計算（画像の縦横のサイズの平均値）
	m_Radius = (this->getContentSize().width + this->getContentSize().height) / 2 / 2;

	return true;
}

// 半径取得
float CEnemy::getRadius()
{
	return m_Radius;
}
