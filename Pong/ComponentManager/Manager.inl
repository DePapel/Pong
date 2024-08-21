#include "Manager.h"

template<typename T>
inline Manager<T>::Manager<T>()
{
}

template<typename T>
inline void Manager<T>::AddPtr(T* t)
{
	cmpList.push_back(t);
}

template<typename T>
inline void Manager<T>::RemovePtr(T* t)
{
	cmpList.erase(std::find(cmpList.begin(), cmpList.end(), t));
}

template<typename T>
inline void Manager<T>::Update()
{
	for (auto it : cmpList)
		it->Update();
}

template<typename T>
inline Manager<T>* Manager<T>::getPtr()
{
	if (mgrPtr == nullptr)
		mgrPtr = new Manager<T>;


	return mgrPtr;
}

template<typename T>
inline void Manager<T>::Delete()
{
	if (mgrPtr)
		delete mgrPtr;
}


template<typename T>
Manager<T>* Manager<T>::mgrPtr = nullptr;

