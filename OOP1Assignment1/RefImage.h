#pragma once
#ifndef REF_IMAGECLASS_FILE
#define REF_IMAGECLASS_FILE
#include "BaseImage.h"

class RefImage : public BaseImage {
private:
public:
	RefImage();
	RefImage(const std::string& fileName, int sizeR, int sizeC);
	~RefImage();
};

#endif
#pragma once
