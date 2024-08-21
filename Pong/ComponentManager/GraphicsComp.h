#pragma once
#include "../ComponentManager/Manager.h"
#include "BaseComp.h"

class GraphicsComp : public BaseComponent
{
public:
	GraphicsComp(GO* owner);
	~GraphicsComp();
};