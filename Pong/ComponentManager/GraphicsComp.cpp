#include "GraphicsComp.h"

GraphicsComp::GraphicsComp(GO* owner) : BaseComponent(owner)
{
	//Add to the manager
	Manager<GraphicsComp> ::getPtr()->AddPtr(this);
}

GraphicsComp::~GraphicsComp()
{
	//Remove from the manager
	Manager<GraphicsComp>::getPtr()->RemovePtr(this);
}

