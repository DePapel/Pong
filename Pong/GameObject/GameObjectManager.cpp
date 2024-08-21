#include "GameObjectManager.h"
#include "../ComponentManager/GameObject.h"

GOManager* GOManager::ptr = nullptr;

GOManager::~GOManager()
{
	for (GO* g : allObj)
		delete g;

	allObj.clear();
}

GOManager* GOManager::GetPtr()
{
	if (ptr != nullptr)
		ptr = new GOManager;

	return ptr;
}

std::list<GO*> GOManager::AllObj()
{
	return allObj;
}

GO* GOManager::AddObj()
{
	GO* g = new GO;

	if (g)
		allObj.push_back(g);


	return g;
}

void GOManager::RemoveObj(GO* g)
{
	if (std::find(allObj.begin(), allObj.end(), g) != allObj.end())
	{
		delete g;
		allObj.remove(g);
	}
}

GO* GOManager::GetLastObj()
{
	return allObj.back();
}
