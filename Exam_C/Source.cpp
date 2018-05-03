#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string>
#include <locale.h>
#include <stdlib.h>
#include <Windows.h>
#include "Structures.h"
#include "Functions.h"

#define kolPochtMash  10

FILE * fp;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");

	pochtMashina pochtMash[kolPochtMash] = { 0 };

	for (size_t i = 0; i < kolPochtMash; i++)
	{
		pochtMash[i].vremVyezd = generirVremya((pochtMash[i].vremVyezd));
		//printf("%d:%d:%d\n", pochtMash[i].vremVyezd.chas, pochtMash[i].vremVyezd.min, pochtMash[i].vremVyezd.sek);
	}

	printf("+++++++++++++++++++++++++++++++\n");
	for (size_t i = 0; i < kolPochtMash; i++)
	{
		//����� ��������
		pochtMash[i].vremPribyt = generirVremya((pochtMash[i].vremPribyt));
		//����� ������
		pochtMash[i].vremVyezd = generirVremya((pochtMash[i].vremVyezd));
		//����� ����
		generirMarka(pochtMash[i].nomerMash.marka);
		//������ ����
		char *temp[] = { "������", "��������", "���", "������", "���" };
		if (!strcmp(pochtMash[i].nomerMash.marka, temp[0]))
			generirModelToy(pochtMash[i].nomerMash.model);
		else
			if (!strcmp(pochtMash[i].nomerMash.marka, temp[1]))
				generirModelMers(pochtMash[i].nomerMash.model);
			else
				if (!strcmp(pochtMash[i].nomerMash.marka, temp[2]))
					generirModelBMW(pochtMash[i].nomerMash.model);
				else
					if (!strcmp(pochtMash[i].nomerMash.marka, temp[3]))
						generirModelSub(pochtMash[i].nomerMash.model);
					else
						generirModelVAZ(pochtMash[i].nomerMash.model);
		//��� ��������� ����
		generirDvigatel(pochtMash[i].nomerMash.dvigatel);
		//����� ����
		generirKuzov(pochtMash[i].nomerMash.kuzov);
		//��� ����
		generirKPP(pochtMash[i].nomerMash.kpp);
		//������ ����
		generirPrivod(pochtMash[i].nomerMash.privod);
		//������������ ���� ����
		generirRul(pochtMash[i].nomerMash.rul);
		//����� ����
		generirNomer(pochtMash[i].nomerMash.nomer);
		//����� ��������
		pochtMash[i].nomMarshrut = generirNomMarsh(pochtMash[i].nomMarshrut);
		//����� ������ ����� � �������
		pochtMash[i].vremObmen = generirVremObmen();

		/*printf("%d:%d:%d\n", pochtMash[i].vremPribyt.chas, pochtMash[i].vremPribyt.min, pochtMash[i].vremPribyt.sek);
		printf("%s ", pochtMash[i].nomerMash.marka);
		printf("%s ", pochtMash[i].nomerMash.model);
		printf("%s\n", pochtMash[i].nomerMash.dvigatel);*/
	}

	char filePathAm[30] = "1_am.txt";
	char filePathPm[30] = "1_pm.txt";

	for (size_t i = 0; i < kolPochtMash; i++)

		if (pochtMash[i].vremVyezd.chas < 12)
		{
			if ((fp = fopen(filePathAm, "a")) == NULL)
			{
				printf("������ ��� �������� �����.\n");
				exit(1);
			}
			else
			{
				//printf("��� o����� ��� �������� �����.\n");
				fprintf(fp, "%d|%d:%d:%d|%d:%d:%d|%s|%s|%s|%s|%s|%s|%s|%s|%d\n", pochtMash[i].nomMarshrut, pochtMash[i].vremVyezd.chas,
					pochtMash[i].vremVyezd.min, pochtMash[i].vremVyezd.sek, pochtMash[i].vremPribyt.chas,
					pochtMash[i].vremPribyt.min, pochtMash[i].vremPribyt.sek, pochtMash[i].nomerMash.marka,
					pochtMash[i].nomerMash.model, pochtMash[i].nomerMash.dvigatel, pochtMash[i].nomerMash.kuzov,
					pochtMash[i].nomerMash.kpp, pochtMash[i].nomerMash.privod, pochtMash[i].nomerMash.rul, 
					pochtMash[i].nomerMash.nomer, pochtMash[i].vremObmen);
				fclose(fp);
			}
		}

		else
			if ((fp = fopen(filePathPm, "a")) == NULL)
			{
				printf("������ ��� �������� �����.\n");
				exit(1);
			}
			else
			{
				//printf("��� o����� ��� �������� �����.\n");
				fprintf(fp, "%d|%d:%d:%d|%d:%d:%d|%s|%s|%s|%s|%s|%s|%s|%s|%d\n", pochtMash[i].nomMarshrut, pochtMash[i].vremVyezd.chas,
					pochtMash[i].vremVyezd.min, pochtMash[i].vremVyezd.sek, pochtMash[i].vremPribyt.chas,
					pochtMash[i].vremPribyt.min, pochtMash[i].vremPribyt.sek, pochtMash[i].nomerMash.marka,
					pochtMash[i].nomerMash.model, pochtMash[i].nomerMash.dvigatel, pochtMash[i].nomerMash.kuzov,
					pochtMash[i].nomerMash.kpp, pochtMash[i].nomerMash.privod, pochtMash[i].nomerMash.rul,
					pochtMash[i].nomerMash.nomer, pochtMash[i].vremObmen);
				fclose(fp);
			}




	system("pause");
}

