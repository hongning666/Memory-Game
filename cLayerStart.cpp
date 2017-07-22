#include "cLayerStart.h"
#include"cLayerGame.h"


Scene* cLayerStart::createScene()
{
	auto scene = Scene::create();
	auto layer = cLayerStart::create();
	scene->addChild(layer);
	return scene;
}
bool cLayerStart::init()
{
	Layer::init();
	LabelBMFont* game_name = LabelBMFont::create("CARD GAME", "bitmapFontTest.fnt");
	game_name->setScale(3);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	LabelBMFont* author = LabelBMFont::create("By --ZCJ", "bitmapFontTest.fnt");
	author->setPosition(visibleSize.width - (author->getContentSize().width) / 2-150, author->getContentSize().height+40);
	author->setScale(2);
	addChild(author);
	game_name->setAnchorPoint(Vec2(0.5, 1));
	game_name->setPosition(visibleSize.width/2,visibleSize.height);
	addChild(game_name);
	MenuItem *easy = MenuItemFont::create("Easy",this,menu_selector(cLayerStart::easy));
	MenuItem *hard = MenuItemFont::create("Hard",this, menu_selector(cLayerStart::hard));
	MenuItem *veryhard = MenuItemFont::create("VeryHard",this ,menu_selector(cLayerStart::veryHard));
	MenuItem *quit = MenuItemFont::create("Quit",this, menu_selector(cLayerStart::quit));

	Menu *menu = Menu::create(easy, hard, veryhard, quit, NULL);
	menu->alignItemsVerticallyWithPadding(20);
	addChild(menu);
	return true;
}
void cLayerStart::easy(Ref* ref)
{
	Scene* scene = cLayerGame::createScene(EASY);
	Director::getInstance()->replaceScene(scene);
}
void cLayerStart::hard(Ref* ref)
{
	Scene* scene = cLayerGame::createScene(HARD);
	Director::getInstance()->replaceScene(scene);
}
void cLayerStart::veryHard(Ref* ref)
{
	Scene* scene = cLayerGame::createScene(VERYHARD);
	Director::getInstance()->replaceScene(scene);
}
void cLayerStart::quit(Ref* ref)
{
	exit(0);
}