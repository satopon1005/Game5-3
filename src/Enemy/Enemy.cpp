#include"DxLib.h"
#include "Enemy.h"

Enemy::Enemy(int posX, int posY, int spd) : x(posX), y(posY), speed(spd) {}

void Enemy::MoveTowardsPlayer(int playerX, int playerY) {
    if (x < playerX) x += speed;
    if (x > playerX) x -= speed;
    if (y < playerY) y += speed;
    if (y > playerY) y -= speed;
}

void Enemy::Draw() {
    DrawCircle(x, y, 10, GetColor(0, 255, 0), TRUE);
}
