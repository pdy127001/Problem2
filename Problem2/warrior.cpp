#include "Warrior.h"
#include "player.h"
#include "Monster.h"
#include<iostream>
using namespace std;
void Warrior::attack() {
	cout << "���� " << getNickname() << "��(��) �Ϲ� ������ �մϴ�!" << std::endl;
}
void Warrior::attack(Monster* monster) {
	std::cout << "���� " << getNickname() << "��(��) " << monster->getName() << "���� �Ϲ� ������ �մϴ�!" << std::endl;
}
Warrior::Warrior(string nickname) : Player(nickname) {
	job_name = "����";
}

