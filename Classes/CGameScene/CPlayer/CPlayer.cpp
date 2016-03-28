#include "CPlayer.h"

USING_NS_CC;

CPlayer::CPlayer()
{
}

// ‰Šú‰»
bool CPlayer::init()
{
	if (!Sprite::init()) {
		return false;
	}

	this->initWithFile("Player.png");

	return true;
}
