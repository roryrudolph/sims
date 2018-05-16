#ifndef MESHLOADER_H
#define MESHLOADER_H


#include "Object.h"
#include <vector>


class ObjectLoader
{
public:
	static void loadFromFile(const char *filepath, Object *object);

private:
	ObjectLoader();
};


#endif //MESHLOADER_H
