#include "Thief.h"
#include "Monster.h"
#include <iostream>
using namespace std;
Thief::Thief(string nickname) : Player(nickname) {
	job_name = "����";
	
}
void Thief::attack() {
	cout << "���� " << getNickname() << "��(��) �Ϲ� ������ �մϴ�!" << endl;
}
void Thief::attack(Monster* monster) {
	cout << "���� " << getNickname() << "��(��) " << monster->getName() << "���� �Ϲ� ������ �մϴ�!" << endl;
}
