#ifndef CLAYERGAME_H_
#define CLAYERGAME_H_
#include"cocos2d.h"
#include<vector>
using namespace std;
USING_NS_CC;
class cLayerGame:public Layer
{
public:
	static Scene* createScene(int degree);
	static cLayerGame* create(int degree);
	bool init(int degree);

	void getAllPoint();
	void getAvailablePoint();
	void addCard();
	void showCardAllWhite(float detal);

	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);

	PointArray *allPoints;
	Array      *allCards;
	vector<int> vec;

	CC_SYNTHESIZE(int, _degree, Degree);
	CC_SYNTHESIZE(int, _clickStart, ClickStrat);
};

#endif