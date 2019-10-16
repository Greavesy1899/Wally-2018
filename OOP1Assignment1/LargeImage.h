#pragma once
#ifndef LARGE_IMAGECLASS_FILE
#define LARGE_IMAGECLASS_FILE
#include "BaseImage.h"
#include "RefImage.h"
#include <vector>

class LargeImage : public BaseImage {
private:
	std::vector<MatchStruct> bestMatches;
public:
	//constructors/destructors.
	LargeImage();
	LargeImage(std::string fileName, int sizeR, int sizeC);
	~LargeImage();

	//methods
	void TemplateMatch(RefImage &refImage);
	void WriteBestMatchesToPGM(int h, int w);
	int CheckCentrePoint(int x, int y, RefImage & refImage);
};

#endif