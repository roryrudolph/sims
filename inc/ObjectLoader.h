#ifndef OBJECTLOADER_H
#define OBJECTLOADER_H


#include "Object.h"
#include <vector>


class ObjectLoader
{
public:
	static void loadFromFile(const char *filepath, Object *object);

private:
	ObjectLoader();
};


#endif //OBJECTLOADER_H
