// Work_Simulator_02B_ClassesHomeWork.cpp
// Jaylin Ferrell
#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1
#define RELEASE 2


#define GAME_MODE DEBUG // To use debug mode change to GAME_MODE DEBUG; * I didn't know how to change macros off of in put
// Do they even still exist after the preprocessor processes them??

int main()
{

#if(GAME_MODE == DEBUG)
	std::cout << "Do the thing" << std::endl;
	srand(time(nullptr));
	Player Jack;


	std::cout << "You are a Jack of all Trades so lets put all your skills to use" << std::endl;
	std::cout << " " << std::endl;
	Jack.PlayerStats();
	std::string input;

	while (input != "q")
	{

		std::cout << "What would you like to do?" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "[w]ork" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "[e]at" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "[s]leep" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "[m]arket" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "[q]uit" << std::endl;
		std::cout << " " << std::endl;

		std::cout << "DEBUG PANEL" << std::endl;
		std::cout << "[100food]" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "[100energy]" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "[100nutrition]" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "[1000money]" << std::endl;

		std::cin >> input;

		if (input == "w")
		{
			#if (LOG_ON == true)
			LOG("Jack goes to work")
			#endif

			Jack.Work();
			Jack.PlayerStats();
		}
		else if (input == "e")
		{
			#if (LOG_ON == true)
			LOG("Jack eats food")
			#endif

			Jack.PlayerEat();
			Jack.PlayerStats();
		}
		else if (input == "s")
		{
			#if (LOG_ON == true)
			LOG("Jack goes to sleep")
			#endif

			Jack.PlayerSleep();
			Jack.PlayerStats();
		}
		// add input for going to market
		else if (input == "m")
		{
			#if (LOG_ON == true)
			LOG("Jack goes to the market") // A lot of repeating so i maybe should put this in a function
			#endif

			Jack.PlayerBuy();
			Jack.PlayerStats();
		}
		else if (input == "100food")
		{
			Jack.SetRefrigerator();
			Jack.PlayerStats();
		}
		else if (input == "100energy")
		{
			Jack.SetEnergy();
			Jack.PlayerStats();
		}
		else if (input == "100nutrition")
		{
			Jack.SetNutrition();
			Jack.PlayerStats();
		}
		else if (input == "1000money")
		{
			Jack.SetMoney();
			Jack.PlayerStats();
		}
	}

#elif (GAME_MODE == RELEASE)
	srand(time(nullptr));
	Player Jack;

	
	std::cout << "You are a Jack of all Trades so lets put all your skills to use" << std::endl;
	std::cout << " " << std::endl;
	Jack.PlayerStats();
	std::string input;

	while (input != "q") 
	{		

		std::cout << "What would you like to do?" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "[w]ork" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "[e]at" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "[s]leep" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "[q]uit" << std::endl;
		std::cout << " " << std::endl;
		// ask player if they would like to travel to the market.
		std::cout << "[m]arket" << std::endl;

		std::cin >> input;

		if (input == "w")
		{
			Jack.Work();
			Jack.PlayerStats();
		}
		else if (input == "e")
		{
			Jack.PlayerEat();
			Jack.PlayerStats();
		}
		else if (input == "s")
		{
			Jack.PlayerSleep();
			Jack.PlayerStats();
		}
		// add input for going to market
		else if (input == "m")
		{
			Jack.PlayerBuy();
			Jack.PlayerStats();
		}
	}
#endif

	return 0;
}

