#include "Enemy.h"
#include "Console.h"
#include <iostream>
using namespace std;

void Enemy::setEnemy()
{
	x = rand() % 20;
	y = 0;
}

void Enemy::drawEnemy()
{
	gotoXY(x, y);

	setTextColor(4);
	cout << "��";
	setTextColor(15);

	y++;
}

bool Enemy::shootEnemy()
{
	if (rand() % 100 < 3)
	{
		return true;
	}
	return false;
}

bool Enemy::checkEnd()
{
	if (y > 39)
	{
		return true;
	}
	return false;
}

int Enemy::getX()
{
	return x;
}

int Enemy::getY()
{
	return y;
}
