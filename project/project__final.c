#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACEBSR 32
#define _CRT_SECURE_NO_WARNINGS


int player[15];   //�÷��̾� ī��� 1���� �迭
int computer[15]; //��ǻ�� ī��� 1���� �迭
int cardcount1 = 7;   //�÷��̾ ī�� ������ �ִ� ��
int cardcount2 = 7;   //��ǻ�Ͱ� ī�� ������ �ִ� ��
int center;  //�����Ǿ� �ִ� ī��
int order; //�������ϱ�

int dummy[51] = { 0, }; //���µǾ��ִ� ī�� �Ʒ��� �ִ� ī�� �迭 (40�̻��̸� �ٲ۴�)
int card[4][13] =
{
   {10,11,12,13,14,15,16,17,18,19,20,21,22},  //��
   {30,31,32,33,34,35,36,37,38,39,40,41,42},  //��
   {50,51,52,53,54,55,56,57,58,59,60,61,62},  //��
   {70,71,72,73,74,75,76,77,78,79,80,81,82}   //��
}; //ī�� ���� �迭


void openf(); //������ ī�� �������ִ� �Լ�
void plcardf(); //�÷��̾� ī�� ����
void cocardf(); //��ǻ�� ī�� ����

void comturn(); //��ǻ�� ��
void plturn(); //�÷��̾� ��
void dummyf(); // ���� 40�̻��̸� ���������� ���� �����ִ� �Լ�
void finish();
void keyf();



//////////////�����Լ�
int main()
{
	openf(); //������ ī�� �������ִ� �Լ�
	plcardf(); //�÷��̾� ī�� ����
	cocardf(); //��ǻ�� ī�� ����

	while (1)
	{
		if (order = 1)
		{
			comturn();


			if (dummy[39] != 0)
			{
				dummyf();
			}
			if (computer[15] != 0)
			{
				break;
			}
			else if (player[15] != 0)
			{
				break;
			}


			plturn();


			if (dummy[39] != 0)
			{
				dummyf();
			}
			if (computer[15] != 0)
			{
				break;
			}
			else if (player[15] != 0)
			{
				break;
			}


		}

		if (order = 0)
		{
			plturn();


			if (dummy[39] != 0)
			{
				dummyf();
			}
			if (computer[15] != 0)
			{
				break;
			}
			else if (player[15] != 0)
			{
				break;
			}


			comturn();


			if (dummy[39] != 0)
			{
				dummyf();
			}
			if (computer[15] != 0)
			{
				break;
			}
			else if (player[15] != 0)
			{
				break;
			}


		}
	}
	return 0;
}





/////////////����� ���� �Լ���

void openf() //������ ī�� �������ִ� �Լ�
{
	srand((unsigned int)time(NULL)); //���� ���
	int sum1 = (rand() % 4); //ī�� �迭�� ���κκ�
	int sum2 = (rand() % 13); //ī�� �迭�� ���κκ�
	center = card[sum1][sum2];
	card[sum1][sum2] += 1000;
}

void plcardf() //�÷��̾� ī�� ����
{
	for (int i = 0; i < 7; i++)  //player1�� ī�� 7�� �����ֱ� ,������ ���ڴ� card�迭���� 1000�� ���ؼ� ����ȭ�� �� �ֵ��� �Ѵ�.
	{
		int sum1 = (rand() % 4); //ī�� �迭�� ���κκ�
		int sum2 = (rand() % 13); //ī�� �迭�� ���κκ�
		if (card[sum1][sum2] / 1000 == 1)
		{
			i--;
			continue;
		}
		player[i] = card[sum1][sum2];
		card[sum1][sum2] = card[sum1][sum2] + 1000;
	}
}

void cocardf() //��ǻ�� ī�� ����
{
	for (int i = 0; i < 7; i++)    //player2�� ī�� 7�� �����ֱ� ,������ ���ڴ� card�迭���� 1000�� ���ؼ� ����ȭ�� �� �ֵ��� �Ѵ�.
	{
		int sum1 = (rand() % 4); //ī�� �迭�� ���κκ�
		int sum2 = (rand() % 13); //ī�� �迭�� ���κκ�
		if (card[sum1][sum2] / 1000 == 1)
		{
			i--;
			continue;
		}
		computer[i] = card[sum1][sum2];
		card[sum1][sum2] = card[sum1][sum2] + 1000;
	}

}

void comturn() //��ǻ�� ��
{
	for (int i = 0; i < 4; i++) //��ǻ�� �� ����
	{
		for (int n = 0; n < 13; n++)
		{
			for (int r = 0; r <= 14; r++)
			{
				if (card[i][n] - 1000 == computer[r]) //��ǻ���� ī�忡�� ī�� �迭���� -1000�� ���� ���� ī��ã��
				{
					if (center / 10 == card[i][n] - 1000 / 10 || center % 10 == card[i][n] - 1000 % 10)  //�� ī�带 10���� �������� ���ų� �������� ������
					{
						for (int j = 0; j <= 51; j++) // ���� ä���
						{
							if (dummy[j] == 0)
							{
								dummy[j] = center;
							}
							//card[sum1][sum2] = card[sum1][sum2] - 1000;     
							// (card[sum1][sum2] = senter) , card�迭�� �ִ� (���Ͱ�+1000)�� -1000���ش�
						}
						center = computer[r];                       //���ο� center�� �������ش�.
						//card[i][n] = card[i][n] - 1000;         //���� center�� �迭������ ���� ���༭ ���� ������ �����. 
						computer[r] = 0;                      // �÷��̾� ī���� �ϳ��� ���ش�.
					}
					else    //�װ� �ƴϸ� ������ �����Ѵ�
					{
						for (int i = 0; i <= 10; i++)
						{
							int semple1 = (rand() % 4);
							int semple2 = (rand() % 13);

							if (card[semple1][semple2] / 1000 == 1)
							{
								i--;
								continue;
							}
							else
							{
								for (int n; n <= 14; n++)
								{
									if (computer[n] == 0)
									{
										computer[n] = card[semple1][semple2]; //ī�� ���� �Դ� ����
										card[semple1][semple2] = card[semple1][semple2] + 1000;  //ī�� �Ծ����ϱ� ���ڸ��� �迭���� + 1000���ش�
										break;
									}
								}
								break;
							}
						}
						break;
						cardcount2 = cardcount2 + 1; //ī�� �����ϱ� +1
					}
					break;
				}
				break;
			}
			break;
		}
		break;
	}
}


void plturn() //�÷��̾� ��
{
	for (int i = 0; i < 4; i++)
	{
		for (int n = 0; n < 13; n++)
		{
			for (int r = 0; r <= 14; r++)
			{
				if (card[i][n] - 1000 == player[r]) //�÷��̾��� ī�忡�� ī�� �迭���� -1000�� ���� ���� ī��ã��
				{
					if (center / 10 == card[i][n] - 1000 / 10 || center % 10 == card[i][n] - 1000 % 10)  //�� ī�带 10���� �������� ���ų� �������� ������
					{
						for (int j = 0; j <= 51; j++) // ���� ä���
						{
							if (dummy[j] == 0)
							{
								dummy[j] = center;
							}
							//card[sum1][sum2] = card[sum1][sum2] - 1000;       // (card[sum1][sum2] = senter) , card�迭�� �ִ� (���Ͱ�+1000)�� -1000���ش�
						}
						center = computer[r];                       //���ο� center�� �������ش�.
						card[i][n] = card[i][n] - 1000;         //���� center�� �迭������ ���� ���༭ ���� ������ �����. 
						player[r] = 0;                     // �÷��̾� ī���� �ϳ��� ���ش�.
					}
					else    //�װ� �ƴϸ� ������ �����Ѵ�
					{
						while (1)
						{
							int semple1 = (rand() % 4);
							int semple2 = (rand() % 13);
							if (card[semple1][semple2] / 1000 == 0)
							{
								player[cardcount1] = card[semple1][semple2]; //ī�� ���� �Դ� ����
								card[semple1][semple2] = card[semple1][semple2] + 1000;  //ī�� �Ծ����ϱ� ���ڸ��� �迭���� + 1000���ش�
								break;
							}
						}
						cardcount1 = cardcount1 + 1; //ī�� �����ϱ� +1
					}

				}
			}

		}
	}
}

void dummyf()
{
	for (int i = 0; i < 4; i++)
	{
		for (int n = 0; n < 13; n++)
		{
			for (int r = 0; r <= 52; r++)
			{
				if (dummy[r] == card[i][n] - 1000)
				{
					card[i][n] = dummy[r];
				}

			}

		}
	}
}


void keyf() {
	int key = _getch();
	printf("%d", key);
	while (kbhit()) {
		key = _getch();
		switch (key) {
		case UP:
			printf("��");
			break;
		case DOWN:
			printf("��");
			break;
		case LEFT:
			printf("��");
			break;
		case RIGHT:
			printf("��");
			break;
		}
	}
}