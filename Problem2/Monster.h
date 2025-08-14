#pragma once
#include <string>
#include "player.h"
using namespace std;
class Monster
{
public:
	Monster(string name);
	void attack(Player* player);//bool�� �����ؼ� �ο��� �������� Ȯ���� �� �ֵ��� �����ϰ� �;��³�, ���� ���� �ڵ忡�� void�� �Ǿ� �־ �״�� �����ϰ� HP�� 0(0���Ϸ� setHP�� ȣ���ϰԵǸ� 0���� ����)�� �Ǹ� ������ �������� ������
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

