#include <stdio.h>
#include "LargeImage.h"

using namespace std;

int main()
{
	RefImage wallyImage = RefImage("Wally_grey.txt", 49, 36);
	LargeImage sceneImage = LargeImage("Cluttered_scene.txt", 768, 1024);
	sceneImage.TemplateMatch(wallyImage);
	printf("Succesfully read data.\n");
	sceneImage.WriteBestMatchesToPGM(wallyImage.GetHeight(), wallyImage.GetWidth());
    return 0;
}
