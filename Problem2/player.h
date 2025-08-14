#pragma once
#include <string>
using namespace std;
class Monster;
class Player {
public:
    Player(string nickname);

	virtual void attack() = 0;
    virtual void attack(Monster* monster) = 0;//bool�� �����ؼ� �ο��� �������� Ȯ���� �� �ֵ��� �����ϰ� �;��³�, ���� ���� �ڵ忡�� void�� �Ǿ� �־ �״�� �����ϰ� HP�� 0(0���Ϸ� setHP�� ȣ���ϰԵǸ� 0���� ����)�� �Ǹ� ������ �������� ������
    void printPlayerStatus();

    // getter �Լ�
    string getJobName();
    string getNickname();
    int getLevel();
    int getHP();
    int getMP();
    int getPower();
    int getDefence();
    int getAccuracy();
    int getSpeed();

    // setter �Լ�
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
    int accuracy;//��Ȯ���� ��� ������� ���� ��Ȯ�������� 100-accuracyȮ���� ũ��Ƽ�� ������ �����ϴ� ������ ����
    int speed;
};