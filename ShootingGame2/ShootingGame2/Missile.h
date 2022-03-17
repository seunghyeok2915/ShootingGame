#pragma once

enum class MissileType
{
	Player,
	Enemy
};

class Missile
{
private:
	int x;
	int y;
	MissileType missileType;


public:
	void setMissile(int _x, int _y,MissileType missileType);
	void drawMissile();
	bool checkEnd();

	bool checkCollision(int _x,int _y);
	int getX();
	int getY();
};