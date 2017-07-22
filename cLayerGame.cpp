#include "cLayerGame.h"
#include<stdlib.h>
#include<time.h>
#include"cCardItem.h"
#include"cLayerOver.h"



Scene* cLayerGame::createScene(int degree)
{
	Scene *scene = Scene::create();
	cLayerGame *layer = cLayerGame::create(degree);
	scene->addChild(layer);
	return scene;
}
cLayerGame* cLayerGame::create(int degree)
{
	cLayerGame *pRet = new cLayerGame;
	if (pRet&&pRet->init(degree))
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
bool cLayerGame::init(int degree)
{
	Layer::init();

	setDegree(degree);
	setClickStrat(0);
	getAllPoint();
	getAvailablePoint();
	addCard();

	scheduleOnce(schedule_selector(cLayerGame::showCardAllWhite), 2);

	return true;
}

void cLayerGame::getAllPoint()
{
	allPoints = PointArray::create(60);
	allPoints->retain();
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			allPoints->addControlPoint(Vec2(80 * i, 80 * j));
		}
	}
}
void cLayerGame::getAvailablePoint()
{
	srand((unsigned)time(nullptr));
	while (1)
	{
		int index = rand() % 60;
		vector<int>::iterator itr = vec.begin();
		for (; itr != vec.end(); ++itr)
		{
			if (*itr == index)
			{
				break;
			}
		}
		if (itr == vec.end())
		{
			vec.push_back(index);
			if (vec.size() == getDegree())
				break;
		}
	}
}
void cLayerGame::addCard()
{
	allCards = Array::create();
	allCards->retain();
	for (int i = 0; i < getDegree(); i++)
	{
		cCardItem *item = cCardItem::create(i);
		item->setPosition(allPoints->getControlPointAtIndex(vec[i]));
		addChild(item);
		item->showText();
		allCards->addObject(item);
	}
}

bool cLayerGame::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	for (int i = 0; i < allCards->count(); i++)
	{
		if (((cCardItem*)allCards->objectAtIndex(i))->boundingBox().containsPoint(pTouch->getLocation()))
		{
			if (getClickStrat() == ((cCardItem*)allCards->objectAtIndex(i))->getIndex())
			{
				((cCardItem*)allCards->objectAtIndex(i))->removeFromParentAndCleanup(true);
				allCards->removeObjectAtIndex(i);
				if (allCards->count() == 0)
				{
					Scene *scene = cLayerOver::createScene(true);
					Director::getInstance()->replaceScene(scene);
				}
			}
			else
			{
				Scene *scene = cLayerOver::createScene(false);
				Director::getInstance()->replaceScene(scene);
			}
			_clickStart++;
		}
	}
	return true;
}
void cLayerGame::showCardAllWhite(float detal)
{
	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);
	Object *obj;
	CCARRAY_FOREACH(allCards,obj)
	{
		cCardItem *spr = (cCardItem*)obj;
		spr->showWhite();
	}
}

