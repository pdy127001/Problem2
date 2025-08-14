#pragma once
#include <string>
using namespace std;
class Monster;
class Player {
public:
    Player(string nickname);

	virtual void attack() = 0;
    virtual void attack(Monster* monster) = 0;//bool로 구현해서 싸움이 끝났는지 확인할 수 있도록 구현하고 싶었는나, 기존 제공 코드에서 void로 되어 있어서 그대로 유지하고 HP가 0(0이하로 setHP를 호출하게되면 0으로 고정)이 되면 게임이 끝나도록 구현함
    void printPlayerStatus();

    // getter 함수
    string getJobName();
    string getNickname();
    int getLevel();
    int getHP();
    int getMP();
    int getPower();
    int getDefence();
    int getAccuracy();
    int getSpeed();

    // setter 함수
    void setNickname(string nickname);
    bool setHP(int HP);
    bool setMP(int MP);
    void setPower(int power);
    void setDefence(int defence);
    void setAccuracy(int accuracy);
    void setSpeed(int speed);

protected:
    string job_name;
    string nickname;
    int level;
    int HP;
    int MP;
    int power;
    int defence;
    int accuracy;//정확도를 어떻게 써야할지 몰라서 정확도에따라 100-accuracy확률로 크리티컬 공격이 성공하는 것으로 구현
    int speed;
};