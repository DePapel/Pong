#pragma once

//#include "../RTTI/BaseRTTI.h"
class GO;

//class BaseComponent : public BaseRTTI
class BaseComponent
{
	BaseComponent() = delete;
	BaseComponent(const BaseComponent&) = delete;

protected:
	GO* mOwner;
	bool active;

public:
	BaseComponent(GO* owner) : mOwner(owner), active(true) {};
	virtual ~BaseComponent() {}

	virtual bool Update() = 0
	{
		return active;
	}
};