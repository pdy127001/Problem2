#include "Archer.h"
#include "Monster.h"
#include <iostream>
using namespace std;
Archer::Archer(string nickname) : Player(nickname) {
	job_name = "궁수";
}
void Archer::attack() {
	cout << "궁수 " << getNickname() << "이(가) 일반 공격을 합니다!" << endl;
}
void Archer::attack(Monster* monster) {
	cout << "궁수 " << getNickname() << "이(가) " << monster->getName() << "에게 일반 공격을 합니다!" << endl;
}
