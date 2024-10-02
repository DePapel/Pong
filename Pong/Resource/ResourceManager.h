#pragma once
#include <map>
#include <string>
#include "Resource.h"

enum fileExt
{
	invalid,
	png,
	jpg,
	mp3,
	wav
};

fileExt GetFileExt(std::string filename);

class ResourceManager
{
private:
	ResourceManager() = default;
	~ResourceManager();

	ResourceManager(const ResourceManager&) = delete;
	const ResourceManager& operator=(const ResourceManager&) = delete;

	static ResourceManager* ptr;
public:
	static ResourceManager* GetPtr();

	static void DeletePtr();

	std::map<std::string, Resource*> resMap;

	template<typename T>
	T* GetFn(const std::string& name);

	void UnloadFn(const std::string& name);

	void AllUnloadfn();
};

template<typename T>
inline T* ResourceManager::GetFn(const std::string& name)
{
	auto found = resMap.find(name);
	if (found != resMap.end())
	{
		found->second->IncCnt();
		return static_cast<T*>(found->second);
	}
	else
	{
		std::string ext = name.substr(name.find_last_of("."));
		fileExt extention = GetFileExt(ext);

		if (extention == mp3 || extention == wav)
		{
			T* p = new T();
			p->LoadData(name);
			resMap.insert(std::pair<std::string, Resource*>(name, p));
			return p;
		}
		else if (extention == png || extention == jpg)
		{
			T* p = new T();
			p->LoadData(name);
			resMap.insert(std::pair<std::string, Resource*>(name, p));
			return p;
		}
	}
}
