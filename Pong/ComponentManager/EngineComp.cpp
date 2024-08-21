#include "EngineComp.h"
#include "../ComponentManager/Manager.h"

EngineComp::EngineComp(GO* owner) : BaseComponent(owner)
{
	//Add to the manager
	Manager<EngineComp>::getPtr()->AddPtr(this);
}

EngineComp::~EngineComp()
{
	//Remove from the manager
	Manager<EngineComp>::getPtr()->RemovePtr(this);
}


