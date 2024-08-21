#pragma once

namespace GSM
{
	class BaseLevel;
	class GameStateManager
	{
		//Singleton == Only 1 obj
		//Prevent others creating me
	private:
		GameStateManager();
		//Remove the compiler defined Copy Constructor and Asignment operator
		GameStateManager(const GameStateManager& other) = delete;
		const GameStateManager& operator= (const GameStateManager& other) = delete;
		~GameStateManager();

		static GameStateManager* ptr;

	public:
		//Get Singleton
		static GameStateManager* GetGSMPtr();
		//Delete Singleton
		static void DeleteGSM();

	private:
		//Have a level
		BaseLevel* previousLevel;
		BaseLevel* currentLevel;

	public:
		//Functions to call Init, Update and Exit
		void Init();
		void Update();
		void Exit();

		//Function to change level
		void ChangeLevel(BaseLevel* newLvl);

		//Function to quit
		bool shouldExit();

		//Function to restart
		//...
	};
}