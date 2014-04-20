#include "SpriteTestLayer.h"


SpriteTestLayer::SpriteTestLayer(void)
{
}

bool SpriteTestLayer::init()
{
	CCSize s=CCDirector::sharedDirector()->getWinSize();
	/*ע�⣺�˴���ͼƬ���룬�벻Ҫֱ��copy������������̵�resource���棬 ���е�ʱ���ǻ�ȡ����ͼƬ�ģ�
				 ����Ŀ¼�µ���Դ�͹���·��Ŀ¼�µ���Դ����ͬһ��Դ��Ȼ�����ڹ���·��Ŀ¼��copy����Դ��resource��
				 �棬Ȼ��ˢ�¹��̣�Ҳˢ�²�������ӵ�ͼƬ��������ʱ��֪������Ϊʲô�������֪�����������������...лл��*/
	
	CCSprite* sprite=CCSprite::create("start.png");
	sprite->setAnchorPoint(ccp(0,1));//����sprite�����,(0,1)Ҳ����ͼƬ�����Ͻ�
	sprite->setPosition(ccp(0,s.height));//����spriteλ��
	this->addChild(sprite);

	//sprite��һЩ�����Ĳ���:���š���ת����ɫ
	m_tamara=CCSprite::create("grossini.png");
	m_tamara->setScaleX( 2.5f);
    m_tamara->setScaleY( -1.0f);
    m_tamara->setPosition(ccp(100,70) );
    m_tamara->setOpacity( 255);//RGBAֵRGB+͸����ֵ
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
	this->addChild(pShoose,0,1000);//�����Ҫ�϶��ľ�����

	setTouchEnabled(true);//����������Ӧ
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
	return pNode->boundingBox().containsPoint(ptClick);//OR pNode->boundingBox().containsPoint(this->convertTouchToNodeSpace(pTouch));�жϾ����Ƿ񱻵��
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
	pNode->setPosition(ccpAdd(pNode->getPosition(),DeltaOfLowerLeft));//ê���ƶ���"���"�����½ǵ���һ����
}
