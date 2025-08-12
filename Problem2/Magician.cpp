#include "Magician.h"
#include "Monster.h"
#include <iostream>
using namespace std;
Magician::Magician(string nickname) : Player(nickname) {
	job_name = "마법사";
	
}
void Magician::attack() {
	cout << "마법사 " << getNickname() << "이(가) 일반 공격을 합니다!" << endl;
}
void Magician::attack(Monster* monster) {
	cout << "마법사 " << getNickname() << "이(가) " << monster->getName() << "에게 일반 공격을 합니다!" << endl;
}
