#define _CRT_SECURE_NO_WARNINGS 1  
#include "game.h"




void InitBoard(char board[ROWS][COLS], int rows, int cols,char c)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = c;
		}
	}

}


void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{	
		printf("%d ", i); //打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

}


void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASYCOUNT;
	while (count)
	{
		int x = rand() % row + 1;  //1-9
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}


int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//方法1，遍历比较，count++
	//方法2
	int i = 0;
	int j = 0;
	int ret = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			ret += mine[i][j] - '0';
		}
	}
	return ret;
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<ROW*COL-EASYCOUNT)
	{
		printf("请输入排查坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法
			if (mine[x][y] == '1')
			{	
				//1.踩雷
				printf("很遗憾，你踩雷了！\n");	
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//2.不是雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';  //在显示棋盘中显示相同位置雷的个数
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入！\n");
		}
	}
	if (win == ROW*COL - EASYCOUNT)  //增加判断，否则上面踩雷时会显示排雷成功。
	{
		printf("恭喜你，排雷成功！\n");
		DisplayBoard(mine, row, col);
	}

}