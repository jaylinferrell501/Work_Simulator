#pragma once
#define LOG_ON true

#if (LOG_ON == true) 
#define LOG(message) std::cout << message << std::endl;\
{													   \
	std::cout << "File: " << __FILE__ << std::endl;		\
	std::cout << "Fuction: " << __func__ << std::endl;		\
	std::cout << "Called on Line: " << __LINE__ << std::endl;		\
}
#endif

class Player 										   
{													  
private:
	int m_hours_worked_;
	int m_nutrition;
	int m_energy;
	int m_money;
	int m_refigerator;
public:
	Player();
	void Work(); // player can work
	void PlayerStats(); // player can check there m_money and stats
	void PlayerJob(); // players stats can be effected buy job
	void PlayerEat(); // player can eat
	void PlayerSleep(); // player can sleep
	void PlayerBuy(); // Player can walk to market and but food
	void SetRefrigerator();
	void SetEnergy();
	void SetNutrition();
	void SetMoney();
};
