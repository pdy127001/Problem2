#include <iostream>
#include "player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
using namespace std;

// 메인 함수
int main() {
    string jobs[] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0;
    string nickname;
	bool game_end = false;
    Player* player = nullptr;
    int act;
    int clear = 0;
    bool monster_live = true;

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    cout << "\n\n<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
    cout << "* 원하시는 직업을 선택해주세요." << endl;
    do {
        for (int i = 0; i < 4; i++) {
            cout << (i + 1) << ". " << jobs[i] << endl;
        }

        cout << "\n선택: ";
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
            cout << "잘못된 입력입니다." << endl;
        }
        player->printPlayerStatus();
	} while (job_choice < 1 || job_choice > 4);
    Monster* monster[5];
	monster[0] = new Monster("슬라임");
	monster[1] = new Monster("고블린");
	monster[2] = new Monster("오크");
	monster[3] = new Monster("드래곤");
	monster[4] = new Monster("마왕");
    for(int i = 0; i < 5&&!game_end; i++) {
        cout << endl<<i+1<<"번째 몬스터를 소환합니다" << endl;
        cout << "몬스터 " << monster[i]->getName() << "이(가) 생성되었습니다.\n" << endl;
        monster_live = true; // 다음 몬스터를 위해 초기화
        while (!game_end && monster_live)
        {
            player->printPlayerStatus();
            cout << "\n행동\n" <<
                "1 : 공격 테스트하기(포켓몬 잉어킹 튀어오르기와 같습니다)\n" <<
                "2 : 몬스터에게 공격하기(스피드에 따라 공격 순서가 결정, 플레이어 공격력-몬스터 방어력이 피해량, 크리티컬 공격은 100-정확도 확률로 성공, 크리티컬시 200%피해)\n" <<
                "3 : 휴식하기(HP,MP 각 15씩 회복)\n" <<
                "4 : 게임 종료하기\n\n" <<
                "원하는 행동을 선택해주세요: ";
            cin >> act;
            if (player->getSpeed() >= monster[i]->getSpeed()) {//캐릭터 선제공격시
                switch (act) {
                case 1:
                    player->attack();
                    monster[i]->attack(player);
                    break;
                case 2:
                    player->attack(monster[i]);
                    if (monster[i]->getHP() == 0) {//몬스터가 죽었는지 판독
                        monster_live = false;
                    }
                    else {
                        monster[i]->attack(player);
                    }
                    break;
                case 3:
                    player->setHP(player->getHP() + 15);
                    player->setMP(player->getMP() + 15);
                    cout << "플레이어의 HP과 MP를 각 15씩 회복합니다!" << endl;
                    monster[i]->attack(player);
                    break;
                case 4:
                    game_end = true;
                    break;
                default:
                    cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
                }
                if (player->getHP() <= 0) {//플레이어가 죽었는지 판독
                    game_end = true;
                }
            }
            else {//몬스터가 선제공격시
                switch (act) {
                case 1:
                    monster[i]->attack(player);
                    if (player->getHP() <= 0) {//플레이어가 죽었는지 판독
                        game_end = true;
                        break;
                    }
                    player->attack();
                    break;
                case 2:
                    monster[i]->attack(player);
                    if (player->getHP() <= 0) {//플레이어가 죽었는지 판독
                        game_end = true;
                        break;
                    }
                    player->attack(monster[i]);
                    break;
                case 3:
                    monster[i]->attack(player);
                    if (player->getHP() <= 0) {//플레이어가 죽었는지 판독
                        game_end = true;
                        break;
                    }
                    player->setHP(player->getHP() + 15);
                    player->setMP(player->getMP() + 15);
                    cout << "플레이어의 HP과 MP를 각 15씩 회복합니다!" << endl;
                    break;
                case 4:
                    game_end = true;
                    break;
                default:
                    cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
                }
                if (monster[i]->getHP() <= 0) {//몬스터가 죽었는지 판독(attack함수가 bool이라면 구현하지 않아도됨)
                    monster_live = false;
                }
            }
        }
	}
	cout << "게임을 종료합니다." << endl;
    delete player;

    return 0;
}