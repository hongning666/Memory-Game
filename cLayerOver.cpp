#include "cLayerOver.h"
#include"cLayerStart.h"


Scene* cLayerOver::createScene(bool res)
{
	Scene *scene = Scene::create();
	cLayerOver *layer = cLayerOver::create(res);
	scene->addChild(layer);
	return scene;
}
cLayerOver *cLayerOver::create(bool res)
{
	cLayerOver *pRet = new cLayerOver;
	if (pRet&&pRet->init(res))
	{
		pRet->autorelease();
	}
	else
	{
		delete pRet;
		pRet = nullptr;
	}
	return pRet;
}
bool cLayerOver::init(bool res)
{
	Layer::init();
	Menu *menu = Menu::create();
	MenuItem *back = MenuItemFont::create("Back", this, menu_selector(cLayerOver::back));
	if (res == true)
	{
		MenuItem *WinItem = MenuItemFont::create("You Win");
		menu->addChild(WinItem);
		menu->addChild(back);
	}
	else
	{
		MenuItem *LoseItem = MenuItemFont::create("You Failed");
		menu->addChild(LoseItem);
		menu->addChild(back);
	}
	menu->alignItemsVerticallyWithPadding(30);
	addChild(menu);
	return true;
}

void cLayerOver::back(Ref* ref)
{
	Scene *scene = cLayerStart::createScene();
	Director::getInstance()->replaceScene(scene);
}
