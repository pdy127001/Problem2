#include "Archer.h"
#include "Monster.h"
#include <iostream>
using namespace std;
Archer::Archer(string nickname) : Player(nickname) {
	job_name = "�ü�";
}
void Archer::attack() {
	cout << "�ü� " << getNickname() << "��(��) �Ϲ� ������ �մϴ�!" << endl;
}
void Archer::attack(Monster* monster) {
	cout << "�ü� " << getNickname() << "��(��) " << monster->getName() << "���� �Ϲ� ������ �մϴ�!" << endl;
}
