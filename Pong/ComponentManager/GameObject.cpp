#include "GameObject.h"
//#include "BaseComp.h"

GO::GO()
{
}

GO::~GO()
{
	for (auto it : compMap)
		delete it.second;

	compMap.clear();
}

std::map<std::string, BaseComponent*>& GO::AllComp()
{
	return compMap;
}
