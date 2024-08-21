#include <typeinfo>
#include "GameObject.h"

template<typename T>
inline T* GO::FindComp() const
{
	auto it = this->compMap.find(typeid(T).name());
	if (it != compMap.end())
		return static_cast<T*>(it->second);

	return nullptr;
}

template<typename T>
T* GO::AddComp()
{
	if (FindComp<T>() != nullptr)
		return nullptr;

	T* cmp = new T(this);

	if (cmp)
		this->compMap.insert(std::pair < std::string, BaseComponent*>(typeid(T).name(), cmp));

	return cmp;
}

template<typename T>
inline bool GO::RemoveComp()
{
	T* c = FindComp<T>();

	if (c != nullptr)
	{
		delete c;
		compMap.erase(typeid(T).name());
		return true;
	}

	return false;
}