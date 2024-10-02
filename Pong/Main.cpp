// ---------------------------------------------------------------------------
// includes

#include <crtdbg.h> // To check for memory leaks
#include "AEEngine.h"
#include <AEMtx33.h>
#include <AEVec2.h>
#include <AELineSegment2.h>
#include "GSM/myGameStateManager.h"
#include "GSM/myMainLevel.h"
#include "GSM/myGoalLevel.h"
// ---------------------------------------------------------------------------
// main

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);


	int gGameRunning = 1;

	// Initialization of your own variables go here

	// Using custom window procedure
	AESysInit(hInstance, nCmdShow, 1600, 900, 1, 60, true, NULL);
	AEGfxSetBackgroundColor(0.f, 0.f, 0.f);
	// Changing the window title
	AESysSetWindowTitle("Donghan_Pong");

	GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();

	//s8 pFont = AEGfxCreateFont("Assets/esamanru-Bold.ttf", 72);
	//AEGfxMeshStart();
	//AEGfxTriAdd(
	//	-0.5f, -0.5f, 0xFFFFFFFF, 0.0f, 1.0f,
	//	0.5f, -0.5f, 0xFFFFFFFF, 1.0f, 1.0f,
	//	-0.5f, 0.5f, 0xFFFFFFFF, 0.0f, 0.0f);
	//
	//AEGfxTriAdd(
	//	0.5f, -0.5f, 0xFFFFFFFF, 1.0f, 1.0f,
	//	0.5f, 0.5f, 0xFFFFFFFF, 1.0f, 0.0f,
	//	-0.5f, 0.5f, 0xFFFFFFFF, 0.0f, 0.0f);
	//AEGfxVertexList* pMesh = AEGfxMeshEnd();

	// reset the system modules
	AESysReset();

	gsm->ChangeLevel(new Levels::MainLevel);

	// Game Loop
	while (gGameRunning)
	{
		// Informing the system about the loop's start
		AESysFrameStart();

		gsm->Update();
		// Your own update logic goes here

		// Your own rendering logic goes here

		// Informing the system about the loop's end
		AESysFrameEnd();

		// check if forcing the application to quit
		if (AEInputCheckTriggered(AEVK_ESCAPE) || 0 == AESysDoesWindowExist())
			gGameRunning = 0;
	}
	gsm->DeleteGSM();
	// free the system
	//AEGfxMeshFree(pMesh);
	AESysExit();
}


//Component Base Architecture

// A component will be a class which will have the logic instead of the
// GO. They will have a hierachy class structure to have similar interfaces

////////	GO class	//////////////////////////////////
// GO now will have a container of BaseComponent*
// BaseComponent will be an abstract class (an interface) on how we will
// declare component in our game
// 
// GO will have a function to add ANY TYPE
// of component class to their container
//
// GO will have a function to find if it already has a 
// component of ANY TYPE
// 
// GO will have a function to delete ANY TYPE of component
// 
// Components in the GO container are ALLOCATED IN THE HEAP,
// so. When the GO is destroyed, the GO must be as well
// 
// ////////////////////////////////////////////

////////	BaseComponent class	//////////////////////////////////
//
// Abstract class, provides interface
// 
// Update function -> performs the logic, all my inherited 
//	classes will use the function with the same syntax
// 
// To support polymorphism we MUST make this interface virtual
// 
// virtual Destructor!!!
// 
// GO* owner.
// 
// I CAN NOT exist WITHOUT AN OWNER
// 
// /////////////////////////////////
// 
// What does copy a GO mean?
// What does copy a Component mean?
// 
// /////////////////////////////////
// 
// Split components into:
//	LogicComponents -> Gamplay specific
//	EngineComponents -> Engine specific (physics, maths...)
//	GraphicsComponents -> Graphics specifics (Draw(), handle image...)
// 
// Each of those WILL have a manager of their own
// 
// /////	Manager class	//////////////////
// 			
// Manage components of a certain type (Logic, Engine, Graphics)
// 
// Only 1 manager of a certain type can exist at a time (Singleton)
// 
// Upadates ALL COMPONENTS of a certain type
//   - Whenever a component of a certain type is created, add it to the 
//		manager
// 
// Container for the components!
// 
// ////////////////////
// 
// Use the GSM levels to call the update and so on
// 
// ///////////////////
// 
// Transform component -> Has the pos, rot, scale of the GO
// Some Logic components to do a simulation -> Use prints for behaviour
//											-> accesses other objects
//											-> moves 
//											-> ...
// Extra credit:
// Sprite Component -> Draw the object
// Audio Component -> Play audio
// 
// 
// 
// 
// 
//
