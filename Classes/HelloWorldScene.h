#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

//#include "SimpleAudioEngine.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    // ��������Ӹ������⺯���̳й������ڴ���HelloWorld���ʱ�����ô˷���
    virtual bool init();  

    //���������ľ�̬����
    static cocos2d::CCScene* scene();
    
    // menu���ص��ô˷���
    void menuCloseCallback(CCObject* pSender);

    // �̳и����Ĵ�����ʽ
    CREATE_FUNC(HelloWorld);
};

#endif  // __HELLOWORLD_SCENE_H__