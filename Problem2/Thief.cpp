#include "Thief.h"
#include "Monster.h"
#include <iostream>
using namespace std;
Thief::Thief(string nickname) : Player(nickname) {
	job_name = "도적";
	
}
void Thief::attack() {
	cout << "도적 " << getNickname() << "이(가) 일반 공격을 합니다!" << endl;
}
void Thief::attack(Monster* monster) {
	cout << "도적 " << getNickname() << "이(가) " << monster->getName() << "에게 일반 공격을 합니다!" << endl;
}
