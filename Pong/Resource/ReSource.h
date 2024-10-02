#pragma once
#include <string>

class Resource
{
	int cnt = 0;
protected:
	void* data = nullptr;

public:
	void IncCnt();
	void DecCnt();

	//fn to return the data
	void* GetData();
	//fn to return the cnt
	int GetCnt();
	//virtual fn to Load data
	virtual void LoadData(std::string filename) = 0;
	//virtual fn to UnLoad data
	virtual void UnloadData() = 0;

	virtual ~Resource() {}
};

class MusicResource : public Resource
{
public:
	//LoadData
	void LoadData(std::string filename) override;
	//UnloadData
	void UnloadData() override;
	//destructor
	~MusicResource();

};

class TextureResource : public Resource
{
public:
	void LoadData(std::string filename) override;
	void UnloadData() override;
	~TextureResource();
};
