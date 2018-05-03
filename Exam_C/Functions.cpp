#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Structures.h"

void generirMarka(char *Marka)	//��������� ����� ����
{
	char *marka[] = { "������","��������", "���", "������", "���" };
	strcpy(Marka, marka[rand() % 5]);
}

void generirModelToy(char *Model)	//��������� ������ ����
{
	char *model[] = { "�����","�������", "�����", "����", "�����" };
	strcpy(Model, model[rand() % 5]);
}

void generirModelMers(char *Model)	//��������� ������ ����
{
	char *model[] = { "W124","W210", "W211", "W163", "W203" };
	strcpy(Model, model[rand() % 5]);
}

void generirModelBMW(char *Model)	//��������� ������ ����
{
	char *model[] = { "5_series","3_series", "1_series", "X3", "X5" };
	strcpy(Model, model[rand() % 5]);
}

void generirModelSub(char *Model)	//��������� ������ ����
{
	char *model[] = { "��������","�������", "������", "������", "�������" };
	strcpy(Model, model[rand() % 5]);
}

void generirModelVAZ(char *Model)	//��������� ������ ����
{
	char *model[] = { "������","������", "������", "����", "������" };
	strcpy(Model, model[rand() % 5]);
}

void generirDvigatel(char *Dvigatel)	//��������� ���� ��������� ����
{
	char *dvig[] = { "������","������","���" };
	strcpy(Dvigatel, dvig[rand() % 3]);
}

void generirKuzov(char *Kuzov)	//��������� ������ ���� 
{
	char *kuzov[] = { "�����","���������" };
	strcpy(Kuzov, kuzov[rand() % 2]);
}

void generirKPP(char *KPP)	//��������� ��� ���� 
{
	char *kpp[] = { "��������","�������" };
	strcpy(KPP, kpp[rand() % 2]);
}

void generirPrivod(char *Privod)	//��������� ������� ���� 
{
	char *privod[] = { "��������","������", "������" };
	strcpy(Privod, privod[rand() % 3]);
}

void generirRul(char *Rul)	//��������� ������������ ���� ���� 
{
	char *rul[] = { "������������","�����������" };
	strcpy(Rul, rul[rand() % 2]);
}

void generirNomer(char *Nomer)	//��������� ������
{
	int n1, n2, n3;
	char n4, n5, nomer[21];

	n1 = rand() % 9;
	n2 = rand() % 9;
	if ((n1 == 0) && (n2 == 0))
		n3 = 1 + rand() % 9;
	else
		n3 = rand() % 9;
	n4 = 65 + rand() % 25;
	n5 = 65 + rand() % 25;

	nomer[0] = n1 + '0';
	nomer[1] = n2 + '0';
	nomer[2] = n3 + '0';
	nomer[3] = n4;
	nomer[4] = n5;
	nomer[5] = '0';
	nomer[6] = '2';
	nomer[7] = '\0';
	strcpy(Nomer, nomer);
}

vremya generirVremya(vremya data)
{
	//srand(time(NULL));
	data.chas = 8 + rand() % 9;
	if (data.chas == 18)
	{
		data.min = 0;
		data.sek = 0;
	}
	else
	{
		data.min = 1 + rand() % 59;
		data.sek = 1 + rand() % 59;
	}

	return data;
}

int generirNomMarsh(int NomerMarsh)
{
	//srand(time(NULL));
	int marsh[10] = { 1,2,3,4,5,6,7,8,9,10 };
	return NomerMarsh = marsh[rand() % 10];
}

int generirVremObmen()
{
	int VremObmen;
	return VremObmen = 7 + rand() % 10;
}