#define _CRT_SECURE_NO_WARNINGS 1 

#include "game.h"	





void game()
{
	//printf("sao lei\n");  //for test
	//�׵���Ϣ�洢
	//�Ų��׵���Ϣ
	char mine[ROWS][COLS] = { 0 }; //11*11
	char show[ROWS][COLS] = { 0 };

	//��ʼ��
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	//DisplayBoard(mine, ROW, COL);//9*9
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//ɨ��
	FindMine(mine,show, ROW, COL);   //mine��������ң������show��������ʾ

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
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ.\n");
			break;
		default:
			printf("�����������������.\n");
			break;
		}
	} while (input);

}



int main()
{

	test();
	return 0;
}