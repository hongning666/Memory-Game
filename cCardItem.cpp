#include "cCardItem.h"


cCardItem* cCardItem::create(int index)
{
	cCardItem* pRet = new cCardItem;
	if (pRet&&pRet->init(index))
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
bool cCardItem::init(int index)
{
	Sprite::init();

	setIndex(index);
	setContentSize(CCSizeMake(80, 80));
	setAnchorPoint(Vec2(0,0));
	String *str = String::createWithFormat("%d", index);
	ttf = LabelTTF::create(str->getCString(), "Courier new", 30);
	ttf->setPosition(40, 40);
	addChild(ttf);

	bg = Sprite::create();
	bg->setTextureRect(CCRectMake(0, 0, 77, 77));
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setColor(Color3B(255, 255, 255));
	addChild(bg); 


	return true;
}
void cCardItem::showWhite()
{
	ttf->setVisible(false);
	bg->setVisible(true);
}
void cCardItem::showText()
{
	ttf->setVisible(true);
	bg->setVisible(false);
}