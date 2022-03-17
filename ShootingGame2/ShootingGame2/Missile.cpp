#include "Missile.h"
#include "Console.h"

#include <iostream>

using namespace std;

void Missile::setMissile(int _x, int _y,MissileType _missileType)
{
	x = _x;
	y = _y;
	missileType = _missileType;
}

void Missile::drawMissile()
{
	switch (missileType)
	{
	case MissileType::Player:
		gotoXY(x, y);
		setTextColor(2);
		cout << "¡Ü";
		setTextColor(15);
		y--;
		break;
	case MissileType::Enemy:
		gotoXY(x, y);
		setTextColor(3);
		cout << "¡Ü";
		setTextColor(15);
		y += 2;
		break;
	default:
		break;
	}
}

bool Missile::checkEnd()
{
	switch (missileType)
	{
	case MissileType::Player:
		if (y < 0)
		{
			return true;
		}
		break;
	case MissileType::Enemy:
		if (y > 38)
		{
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}

bool Missile::checkCollision(int _x, int _y)
{
	switch (missileType)
	{
	case MissileType::Player:
		if (x == _x && (y == _y || y + 1 == _y))
		{
			return true;
		}
		break;
	case MissileType::Enemy:
		if (x == _x && (y == _y || y + 1 == _y || y -1 == _y))
		{
			return true;
		}
		break;
	default:
		break;
	}

	return false;
}

int Missile::getX()
{
	return x;
}

int Missile::getY()
{
	return y;
}
