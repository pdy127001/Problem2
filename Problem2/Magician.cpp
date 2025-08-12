#include "Magician.h"
#include "Monster.h"
#include <iostream>
using namespace std;
Magician::Magician(string nickname) : Player(nickname) {
	job_name = "������";
	
}
void Magician::attack() {
	cout << "������ " << getNickname() << "��(��) �Ϲ� ������ �մϴ�!" << endl;
}
void Magician::attack(Monster* monster) {
	cout << "������ " << getNickname() << "��(��) " << monster->getName() << "���� �Ϲ� ������ �մϴ�!" << endl;
}
