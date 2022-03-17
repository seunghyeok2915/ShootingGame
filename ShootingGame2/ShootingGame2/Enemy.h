#pragma once

class Enemy
{
private:
	int x;
	int y;

public:
	void setEnemy();
	void drawEnemy();
	bool shootEnemy();
	bool checkEnd();

	int getX();
	int getY();
};