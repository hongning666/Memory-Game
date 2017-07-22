#ifndef CLAYEROVER_H_
#define CLAYEROVER_H_
#include"cocos2d.h"
USING_NS_CC;
class cLayerOver:public Layer
{
public:
	static Scene* createScene(bool res);
	static cLayerOver *create(bool res);
	bool init(bool res);

	void back(Ref* ref);
};
#endif
