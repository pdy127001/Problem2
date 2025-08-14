#include "Magician.h"
#include "Monster.h"
#include <iostream>
using namespace std;
Magician::Magician(string nickname) : Player(nickname) {
	job_name = "������";
	setNickname(nickname);
	level = 1;
	setHP(100);
	setMP(100);
	setPower(30);
	setDefence(5);
	setAccuracy(30);
	setSpeed(15);
}
void Magician::attack() {
	cout << "������ " << getNickname() << "��(��) �Ϲ� ������ �׽�Ʈ�մϴ�." << endl;
	cout << "��... �� �۵��ϴ±���\n" << endl;
}
void Magician::attack(Monster* monster) {
	cout << "������ " << getNickname() << "��(��) " << monster->getName() << "���� ������ �մϴ�!\n" << endl;
	int damage = this->getPower() - monster->getDefence();
	int hitter = 1;
	damage = damage / hitter;//Ÿ�� ����(Ÿ�������ϸ� ��������̱⿡ 1Ÿ���� ���ط��� ������ �� ����) 
	if (damage <= 0) damage = 1; // ������ ���ݷº��� ũ�ų� ���ٸ� ���� 1
	int r = rand() % 100+1;
	if (r <= this->getAccuracy()) {//ũ��Ƽ��(Ÿ�� ���� ���� �ϳ� �Ŀ� �ϳĿ� ���� Ư�� ��Ȳ������ ���ط��� �ٸ�)
		damage *= 2;
		cout << "ũ��Ƽ�� ������ �����߽��ϴ�!" << endl;
	}
	for (int i = 0; i < hitter; i++) {
		cout << monster->getName() << "���� " << damage << "�� ���ظ� �������ϴ�." << endl;
	}
	if (monster->setHP(monster->getHP() - damage * hitter)) {
		cout << "\n���� " << monster->getName() << "�� ���� HP��" << monster->getHP() << "�Դϴ�." << endl;
	}
	else {
		cout << "\n���� " << monster->getName() << "�� ���� HP��" << monster->getHP() << endl;
		cout << "���� " << monster->getName() << "��(��) ���������ϴ�!" << endl;
	}
	return;//��� ���⼭ monster->setHP�� false�� ��ȯ�ϸ� ������ �������� �����ϰ� �;�����, ���� ���� �ڵ忡�� void�� �Ǿ� �־ �״�� ������
}
