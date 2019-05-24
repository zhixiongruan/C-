/*打字游戏*/

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define KLETTER_COUNT 10
#define KSPEED 1000

//设计子弹，设计字母
typedef struct tag_letter
{
	//ASCII
	char ch;
	//位置
	int x;
	int y;
	//是否显示：0 不显示 1 显示
	int isDisplay;
	//生命：0 死亡 1 生存
	int life;
}Letter;

Letter letters[KLETTER_COUNT];
Letter bullet;




//定位屏幕位置
void gotoxy(int x, int y);
//游戏角色初始化
void initLetters();
//子弹初始化
void initBullet(int x);
//绘制字母
void drawLetter(char ch, int x, int y);
//用来判断所有字母是否应该显示
void judgeLetterDisplay();
//让所有字母下降
void letterMoving();
//子弹运行
void bulletMoving();

int main(void)
{
	initLetters();
	while (letters[KLETTER_COUNT - 1].y < 25)
	{
		letterMoving();
		Sleep(KSPEED);
	}
	system("pause");
	return 0;
}

void gotoxy(int x, int y)
{
	//句柄
	HANDLE handle;
	//坐标
	COORD coord;

	coord.X = x;
	coord.Y = y;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(handle, coord);
}

void initLetters()
{
	int i = 0;
	srand((unsigned)time(NULL));
	for (i = 0; i < KLETTER_COUNT; i++)
	{
		letters[i].ch = rand() % 26 + 'A';
		letters[i].x = rand() % 80;
		letters[i].y = -2 * i;
		letters[i].life = 1;
	}
}

void initBullet(int x)
{
	bullet.ch = 30;
	bullet.x = x;
	bullet.y = 25;
}

void drawLetter(char ch, int x, int y)
{
	gotoxy(x, y);
	printf("%c", ch);
}

void judgeLetterDisplay()
{
	int i = 0;
	for (i = 0; i < KLETTER_COUNT; i++)
	{
		if (0 == letters[i].life)
		{
			letters[i].isDisplay = 0;
		}
		else
		{
			if (letters[i].y < 0 || letters[i].y > 24)
			{
				letters[i].isDisplay = 0;
			}
			else
			{
				letters[i].isDisplay = 1;
			}
		}
	}
}

void letterMoving()
{
	int i = 0;
	judgeLetterDisplay();
	for (i = 0; i < KLETTER_COUNT; i++)
	{
		if (letters[i].y < 25)
		{
			if (letters[i].isDisplay == 1)
			{
				drawLetter(' ', letters[i].x, letters[i].y);
				drawLetter(letters[i].ch, letters[i].x, letters[i].y + 1);
			}
			else
			{
				drawLetter(' ', letters[i].x, letters[i].y);
			}
			letters[i].y++;
		}
		else
		{
			drawLetter(' ', letters[i].x, letters[i].y);
		}
	}
}

void bulletMoving()
{
	if (bullet.life == 1)
	{
		drawLetter(' ', bullet.x, bullet.y);
		drawLetter(bullet.ch, bullet.x, bullet.y - 1);
	}
	bullet.y--;
}