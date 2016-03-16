#pragma once

#include "gameNode.h"
#define PuzzleNum 16

struct tagImage
{
	RECT imageRC;
	int num;
};

class gameStudy : public gameNode
{
private:
	image* _background;
	tagImage _image[PuzzleNum];
public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void imageSetting(void);
	void shuffle(tagImage* image);
	void rectMove(tagImage * image, int index);
};

