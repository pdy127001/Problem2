#include <iostream>
#include "player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
using namespace std;

// ���� �Լ�
int main() {
    string jobs[] = { "����", "������", "����", "�ü�" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;

    cout << "* �г����� �Է����ּ���: ";
    cin >> nickname;

    cout << "<���� �ý���>" << endl;
    cout << nickname << "��, ȯ���մϴ�!" << endl;
    cout << "* ���Ͻô� ������ �������ּ���." << endl;
    do {
        for (int i = 0; i < 4; i++) {
            cout << (i + 1) << ". " << jobs[i] << endl;
        }

        cout << "����: ";
        cin >> job_choice;

        switch (job_choice) {
        case 1:
            player = new Warrior(nickname);
            break;
        case 2:
            player = new Magician(nickname);
            break;
        case 3:
            player = new Thief(nickname);
            break;
        case 4:
            player = new Archer(nickname);
            break;
        default:
            cout << "�߸��� �Է��Դϴ�." << endl;
        }
	} while (job_choice < 1 || job_choice > 4);
    

    player->attack();
    player->printPlayerStatus();

    delete player;

    return 0;
}