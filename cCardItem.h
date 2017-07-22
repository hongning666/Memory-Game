#ifndef CCARDITEM_H_
#define CCARDITEM_H_
#include"cocos2d.h"
USING_NS_CC;
class cCardItem:public Sprite
{
public:
	static cCardItem* create(int index);
	bool init(int index);

	void showWhite();
	void showText();

	LabelTTF *ttf;
	Sprite* bg;

	CC_SYNTHESIZE(int, _index, Index);
};

#endif