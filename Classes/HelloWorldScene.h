#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
	HelloWorld();

    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	// ボタンを押した際、テスト画像を消す処理
	void deleteTestSprite(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
	cocos2d::Sprite*	m_TestSprite;
};

#endif // __HELLOWORLD_SCENE_H__
