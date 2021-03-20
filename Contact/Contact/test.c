#define _CRT_SECURE_NO_WARNINGS 1  

#include "contact.h"

void menu()
{
	printf("*******************************\n");
	printf("***** 1.add      2.del    *****\n");
	printf("***** 3.search   4.modify *****\n");
	printf("***** 5.show     6.sort   *****\n");
	printf("***** 0.exit              *****\n");
	printf("*******************************\n");
}
int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;  //con就是通讯录，里面包含数组和size
		////int size = 0;  //记录通讯录已经存放多少人
		////struct PeoInfo data[MAX];//存放1000人信息
	//初始化通信录
	InitContact(&con);
	//通过菜单方式增加修改控制通讯录
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);

	return 0;
}