#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class SpriteTestLayer :public CCLayer
{
public:
	SpriteTestLayer(void);
	~SpriteTestLayer(void);

	void spriteMoveFinished(CCNode* sender);

	virtual void registerWithTouchDispatcher();

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	// 这个方法从父类虚拟函数继承过来，在创建HelloWorld层的时候会调用此方法
    virtual bool init();  
	CREATE_FUNC(SpriteTestLayer);
private:
	typedef CCSprite* CCSPRITE;
	CCSPRITE m_tamara,m_grossini,m_kathia;
};

