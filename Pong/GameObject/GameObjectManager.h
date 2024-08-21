#pragma once
#include <list>

class GO;

class GOManager
{
	std::list<GO*> allObj;
	GOManager() = default;
	GOManager(const GOManager&) = delete;
	const GOManager& operator=(const GOManager&) = delete;
	~GOManager();
	static GOManager* ptr;

public:
	static GOManager* GetPtr();

	std::list<GO*> AllObj();
	GO* AddObj();
	void RemoveObj(GO* g);
	GO* GetLastObj();
};