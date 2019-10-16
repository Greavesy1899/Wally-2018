#include "RefImage.h"

RefImage::RefImage() = default;

RefImage::RefImage(const std::string& fileName, int sizeR, int sizeC)
{
	printf("Created a new instance of the RefImage class. Reading file %s.\n", fileName.c_str());
	ReadData(fileName, sizeR, sizeC);
}

RefImage::~RefImage() = default;
