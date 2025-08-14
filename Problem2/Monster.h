#pragma once
#include <string>
#include "player.h"
using namespace std;
class Monster
{
public:
	Monster(string name);
	void attack(Player* player);//bool로 구현해서 싸움이 끝났는지 확인할 수 있도록 구현하고 싶었는나, 기존 제공 코드에서 void로 되어 있어서 그대로 유지하고 HP가 0(0이하로 setHP를 호출하게되면 0으로 고정)이 되면 게임이 끝나도록 구현함
	string getName();
	int getHP();
	int getPower();
	int getDefence();
	int getSpeed();
	void setName(string name);
	bool setHP(int HP);
	void setPower(int power);
	void setDefence(int defence);
	void setSpeed(int speed);
protected:
	string name; 
	int HP; 
	int power; 
	int defence; 
	int speed; 
};

