#include <iostream>
#include "player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
using namespace std;

// ���� �Լ�
int main() {
    string jobs[] = { "����", "������", "����", "�ü�" };
    int job_choice = 0;
    string nickname;
	bool game_end = false;
    Player* player = nullptr;
    int act;
    int clear = 0;
    bool monster_live = true;

    cout << "* �г����� �Է����ּ���: ";
    cin >> nickname;

    cout << "\n\n<���� �ý���>" << endl;
    cout << nickname << "��, ȯ���մϴ�!" << endl;
    cout << "* ���Ͻô� ������ �������ּ���." << endl;
    do {
        for (int i = 0; i < 4; i++) {
            cout << (i + 1) << ". " << jobs[i] << endl;
        }

        cout << "\n����: ";
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
        player->printPlayerStatus();
	} while (job_choice < 1 || job_choice > 4);
    Monster* monster[5];
	monster[0] = new Monster("������");
	monster[1] = new Monster("���");
	monster[2] = new Monster("��ũ");
	monster[3] = new Monster("�巡��");
	monster[4] = new Monster("����");
    for(int i = 0; i < 5&&!game_end; i++) {
        cout << endl<<i+1<<"��° ���͸� ��ȯ�մϴ�" << endl;
        cout << "���� " << monster[i]->getName() << "��(��) �����Ǿ����ϴ�.\n" << endl;
        monster_live = true; // ���� ���͸� ���� �ʱ�ȭ
        while (!game_end && monster_live)
        {
            player->printPlayerStatus();
            cout << "\n�ൿ\n" <<
                "1 : ���� �׽�Ʈ�ϱ�(���ϸ� �׾�ŷ Ƣ�������� �����ϴ�)\n" <<
                "2 : ���Ϳ��� �����ϱ�(���ǵ忡 ���� ���� ������ ����, �÷��̾� ���ݷ�-���� ������ ���ط�, ũ��Ƽ�� ������ 100-��Ȯ�� Ȯ���� ����, ũ��Ƽ�ý� 200%����)\n" <<
                "3 : �޽��ϱ�(HP,MP �� 15�� ȸ��)\n" <<
                "4 : ���� �����ϱ�\n\n" <<
                "���ϴ� �ൿ�� �������ּ���: ";
            cin >> act;
            if (player->getSpeed() >= monster[i]->getSpeed()) {//ĳ���� �������ݽ�
                switch (act) {
                case 1:
                    player->attack();
                    monster[i]->attack(player);
                    break;
                case 2:
                    player->attack(monster[i]);
                    if (monster[i]->getHP() == 0) {//���Ͱ� �׾����� �ǵ�
                        monster_live = false;
                    }
                    else {
                        monster[i]->attack(player);
                    }
                    break;
                case 3:
                    player->setHP(player->getHP() + 15);
                    player->setMP(player->getMP() + 15);
                    cout << "�÷��̾��� HP�� MP�� �� 15�� ȸ���մϴ�!" << endl;
                    monster[i]->attack(player);
                    break;
                case 4:
                    game_end = true;
                    break;
                default:
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �õ����ּ���." << endl;
                }
                if (player->getHP() <= 0) {//�÷��̾ �׾����� �ǵ�
                    game_end = true;
                }
            }
            else {//���Ͱ� �������ݽ�
                switch (act) {
                case 1:
                    monster[i]->attack(player);
                    if (player->getHP() <= 0) {//�÷��̾ �׾����� �ǵ�
                        game_end = true;
                        break;
                    }
                    player->attack();
                    break;
                case 2:
                    monster[i]->attack(player);
                    if (player->getHP() <= 0) {//�÷��̾ �׾����� �ǵ�
                        game_end = true;
                        break;
                    }
                    player->attack(monster[i]);
                    break;
                case 3:
                    monster[i]->attack(player);
                    if (player->getHP() <= 0) {//�÷��̾ �׾����� �ǵ�
                        game_end = true;
                        break;
                    }
                    player->setHP(player->getHP() + 15);
                    player->setMP(player->getMP() + 15);
                    cout << "�÷��̾��� HP�� MP�� �� 15�� ȸ���մϴ�!" << endl;
                    break;
                case 4:
                    game_end = true;
                    break;
                default:
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �õ����ּ���." << endl;
                }
                if (monster[i]->getHP() <= 0) {//���Ͱ� �׾����� �ǵ�(attack�Լ��� bool�̶�� �������� �ʾƵ���)
                    monster_live = false;
                }
            }
        }
	}
	cout << "������ �����մϴ�." << endl;
    delete player;

    return 0;
}