#ifndef CLAYERSTART_H_
#define CLAYERSTART_H_
#include"cocos2d.h"
USING_NS_CC;
class cLayerStart:public Layer
{
public:
	static Scene* createScene();
	bool init();
	CREATE_FUNC(cLayerStart);
	void easy(Ref*);
	void hard(Ref*);
	void veryHard(Ref*);
	void quit(Ref*);

	enum DEGREE
	{
		EASY=5,HARD=7,VERYHARD=9,
	};
};
#endif