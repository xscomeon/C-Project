#define _CRT_SECURE_NO_WARNINGS 1  

#include "contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;  //���ͨ��¼ֻ��0��Ԫ��
}

static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;//�ҵ���
		}
	}
	return -1;//�Ҳ���
}

void AddContact(struct Contact* ps)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷�����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[ps->size].name);
		printf("����������:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("��ӳɹ�\n");
	}

}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��.\n");
	}
	else
	{
		int i = 0;
		//��ӡ����
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//��ӡ����
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}

}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ������ϵ��:>");
	scanf("%s", name);
	//1.����Ҫɾ�����˵�λ��
	//�ҵ��˷�����������Ԫ�ص��±꣬�Ҳ�������-1
	int pos = FindByName(ps, name);
	//int i = 0;
	//for (i = 0; i < ps->size; i++)
	//{
	//	if (0 == strcmp(ps->data[i].name, name))
	//	{
	//		break;
	//	}
	//}
	//2.ɾ��
	//if (i == ps->size)
	if (pos==-1)
	{
		printf("Ҫɾ�����˲�����.\n");
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�.\n");
	}

}

void SearchContact(const struct Contact* ps)
{
	char* name[MAX_NAME];
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����.\n");
	}
	else
	{
		//��ӡ����
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//��ӡ����
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char* name[MAX_NAME];
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����.\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[pos].name);
		printf("����������:>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[pos].addr);

		printf("�޸����.\n");
	}
}

int contactcmp(const void* p1, const void* p2)
{
	return strcmp((*(struct PeoInfo*)p1).name, (*(struct PeoInfo*)p2).name);
}

//��������ǰ��������򣬻�����ʵ�ָ��๦��
void SortContact(struct Contact* ps)
{
	qsort(ps, ps->size, sizeof(ps->data[0]), contactcmp);
}