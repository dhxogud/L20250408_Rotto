#include <iostream>
#include <string>

#define NUMBER_SIZE		7

using namespace std;

int ComputerNumbers[NUMBER_SIZE] = { 0, };
int PlayerNumbers[7] = { 0, };

void Initialize()
{
	for (int Index = 0; Index < NUMBER_SIZE; Index++)
	{
		ComputerNumbers[Index] = Index + 1;
	}
}

void Shuffling()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < NUMBER_SIZE * 100; i++)
	{
		int First = rand() % NUMBER_SIZE;
		int Second = rand() % NUMBER_SIZE;
		char Temp = ComputerNumbers[First];
		ComputerNumbers[First] = ComputerNumbers[Second];
		ComputerNumbers[Second] = Temp;
	}
}

void PickNumber()
{
	for (int i = 0; i < 7; i++)
	{
		cout << "번호를 선택하세요 : ";
		cin >> PlayerNumbers[i];
	}
}

void PrintResult()
{
	int MatchCount = 0;
	bool IsBonus = false;
	for (int i = 0; i < 7; i++)
	{
		cout << "컴퓨터가 고른 번호 : " + to_string(ComputerNumbers[i]) << endl;
		cout << "플레이어가 고른 번호 : " + to_string(PlayerNumbers[i]) << endl;
		cout << "===============================" << endl;

		if (ComputerNumbers[i] == PlayerNumbers[i])
		{
			if (i == 6)
			{
				IsBonus = true;
			}
			else
			{
				MatchCount += 1;
			}
		}
	}


	if (MatchCount == 6) // 1등
	{
		cout << "1등 당첨 성공!";
	}
	else if (MatchCount == 5 && IsBonus) // 2등
	{
		cout << "2등 당첨 성공!";
	}
	else if (MatchCount == 5 && !IsBonus) // 3등
	{
		cout << "3등 당첨 성공!";
	}
	else if (MatchCount == 4) // 4등
	{
		cout << "4등 당첨 성공!";
	}
	else if (MatchCount == 3) // 5등
	{
		cout << "5등 당첨 성공!";
	}
	else
	{
		cout << "당첨 실패!";
	}
	cout << endl;
	return;
}

int main()
{

	Initialize(); // 초기화
	Shuffling(); // 당첨 번호 랜덤으로 추첨
	PickNumber();	// 플레이어 번호 선택(총 7번 = 6 + 보너스 1번)
	PrintResult();	// 결과 출력



	return 0;
}