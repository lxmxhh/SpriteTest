#include "SpriteTestScene.h"


SpriteTestScene::SpriteTestScene(void)
{
}


SpriteTestScene::~SpriteTestScene(void)
{
}

CCScene* SpriteTestScene::scene()
{
	CCScene* scene=CCScene::create();
	SpriteTestLayer* layer=SpriteTestLayer::create();
	scene->addChild(layer);
	return scene;
}
