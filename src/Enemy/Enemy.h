#pragma once
#include"../Player/Player.h"
// �G�̃N���X

class Enemy {
public:
    int x, y; // �G�̈ʒu
    int speed; // �G�̑��x

    Enemy(int posX, int posY, int spd);
    void MoveTowardsPlayer(int playerX, int playerY);
    void Draw();
};

// �G�̃I�u�W�F�N�g��������
//const int enemyCount = 5;
//Enemy enemies[enemyCount] = {
//	Enemy(100, 100, 1),
//	Enemy(200, 100, 1),
//	Enemy(500, 200, 1),
//	Enemy(1500, 700, 1),
//	Enemy(2000, 1000, 1)
//};
//

