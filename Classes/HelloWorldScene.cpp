#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 创建一个场景
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 创建一个HelloWorld层
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // 添加场景到层中
        scene->addChild(layer);
    } while (0);

    return scene;
}

// 初始化层实例对象函数
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
       //1、初始化父类方法

        CC_BREAK_IF(! CCLayer::init());

       //下面添加你自己的代码

        //添加一个MenuItemImage菜单项，以便后面你的退出

        //传递两张状态图片，监听的层，注册监听
        CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        // 设置菜单的位置
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

        // 创建一个菜单，来包含菜单项
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // 添加这个菜单到层中
        this->addChild(pMenu, 1);

        // 添加一个HelloWorld 标签
        CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
        CC_BREAK_IF(! pLabel);

        // 获得窗体的大小
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 50));

        // 添加标签到层中
        this->addChild(pLabel, 1);

        // 创建一个精灵背景
        CCSprite* pSprite = CCSprite::create("HelloWorld.png");
        CC_BREAK_IF(! pSprite);

        // 设置精灵位置
        pSprite->setPosition(ccp(size.width/2, size.height/2));

        // 添加精灵到层中
        this->addChild(pSprite, 0);

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // 点击menu退出
    CCDirector::sharedDirector()->end();
}

