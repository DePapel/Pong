#pragma once
////////	GO class	//////////////////////////////////
// BaseComponent will be an abstract class (an interface) on how we will declare component in our game

// Components in the GO container are ALLOCATED IN THE HEAP,
// so. When the GO is destroyed, the GO must be as well
#include <map>
#include <string>
class BaseComponent;

class GO
{
	// GO now will have a container of BaseComponent*
	std::map<std::string, BaseComponent*> compMap;

public:
	GO();
	~GO();

	// GO will have a function to "add" ANY TYPE of component class to their container
	template<typename T>
	T* AddComp();

	// GO will have a function to "find" if it already has a component of ANY TYPE
	template<typename T>
	T* FindComp() const;

	// GO will have a function to "delete" ANY TYPE of component
	template<typename T>
	bool RemoveComp();

	//void AddComp(std::string, BaseComponent*);
	std::map<std::string, BaseComponent*>& AllComp();
};

#include "GameObject.inl"