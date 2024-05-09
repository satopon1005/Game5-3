#pragma once
#include"../Player/Player.h"
// 敵のクラス

class Enemy {
public:
    int x, y; // 敵の位置
    int speed; // 敵の速度

    Enemy(int posX, int posY, int spd);
    void MoveTowardsPlayer(int playerX, int playerY);
    void Draw();
};

// 敵のオブジェクトを初期化
//const int enemyCount = 5;
//Enemy enemies[enemyCount] = {
//	Enemy(100, 100, 1),
//	Enemy(200, 100, 1),
//	Enemy(500, 200, 1),
//	Enemy(1500, 700, 1),
//	Enemy(2000, 1000, 1)
//};
//

