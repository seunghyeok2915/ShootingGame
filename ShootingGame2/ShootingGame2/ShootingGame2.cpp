#include <iostream>
#include <time.h>
#include <vector>

#include "Enemy.h"
#include "Missile.h"
#include "Console.h"

#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

using namespace std;

int x, y, missileCount;

vector<Enemy> enemies;
vector<Missile> myMissile;
vector<Missile> enemyMissiles;

void initData()
{
	srand((unsigned)time(NULL));

	x = 10;
	y = 38;

	missileCount = 0;

	enemies.clear();
	myMissile.clear();

}

void checkDirection()
{
	int key = _getch();

	switch (key)
	{
	case UP:
		if (y > 0)
		{
			y--;
		}
		break;

	case DOWN:
		if (y < 38)
		{
			y++;
		}
		break;

	case LEFT:
		if (x > 0)
		{
			x--;
		}
		break;

	case RIGHT:
		if (x < 19)
		{
			x++;
		}
		break;

	default:

		break;
	}
}

void checkCollision()
{
	bool bCollision = false;

	do
	{
		bCollision = false;

		for (int i = 0; i < (int)myMissile.size(); i++)
		{
			for (int j = 0; j < (int)enemies.size(); j++)
			{
				if (myMissile[i].checkCollision(enemies[j].getX(), enemies[j].getY()))
				{
					myMissile.erase(myMissile.begin() + i);
					enemies.erase(enemies.begin() + j);

					bCollision = true;
					break;
				}
			}

			if (bCollision)
			{
				break;
			}
		}
	} while (bCollision);
}

void checkCollisionEnemy()
{

	bool bCollision = false;

	do
	{
		bCollision = false;

		for (int i = 0; i < (int)enemyMissiles.size(); i++)
		{
			for (int j = 0; j < (int)myMissile.size(); j++)
			{
				if (enemyMissiles[i].checkCollision(myMissile[j].getX(), myMissile[j].getY()))
				{
					enemyMissiles.erase(enemyMissiles.begin() + i);
					myMissile.erase(myMissile.begin() + j);

					bCollision = true;
					break;
				}
			}

			if (bCollision)
			{
				break;
			}
		}
	} while (bCollision);
}

void drawPlayer()
{
	gotoXY(x, y);

	cout << "▲";
	
	gotoXY(19, 39);
}

int main()
{
    setConsoleView();
	initData();

	while (true)
	{
		int key = getKeyDown();
		key = tolower(key);

		if (key == 0xE0)
		{
			checkDirection();
		}
		else if (key == 'a')
		{
			if (missileCount == 0)
			{
				Missile missile;
				missile.setMissile(x, y, MissileType::Player);
			
				myMissile.push_back(missile);

				missileCount = 3;
			}
		}

		if (rand() % 100 < 10)
		{
			Enemy enemy;
			enemy.setEnemy();

			enemies.push_back(enemy);
		}

		checkCollision();
		checkCollisionEnemy();

		for (int i = 0; i < (int)enemyMissiles.size(); i++)
		{
			if (enemyMissiles[i].checkCollision(x, y))
			{
				cout << "사망";
				exit(0);
			}
		}


		for (int i = 0; i < (int)enemies.size(); i++)
		{
			enemies[i].drawEnemy();
			if(enemies[i].shootEnemy())
			{
				Missile missile;
				missile.setMissile(enemies[i].getX(), enemies[i].getY(), MissileType::Enemy);

				enemyMissiles.push_back(missile);
			}
		}

		for (int i = 0; i < (int)myMissile.size(); i++)
		{
			myMissile[i].drawMissile();
		}

		for (int i = 0; i < (int)enemyMissiles.size(); i++)
		{
			enemyMissiles[i].drawMissile();
		}
	

		drawPlayer();

		for (int i = 0; i < (int)myMissile.size(); i++)
		{
			if (myMissile[i].checkEnd())
			{
				myMissile.erase(myMissile.begin() + i);
				i--;
			}
		}

		for (int i = 0; i < (int)enemyMissiles.size(); i++)
		{
			if (enemyMissiles[i].checkEnd())
			{
				enemyMissiles.erase(enemyMissiles.begin() + i);
				i--;
			}
		}

		for (int i = 0; i < (int)enemies.size(); i++)
		{
			if (enemies[i].checkEnd())
			{
				enemies.erase(enemies.begin() + i);
				i--;
			}
		}

		if (missileCount > 0)
		{
			missileCount--;
		}

		Sleep(100);

		clrscr();
	}
}