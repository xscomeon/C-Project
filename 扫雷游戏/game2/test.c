#define _CRT_SECURE_NO_WARNINGS 1 

#include "game.h"	





void game()
{
	//printf("sao lei\n");  //for test
	//雷的信息存储
	//排查雷的信息
	char mine[ROWS][COLS] = { 0 }; //11*11
	char show[ROWS][COLS] = { 0 };

	//初始化
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);//9*9
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//扫雷
	FindMine(mine,show, ROW, COL);   //mine数组里查找，结果在show数组里显示

}

void menu()
{
	printf("**********************\n");
	printf("******  1.play  ******\n");
	printf("******  0.exit  ******\n");
	printf("**********************\n");
}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	//menu();
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏.\n");
			break;
		default:
			printf("输入错误，请重新输入.\n");
			break;
		}
	} while (input);

}



int main()
{

	test();
	return 0;
}