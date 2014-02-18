#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // ����һ������
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // ����һ��HelloWorld��
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // ��ӳ���������
        scene->addChild(layer);
    } while (0);

    return scene;
}

// ��ʼ����ʵ��������
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
       //1����ʼ�����෽��

        CC_BREAK_IF(! CCLayer::init());

       //����������Լ��Ĵ���

        //���һ��MenuItemImage�˵���Ա��������˳�

        //��������״̬ͼƬ�������Ĳ㣬ע�����
        CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        // ���ò˵���λ��
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

        // ����һ���˵����������˵���
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // �������˵�������
        this->addChild(pMenu, 1);

        // ���һ��HelloWorld ��ǩ
        CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
        CC_BREAK_IF(! pLabel);

        // ��ô���Ĵ�С
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 50));

        // ��ӱ�ǩ������
        this->addChild(pLabel, 1);

        // ����һ�����鱳��
        CCSprite* pSprite = CCSprite::create("HelloWorld.png");
        CC_BREAK_IF(! pSprite);

        // ���þ���λ��
        pSprite->setPosition(ccp(size.width/2, size.height/2));

        // ��Ӿ��鵽����
        this->addChild(pSprite, 0);

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // ���menu�˳�
    CCDirector::sharedDirector()->end();
}

