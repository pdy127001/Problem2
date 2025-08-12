#include "Warrior.h"
#include "player.h"
#include "Monster.h"
#include<iostream>
using namespace std;
void Warrior::attack() {
	cout << "전사 " << getNickname() << "이(가) 일반 공격을 합니다!" << std::endl;
}
void Warrior::attack(Monster* monster) {
	std::cout << "전사 " << getNickname() << "이(가) " << monster->getName() << "에게 일반 공격을 합니다!" << std::endl;
}
Warrior::Warrior(string nickname) : Player(nickname) {
	job_name = "전사";
}

