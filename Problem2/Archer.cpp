#include "Archer.h"
#include "Monster.h"
#include <iostream>
using namespace std;
Archer::Archer(string nickname) : Player(nickname) {
	job_name = "궁수";
	setNickname(nickname);
	level = 1;
	setHP(100);
	setMP(50);
	setPower(30);
	setDefence(5);
	setAccuracy(50);
	setSpeed(20);
}
void Archer::attack() {
	cout << "궁수 " << getNickname() << "이(가) 일반 공격을 테스트합니다." << endl;
	cout << "음... 잘 작동하는군요\n" << endl;
}
void Archer::attack(Monster* monster) {
	cout << "궁수 " << getNickname() << "이(가) " << monster->getName() << "에게 공격을 합니다!\n" << endl;
	int damage = this->getPower() - monster->getDefence();
	int hitter = 3;
	damage = damage / hitter;//타수 분할(타수분할하면 버림계산이기에 1타보다 피해량이 적어질 수 있음) 
	if (damage <= 0) damage = 1; // 방어력이 공격력보다 크거나 같다면 피해 1
	int r = rand() % 100 + 1;
	if (r <= this->getAccuracy()) {//크리티컬(타수 분할 전에 하냐 후에 하냐에 따라 특정 상황에서는 피해량이 다름)
		damage *= 2;
		cout << "크리티컬 공격이 성공했습니다!" << endl;
	}
	for (int i = 0; i < hitter; i++) {
		cout << monster->getName() << "에게 " << damage << "의 피해를 입혔습니다." << endl;
	}
	if (monster->setHP(monster->getHP() - damage * hitter)) {
		cout << "\n몬스터 " << monster->getName() << "의 남은 HP는" << monster->getHP() << "입니다." << endl;
	}
	else {
		cout << "\n몬스터 " << monster->getName() << "의 남은 HP는" << monster->getHP() << endl;
		cout << "몬스터 " << monster->getName() << "이(가) 쓰러졌습니다!" << endl;
	}
	return;//사실 여기서 monster->setHP가 false를 반환하면 게임이 끝나도록 구현하고 싶었으나, 기존 제공 코드에서 void로 되어 있어서 그대로 유지함
}
	
