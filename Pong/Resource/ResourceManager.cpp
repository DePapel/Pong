#include "ResourceManager.h"

ResourceManager* ResourceManager::ptr = nullptr;

ResourceManager::~ResourceManager()
{
}

ResourceManager* ResourceManager::GetPtr()
{
	if (ptr == nullptr)
		ptr = new ResourceManager();

	return ptr;
}

void ResourceManager::DeletePtr()
{
	if (ptr != nullptr)
		delete ptr;

	ptr = nullptr;
}

void ResourceManager::UnloadFn(const std::string& name)
{
	auto found = resMap.find(name);
	if (found != resMap.end())
	{
		found->second->DecCnt();

		if (found->second->GetCnt() == 0)
		{
			found->second->UnloadData();
			delete found->second;
			resMap.erase(found);
		}
	}
}

void ResourceManager::AllUnloadfn()
{
	for (auto it : resMap)
	{
		it.second->UnloadData();
		delete it.second;
	}

	resMap.clear();
}

fileExt GetFileExt(std::string filename)
{
	if (filename == ".png") return png;
	if (filename == ".jpg") return jpg;
	if (filename == ".mp3") return mp3;
	if (filename == ".wav") return wav;
	return invalid;
}
