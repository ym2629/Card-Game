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


int player[15];   //플레이어 카드는 1차원 배열
int computer[15]; //컴퓨터 카드는 1차원 배열
int cardcount1 = 7;   //플레이어가 카드 가지고 있는 수
int cardcount2 = 7;   //컴퓨터가 카드 가지고 있는 수
int center;  //공개되어 있는 카드
int order; //순서정하기

int dummy[51] = { 0, }; //오픈되어있는 카드 아래에 있는 카드 배열 (40이상이면 바꾼다)
int card[4][13] =
{
   {10,11,12,13,14,15,16,17,18,19,20,21,22},  //♠
   {30,31,32,33,34,35,36,37,38,39,40,41,42},  //◆
   {50,51,52,53,54,55,56,57,58,59,60,61,62},  //♥
   {70,71,72,73,74,75,76,77,78,79,80,81,82}   //♣
}; //카드 종류 배열


void openf(); //공개된 카드 지정해주는 함수
void plcardf(); //플레이어 카드 지정
void cocardf(); //컴퓨터 카드 지정

void comturn(); //컴퓨터 턴
void plturn(); //플레이어 턴
void dummyf(); // 더미 40이상이면 게임진행을 위해 섞어주는 함수
void finish();
void keyf();



//////////////메인함수
int main()
{
	openf(); //공개된 카드 지정해주는 함수
	plcardf(); //플레이어 카드 지정
	cocardf(); //컴퓨터 카드 지정

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





/////////////사용자 정의 함수들

void openf() //공개된 카드 지정해주는 함수
{
	srand((unsigned int)time(NULL)); //랜덤 모듈
	int sum1 = (rand() % 4); //카드 배열의 세로부분
	int sum2 = (rand() % 13); //카드 배열의 가로부분
	center = card[sum1][sum2];
	card[sum1][sum2] += 1000;
}

void plcardf() //플레이어 카드 지정
{
	for (int i = 0; i < 7; i++)  //player1의 카드 7개 정해주기 ,정해준 숫자는 card배열에서 1000을 더해서 차별화할 수 있도록 한다.
	{
		int sum1 = (rand() % 4); //카드 배열의 세로부분
		int sum2 = (rand() % 13); //카드 배열의 가로부분
		if (card[sum1][sum2] / 1000 == 1)
		{
			i--;
			continue;
		}
		player[i] = card[sum1][sum2];
		card[sum1][sum2] = card[sum1][sum2] + 1000;
	}
}

void cocardf() //컴퓨터 카드 지정
{
	for (int i = 0; i < 7; i++)    //player2의 카드 7개 정해주기 ,정해준 숫자는 card배열에서 1000을 더해서 차별화할 수 있도록 한다.
	{
		int sum1 = (rand() % 4); //카드 배열의 세로부분
		int sum2 = (rand() % 13); //카드 배열의 가로부분
		if (card[sum1][sum2] / 1000 == 1)
		{
			i--;
			continue;
		}
		computer[i] = card[sum1][sum2];
		card[sum1][sum2] = card[sum1][sum2] + 1000;
	}

}

void comturn() //컴퓨터 턴
{
	for (int i = 0; i < 4; i++) //컴퓨터 턴 시작
	{
		for (int n = 0; n < 13; n++)
		{
			for (int r = 0; r <= 14; r++)
			{
				if (card[i][n] - 1000 == computer[r]) //컴퓨터의 카드에서 카드 배열에서 -1000한 값과 같은 카드찾기
				{
					if (center / 10 == card[i][n] - 1000 / 10 || center % 10 == card[i][n] - 1000 % 10)  //그 카드를 10으로 나눈값이 같거나 나머지가 같으면
					{
						for (int j = 0; j <= 51; j++) // 더미 채우기
						{
							if (dummy[j] == 0)
							{
								dummy[j] = center;
							}
							//card[sum1][sum2] = card[sum1][sum2] - 1000;     
							// (card[sum1][sum2] = senter) , card배열에 있는 (센터값+1000)을 -1000해준다
						}
						center = computer[r];                       //새로운 center를 지정해준다.
						//card[i][n] = card[i][n] - 1000;         //원래 center의 배열에서의 값은 빼줘서 원래 값으로 만든다. 
						computer[r] = 0;                      // 플레이어 카드의 하나를 없앤다.
					}
					else    //그게 아니면 다음과 같이한다
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
										computer[n] = card[semple1][semple2]; //카드 새로 먹는 과정
										card[semple1][semple2] = card[semple1][semple2] + 1000;  //카드 먹었으니까 그자리의 배열값은 + 1000해준다
										break;
									}
								}
								break;
							}
						}
						break;
						cardcount2 = cardcount2 + 1; //카드 먹으니까 +1
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


void plturn() //플레이어 턴
{
	for (int i = 0; i < 4; i++)
	{
		for (int n = 0; n < 13; n++)
		{
			for (int r = 0; r <= 14; r++)
			{
				if (card[i][n] - 1000 == player[r]) //플레이어의 카드에서 카드 배열에서 -1000한 값과 같은 카드찾기
				{
					if (center / 10 == card[i][n] - 1000 / 10 || center % 10 == card[i][n] - 1000 % 10)  //그 카드를 10으로 나눈값이 같거나 나머지가 같으면
					{
						for (int j = 0; j <= 51; j++) // 더미 채우기
						{
							if (dummy[j] == 0)
							{
								dummy[j] = center;
							}
							//card[sum1][sum2] = card[sum1][sum2] - 1000;       // (card[sum1][sum2] = senter) , card배열에 있는 (센터값+1000)을 -1000해준다
						}
						center = computer[r];                       //새로운 center를 지정해준다.
						card[i][n] = card[i][n] - 1000;         //원래 center의 배열에서의 값은 빼줘서 원래 값으로 만든다. 
						player[r] = 0;                     // 플레이어 카드의 하나를 없앤다.
					}
					else    //그게 아니면 다음과 같이한다
					{
						while (1)
						{
							int semple1 = (rand() % 4);
							int semple2 = (rand() % 13);
							if (card[semple1][semple2] / 1000 == 0)
							{
								player[cardcount1] = card[semple1][semple2]; //카드 새로 먹는 과정
								card[semple1][semple2] = card[semple1][semple2] + 1000;  //카드 먹었으니까 그자리의 배열값은 + 1000해준다
								break;
							}
						}
						cardcount1 = cardcount1 + 1; //카드 먹으니까 +1
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
			printf("↑");
			break;
		case DOWN:
			printf("↓");
			break;
		case LEFT:
			printf("←");
			break;
		case RIGHT:
			printf("→");
			break;
		}
	}
}