#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Player::Player()
{
	// Setting player starting stats
	m_hours_worked_ = 0;
	m_nutrition = 50;
	m_energy = 75;
	m_money = 0;
	m_refigerator = 0;
} 

void Player::Work()
{
	// Prints a new message of different jobs done each time
	srand(time(nullptr));
	int jobPicker = 1 + rand() % 5;

	if (m_nutrition <= 5) // you need at least 5
	{
		std::cout << "I cant give you any jobs in that sorry state check your [Energy or Nutrition!!!]" << std::endl;
		return;
	}
	else if (m_energy <= 5)
	{
		std::cout << "I cant give you any jobs in that sorry state check your [Energy or Nutrition!!!]" << std::endl;
		return;
	}
	else
	{
		if (jobPicker == 1) {
			std::cout << "Today your job is to cook for the kings party" << std::endl;
		}
		if (jobPicker == 2) {
			std::cout << "Today your job is to solve a crime in central" << std::endl;
		}
		if (jobPicker == 3) {
			std::cout << "Today your job is to escort the prince to through the badlands" << std::endl;
		}
		if (jobPicker == 4) {
			std::cout << "Today your job is to kill the bandits south of east ridage" << std::endl;
		}
		if (jobPicker == 5) {
			std::cout << "Today your job is clean the castle walls" << std::endl;
		}

		Player::PlayerJob();

		std::cout << " " << std::endl;
	}
}

void Player::PlayerStats() // Call outside of if (Input == w)
{
	// Prints Players stats
	// Hours worked, Nutrition, Energy, Money
	std::cout << "Hours Worked: " << m_hours_worked_ << std::endl;
	std::cout << "Nutrition: " << m_nutrition << std::endl;
	std::cout << "Energy: " << m_energy << std::endl;
	std::cout << "Money: " << m_money << std::endl;
	std::cout << "Refigerator: " << m_refigerator << std::endl;
	std::cout << " " << std::endl;

}

void Player::PlayerJob()
{
	// Prints a random amout(Between 1 and 10) of hours worked and adds 
	// value to hours worked variable. 
	 
	int randomNum = 1 + rand() % 10;
	 
	if (randomNum <= 5)
	{
		m_hours_worked_ += randomNum;
		m_money += randomNum * 12;
		m_nutrition -= 8;
		m_energy -= 4;
	}

	 
	if (randomNum > 5 && randomNum <= 10)
	{
		m_hours_worked_ += randomNum;
		m_money += randomNum * 12;
		m_nutrition -= 10;
		m_energy -= 8;
	}
}

void Player::PlayerEat()
{
	
	// if frige has food do this...
	if (m_refigerator <= 0)
	{
		m_refigerator = 0;
		std::cout << " " << std::endl;
		std::cout << "I cant eat food I need to go to the [Market]" << std::endl;
		std::cout << " " << std::endl;
		return;
	}
	else if (m_energy <= 4)
	{
		m_energy = 0;
		std::cout << " " << std::endl;
		std::cout << "I cant eat food I need to go to the [Sleep]" << std::endl;
		std::cout << " " << std::endl;
		return;
	}
	else 
	{
		m_refigerator -= 2;
		m_nutrition += 10;
		m_energy -= 5;
	}
	if (m_nutrition <= 100)
	{
		std::cout << " " << std::endl;
		std::cout << "Man Im Fool" << std::endl;
		std::cout << " " << std::endl;
	}
	

}

void Player::PlayerSleep()
{
	if (m_nutrition <= 5)
	{
		std::cout << " " << std::endl;
		std::cout << "You what up from hunger" << std::endl;
		std::cout << " " << std::endl;
		return;
	}
	if (m_energy >= 100)
	{
		std::cout << " " << std::endl;
		std::cout << "I am well rested no need to sleep" << std::endl;
		std::cout << " " << std::endl;
		return;
	}
	m_nutrition -= 5;
	m_energy += 10;
}
void Player::PlayerBuy()
{
	constexpr  int smallFoodBundlePrice = 100;
	constexpr int mediumFoodBundlePrice = 175;
	constexpr int largeFoodBundlePrice = 250;
	int choice;

	constexpr int smallFoodBundle = 0;
	constexpr int mediumFoodBundle = 1;
	constexpr int largeFoodBundle = 2;

	if (m_energy <= 4)
	{
		std::cout << " " << std::endl;
		std::cout << "Too tired need sleep first" << std::endl;
		std::cout << " " << std::endl;
		return;
	}

	std::cout << "Hey Jack hows it going thease days? How can i help you" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "0)" << "Small Food Bundle: " << smallFoodBundlePrice << std::endl;
	std::cout << "1)" << "Meduim Food Bundle: " << mediumFoodBundlePrice << std::endl;
	std::cout << "2)" << "Large Food Bundle: " << largeFoodBundlePrice << std::endl;

	std::cin >> choice;
	// Just trying out new concepts
	switch (choice)
	{
	case smallFoodBundle:
		if (m_money < smallFoodBundlePrice)
		{
			std::cout << " " << std::endl;
			std::cout << "COME BACK WHEN YOU HAVE THE MONEY JACK!!!!! [You were kicked out]" << std::endl;
			std::cout << " " << std::endl;
		}
		else
		{
			m_money -= smallFoodBundlePrice;
			m_refigerator += 24;
			std::cout << " " << std::endl;
			std::cout << "You Obtained the Small Food Bundle" << std::endl;
			std::cout << " " << std::endl;
		}
		break;
	case mediumFoodBundle:
		if (m_money < mediumFoodBundlePrice)
		{
			std::cout << " " << std::endl;
			std::cout << "COME BACK WHEN YOU HAVE THE MONEY JACK!!!!! [You were kicked out]" << std::endl;
			std::cout << " " << std::endl;
		}
		else
		{
			m_money -= mediumFoodBundlePrice;
			m_refigerator += 58;
			std::cout << " " << std::endl;
			std::cout << "You Obtained the Medium Food Bundle" << std::endl;
			std::cout << " " << std::endl;
		}
		break;
	case largeFoodBundle:
		if (m_money < largeFoodBundlePrice)
		{
			std::cout << " " << std::endl;
			std::cout << "COME BACK WHEN YOU HAVE THE MONEY JACK!!!!! [You were kicked out]" << std::endl;
			std::cout << " " << std::endl;
		}
		else
		{
			m_money -= largeFoodBundlePrice;
			m_refigerator += 100;
			std::cout << " " << std::endl;
			std::cout << "You Obtained the Large Food Bundle" << std::endl;
			std::cout << " " << std::endl;
		}
	default:
		std::cout << "WE DONT HAVE THAT SO BEAT IT!!";
		break;
	}
}

// Cheat Mode

void Player::SetRefrigerator()
{
	m_refigerator += 100;
}
void Player::SetEnergy()
{
	m_energy += 100;
}
void Player::SetNutrition()
{
	m_nutrition += 100;
}
void Player::SetMoney()
{
	m_money += 1000;
}





// Player should be able to buy food if they have m_money
// when they but food the frige will increase its number buy
// a certain amount.
