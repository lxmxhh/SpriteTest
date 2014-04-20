#include "SpriteTestLayer.h"


SpriteTestLayer::SpriteTestLayer(void)
{
}

bool SpriteTestLayer::init()
{
	CCSize s=CCDirector::sharedDirector()->getWinSize();
	/*注意：此处的图片加入，请不要直接copy到工程这个工程的resource下面， 运行的时候是获取不到图片的，
				 工程目录下的资源和工程路径目录下的资源不是同一资源，然后我在工程路径目录下copy新资源到resource下
				 面，然后刷新工程，也刷新不出新添加的图片出来，暂时不知道这是为什么？如果有知道的朋友请给我留言...谢谢！*/
	
	CCSprite* sprite=CCSprite::create("start.png");
	sprite->setAnchorPoint(ccp(0,1));//设置sprite的描点,(0,1)也就是图片的左上角
	sprite->setPosition(ccp(0,s.height));//设置sprite位置
	this->addChild(sprite);

	//sprite的一些基本的操作:缩放、旋转、混色
	m_tamara=CCSprite::create("grossini.png");
	m_tamara->setScaleX( 2.5f);
    m_tamara->setScaleY( -1.0f);
    m_tamara->setPosition(ccp(100,70) );
    m_tamara->setOpacity( 255);//RGBA值RGB+透明度值
	this->addChild(m_tamara);

	m_grossini=CCSprite::create("grossinis_sister1.png");
    m_grossini->setRotation( 120);
    m_grossini->setPosition( ccp(s.width/2, s.height/2));
    m_grossini->setColor( ccc3( 255,0,0));
	this->addChild(m_grossini);

	m_kathia=CCSprite::create("grossinis_sister2.png");
    m_kathia->setPosition( ccp(s.width-100, s.height/2));
    m_kathia->setColor( ccBLUE);
	this->addChild(m_kathia);

	 // Determine speed of the target
    int minDuration = (int)2.0;
    int maxDuration = (int)4.0;
    int rangeDuration = maxDuration - minDuration;
    // srand( TimGetTicks() );
    int actualDuration = ( rand() % rangeDuration )
                                        + minDuration;

    // Create the actions
    CCFiniteTimeAction* actionMove = 
		CCMoveTo::create( (float)actualDuration,  ccp(0 - m_grossini->getContentSize().width/2, s.height/2) );
    CCFiniteTimeAction* actionMoveDone = 
        CCCallFuncN::create( this, 
        callfuncN_selector(SpriteTestLayer::spriteMoveFinished));
    m_grossini->runAction( CCSequence::create(actionMove, 
        actionMoveDone, NULL) );


	CCSize szWin = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint ptCenterOfLayer = CCPointMake(szWin.width/2,szWin.height/2);
	CCSprite* pShoose = CCSprite::create("xuhong.jpg");
	pShoose->setPosition(ptCenterOfLayer);
	this->addChild(pShoose,0,1000);//添加需要拖动的精灵结点

	setTouchEnabled(true);//开启触屏响应
	return true;
}
SpriteTestLayer::~SpriteTestLayer(void)
{
}

void SpriteTestLayer::spriteMoveFinished(CCNode* sender)
{
	CCSprite *sprite = (CCSprite *)sender;
	this->removeChild(sprite, true);
}

void SpriteTestLayer::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);
}

bool SpriteTestLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint ptClick = pTouch->getLocation();
	CCNode *pNode = this->getChildByTag(1000);//SSPrite* pSpr = static_cast<CCSprite *>(this->getChildByTag(1000));
	return pNode->boundingBox().containsPoint(ptClick);//OR pNode->boundingBox().containsPoint(this->convertTouchToNodeSpace(pTouch));判断精灵是否被点击
}
void SpriteTestLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint Diff = pTouch->getDelta();
	CCNode *pNode = this->getChildByTag(1000);
	CCPoint ptCurrent = pNode->getPosition();
	pNode->setPosition(ccpAdd(ptCurrent,Diff));

	CCRect reRect = pNode->boundingBox();
	CCSize szWin = CCDirector::sharedDirector()->getWinSize();
	CCPoint ptLowerLeft = cocos2d::CCPoint(reRect.origin.x,reRect.origin.y);
	CCPoint DeltaOfLowerLeft;
	DeltaOfLowerLeft.x = min(max(reRect.origin.x,0),szWin.width-reRect.size.width)  - ptLowerLeft.x;
	DeltaOfLowerLeft.y = min(max(reRect.origin.y,0),szWin.height-reRect.size.height)- ptLowerLeft.y;
	pNode->setPosition(ccpAdd(pNode->getPosition(),DeltaOfLowerLeft));//锚点移动的"差距"和左下角的是一样的
}
