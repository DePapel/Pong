#pragma once
#include <list>

template<typename T>
class Manager
{
	std::list<T*> cmpList;
	static Manager<T>* mgrPtr;

	friend T;

	void AddPtr(T* t);
	void RemovePtr(T* t);
	~Manager<T>() { cmpList.clear(); }

public:
	void Update();

	Manager<T>();
	static Manager<T>* getPtr();
	static void Delete();
};

#include "Manager.inl"

