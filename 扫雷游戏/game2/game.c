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
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{	
		printf("%d ", i); //��ӡ�к�
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
	//����1�������Ƚϣ�count++
	//����2
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
		printf("�������Ų�����:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����Ϸ�
			if (mine[x][y] == '1')
			{	
				//1.����
				printf("���ź���������ˣ�\n");	
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//2.������
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';  //����ʾ��������ʾ��ͬλ���׵ĸ���
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("��������Ƿ������������룡\n");
		}
	}
	if (win == ROW*COL - EASYCOUNT)  //�����жϣ������������ʱ����ʾ���׳ɹ���
	{
		printf("��ϲ�㣬���׳ɹ���\n");
		DisplayBoard(mine, row, col);
	}

}