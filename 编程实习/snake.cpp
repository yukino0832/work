#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include <ctime>

#define MAXN 20

struct node{
	int body[MAXN * MAXN][2];
	int dir;
	int teil;
};

int land[MAXN][MAXN];
int x, y;
int direct[4][4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //下上右左 
bool flag, gameover;
node snake;

HANDLE handle;
COORD coord;
CONSOLE_CURSOR_INFO cci;

void debug();
void snake_move();
void print();
void put_food();

int main()
{
	RESTART:
	debug();
	while(1)
	{
		put_food();
		snake_move();
		print();
		if(gameover)
			break;
		Sleep(10);
	}
	
	printf("\n重来？(Y/N)\n");
	char re;
	re = getchar();
	if(re == 'Y' || re == 'y')
	{
		system("cls");
		goto RESTART;
	}
	
	getchar(); getchar();
	return 0;
} 
void debug()
{
	memset(land, 0, sizeof(land));
	snake.body[0][0] = MAXN / 2; snake.body[0][1] = MAXN / 2;
	snake.body[1][0] = MAXN / 2 - 1; snake.body[1][1] = MAXN / 2;
	snake.body[2][0] = MAXN / 2 - 2; snake.body[2][1] = MAXN / 2;
	snake.dir = 0; snake.teil = 2;
	
	handle=GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X=0;
	coord.Y=0;
	SetConsoleCursorPosition(handle,coord);
	
	srand(time(NULL));
	
	for(int i = 0; i <= snake.teil; i++)
		land[snake.body[i][0]][snake.body[i][1]] = 1;
	gameover = false; flag = false;
} 
void snake_move()
{
	int ch;
	if(_kbhit())
	{
		ch = _getch();
		switch(ch)
		{
			case 'w': if(snake.dir != 0) snake.dir = 1; break;
			case 's': if(snake.dir != 1) snake.dir = 0; break;
			case 'a': if(snake.dir != 2) snake.dir = 3; break;
			case 'd': if(snake.dir != 3) snake.dir = 2; break;
		}
	}
	
	int crr_x, crr_y;
	crr_x = snake.body[0][0] + direct[snake.dir][0];
	crr_y = snake.body[0][1] + direct[snake.dir][1];
	if(crr_x < 0 || crr_x >= MAXN || crr_y < 0 || crr_y >= MAXN ||
		land[crr_x][crr_y] == 1)  //撞边界或自己 
	{
		gameover = true;
		return;
	}
	if(land[crr_x][crr_y] == 2)  //吃到食物 
	{
		snake.teil++;
		flag = false;
		land[crr_x][crr_y] = 0;
	}
	
	land[snake.body[snake.teil][0]][snake.body[snake.teil][1]] = 0;  //移动 
	for(int i = snake.teil; i > 0; i--)
	{
		snake.body[i][0] = snake.body[i - 1][0];
		snake.body[i][1] = snake.body[i - 1][1];
	}
	snake.body[0][0] = crr_x; snake.body[0][1] = crr_y;
	land[snake.body[0][0]][snake.body[0][1]] = 1;
}
void print()
{
	SetConsoleCursorPosition(handle,coord);
   	cci.bVisible = 0;
  	cci.dwSize = 1;
	SetConsoleCursorInfo(handle, &cci);
	
	for(int i = 0; i <= MAXN + 1; i++)
		printf("■");
	printf("\n");
	for(int i = 0; i < MAXN; i++)
	{
		printf("■");
		for(int j = 0; j < MAXN; j++)
		{
			if(land[i][j] == 1)	 printf("■");
			else if(land[i][j] == 2)  printf("□") ;
			else printf("  ");
		}
		printf("■\n" );
	}
	for(int i = 0; i <= MAXN + 1; i++)
		printf("■");
}
void put_food()
{
	if(flag)
		return;
	x = rand() % MAXN;
	y = rand() % MAXN;
	if(land[x][y] == 1)	put_food();
	else land[x][y] = 2;
	flag = true;
}
