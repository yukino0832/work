#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <vector>

const int width = 40;
const int height = 20;
// 20*40

enum move     //move direction
{
	up,down,left,right
};

struct position     //initial positon
{
	int x, y;
};

std::vector<position> snake;
position food;
move dir = right;
// create instance

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// get output API

void init();
void draw();
void Move();
void createfood();
void Gameover();
void hidecursor();
bool is_crack(const position& head);


int main()
{
	std::srand(static_cast<unsigned>(std::time(0)));
	init();

	while (true)
	{
		if (_kbhit()) // 有按键被按下
		{
			switch (_getch())
			{
			case 'w':
				if (dir != down)  // 不能进行反方向移动
					dir = up;
				break;
			case 's':
				if (dir != up)
					dir = down;
				break;
			case 'a':
				if (dir != right)
					dir = left;
				break;
			case 'd':
				if (dir != left)
					dir = right;
				break;
			}
		}
		Move();
		draw();
		Sleep(100); // 速度可调
		if (is_crack(snake[0]))
		{
			Gameover();
			break;
		}
	}

	return 0;
}

void init()  // initialize
{
    system("cls");
	hidecursor();
	snake.clear();
	position initposition = { width / 4, height / 2 };
	snake.push_back(initposition);
	snake.push_back({ initposition.x - 1, initposition.y });
	snake.push_back({ initposition.x - 2, initposition.y });
	// set initial position , length = 3
	
	createfood();
}

void draw()
{
	COORD coord = { 0, 0 };  // 重置光标位置
	SetConsoleCursorPosition(hConsole, coord);
	for (int i = 0; i <= width; i++)
	    std::cout << "#";
	std::cout << std::endl;
	for (int i = 0; i < height; i++) // 初始化界面，不喜欢这个界面可以改
	{
		for (int j = 0; j <= width; j++)
		{
			if (j == 0 || j == width)
				std::cout << "#";
			else if (i == food.y && j == food.x)
				std::cout << "*";
			else
			{
				bool isbody = false;
				for (const auto& part : snake)
				{
					if (part.x == j && part.y == i)
					{
						std::cout << "#";
						isbody = true;
						break;
					}
				}
				if (!isbody)
					std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
	for (int i = 0; i <= width; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
}

void Move()  // move the snake
{
	position head = snake[0];
	switch (dir)
	{
	case up:
		head.y -= 1;
		break;
	case down:
		head.y += 1;
		break;
	case left:
		head.x -= 1;
		break;
	case right:
		head.x += 1;
		break;
	}
	if (head.x == food.x && head.y == food.y) // eat food, get longer
	{
		snake.push_back({ 0, 0 });
		snake.pop_back();
		createfood();
	} else
	{
		snake.pop_back();
	}
	snake.insert(snake.begin(), head);
}

void createfood()
{
	while (true)           // 循环直到食物不与蛇重合
	{
		food.x = std::rand() % (width - 1) + 1;
		food.y = std::rand() % (height - 1) + 1;
		bool if_in_snake = false;
		for (const auto& part : snake)
		{
			if (part.x == food.x && part.y == food.y)
			{
				if_in_snake = true;
				break;
			}
		}
		if (!if_in_snake)
			break;
	}
}

void Gameover()
{
	system("cls");
	std::cout << "菜，就多练" << std::endl;
	std::cout << "Press any key to exit..." << std::endl;
	_getch();
}

void hidecursor()  // 解决光标异常闪动
{
	CONSOLE_CURSOR_INFO cursorinfo;
	cursorinfo.bVisible = false;
	cursorinfo.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &cursorinfo);
}

bool is_crack(const position& head) // 碰到边界或自己就结束
{
	if (head.x <= 0 || head.x >= width || head.y <= 0 || head.y >= height)
		return true;
	for (size_t i = 1; i < snake.size(); i++)
	{
		if (snake[i].x == head.x && snake[i].y == head.y)
			return true;
	}
	return false;
}
