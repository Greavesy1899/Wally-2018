#include "BaseImage.h"

//basic constructor.
BaseImage::BaseImage()
{
	this->data = nullptr;
	this->width = 0;
	this->height = 0;
	this->length = 0;
}

BaseImage::BaseImage(int sizeR, int sizeC)
{
	width = sizeC;
	height = sizeR;
	length = sizeC * sizeR;
	data = new double[length];

	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y < width; y++)
			data[x + (width*y)] = 0.0;
	}
}

//more complex constructor; input name of file as well as the width and height of the image.
BaseImage::BaseImage(const std::string& fileName, int sizeR, int sizeC)
{
	ReadData(fileName, sizeR, sizeC);
}

//destructor to delete the data at the end; this is to plug any leaks. (haha get it!?!?)
BaseImage::~BaseImage()
{
	delete[] data;
}

//I'd like to still be able to use this without having the width or height set.
void BaseImage::ReadData(const std::string& fileName, int sizeR, int sizeC)
{
	data = read_text(fileName, sizeR, sizeC);
	width = sizeC;
	height = sizeR;
	length = sizeC * sizeR;
}

void BaseImage::WritePGM(const std::string& fileName, double* data, int h, int w)
{
	write_pgm(fileName, data, height, width, 255);
}

//get the values from the data. If the user asks for out of bounds data, it will throw an error.
double BaseImage::GetValueAt(int x, int y) const
{
	double value = NULL;
	if ((x >= 0) && (x < width))
	{
		if((y >= 0) && (y < height))
			value = data[x + (width*y)];
	}
	else
	{
		value = -1;
	}

	return value;
}

//set the value at the desired point in the data. If the user asks for out of bounds data, it will throw an error.
void BaseImage::SetValueAt(int x, int y, double value)
{
	if ((x >= 0) && (x < width))
	{
		if ((y >= 0) && (y < height))
			data[x + (width*y)] = value;
	}
	else
	{
		printf("ERROR: x or y is out of bounds.\n");
	}
}

int BaseImage::GetWidth() const
{
	return this->width;
}

int BaseImage::GetLength() const
{
	return this->length;
}

int BaseImage::GetHeight() const
{
	return this->height;
}
