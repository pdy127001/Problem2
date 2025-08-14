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
	cout << "���� " << getName() << "��(��) " << player->getNickname() << "���� ������ �մϴ�!\n" << endl;
	int damage = this->getPower() - player->getDefence();
	int hitter = 1;
	bool monster_live;
	damage = damage / hitter;//Ÿ�� ����(Ÿ�������ϸ� ��������̱⿡ 1Ÿ���� ���ط��� ������ �� ����) 
	if (damage <= 0) damage = 1; // ������ ���ݷº��� ũ�ų� ���ٸ� ���� 1
	for (int i = 0; i < hitter; i++) {
		cout << player->getNickname() << "���� " << damage << "�� ���ظ� �������ϴ�." << endl;
	}
	if (player->setHP(player->getHP() - damage * hitter)) {
		cout << "\n�÷��̾� " << player->getNickname() << "�� ���� HP��" << player->getHP() << "�Դϴ�." << endl;
	}
	else {
		cout << "\n�÷��̾� " << player->getNickname() << "�� ���� HP��" << player->getHP() << endl;
		cout << "�÷��̾� " << player->getNickname() << "��(��) ���������ϴ�!" << endl;
	}
	return;//��� ���⼭ player->setHP�� false�� ��ȯ�ϸ� ������ �������� �����ϰ� �;�����, ���� ���� �ڵ忡�� void�� �Ǿ� �־ �״�� ������
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