#include "LogicComp.h"
#include "../ComponentManager/Manager.h"

LogicComp::LogicComp(GO* owner) : BaseComponent(owner)
{
	//Add to the manager
	Manager<LogicComp>::getPtr()->AddPtr(this);
}

LogicComp::~LogicComp()
{
	//Remove from the manager
	Manager<LogicComp>::getPtr()->RemovePtr(this);
}