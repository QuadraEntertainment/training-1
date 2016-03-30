#include "CEnemy.h"

USING_NS_CC;

// ‰Šú‰»
bool CEnemy::init()
{
	if (!Sprite::init()) {
		return false;
	}

	this->initWithFile("Enemy.png");

	return true;
}
