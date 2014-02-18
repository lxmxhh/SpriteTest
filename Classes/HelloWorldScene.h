#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

//#include "SimpleAudioEngine.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    // 这个方法从父类虚拟函数继承过来，在创建HelloWorld层的时候会调用此方法
    virtual bool init();  

    //创建场景的静态方法
    static cocos2d::CCScene* scene();
    
    // menu返回调用此方法
    void menuCloseCallback(CCObject* pSender);

    // 继承父类层的创建方式
    CREATE_FUNC(HelloWorld);
};

#endif  // __HELLOWORLD_SCENE_H__