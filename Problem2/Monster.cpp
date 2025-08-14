#include "Monster.h"
#include <iostream>
#include "player.h"
using namespace std;
Monster::Monster(string name) {
	setName(name);
	setHP(10); 
	setPower(30);
	setDefence(10);
	setSpeed(10);
}
void Monster::attack(Player* player) {
	cout << "몬스터 " << getName() << "이(가) " << player->getNickname() << "에게 공격을 합니다!\n" << endl;
	int damage = this->getPower() - player->getDefence();
	int hitter = 1;
	bool monster_live;
	damage = damage / hitter;//타수 분할(타수분할하면 버림계산이기에 1타보다 피해량이 적어질 수 있음) 
	if (damage <= 0) damage = 1; // 방어력이 공격력보다 크거나 같다면 피해 1
	for (int i = 0; i < hitter; i++) {
		cout << player->getNickname() << "에게 " << damage << "의 피해를 입혔습니다." << endl;
	}
	if (player->setHP(player->getHP() - damage * hitter)) {
		cout << "\n플레이어 " << player->getNickname() << "의 남은 HP는" << player->getHP() << "입니다." << endl;
	}
	else {
		cout << "\n플레이어 " << player->getNickname() << "의 남은 HP는" << player->getHP() << endl;
		cout << "플레이어 " << player->getNickname() << "이(가) 쓰러졌습니다!" << endl;
	}
	return;//사실 여기서 player->setHP가 false를 반환하면 게임이 끝나도록 구현하고 싶었으나, 기존 제공 코드에서 void로 되어 있어서 그대로 유지함
}
void Monster::setName(string name) {
	this->name = name;
}
string Monster::getName() {
	return name;
}
int Monster::getHP() {
	return HP;
}
int Monster::getPower() {
	return power;
}
int Monster::getDefence() {
	return defence;
}
int Monster::getSpeed() {
	return speed;
}
bool Monster::setHP(int HP) {
	if (HP <= 0) {
		this->HP = 0;
		return false;
	}
	this->HP = HP;
	return true;
}
void Monster::setPower(int power) {
	this->power = power;
}
void Monster::setDefence(int defence) {
	this->defence = defence;
}
void Monster::setSpeed(int speed) {
	this->speed = speed;
}