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
		cout << "��ȣ�� �����ϼ��� : ";
		cin >> PlayerNumbers[i];
		ComputerNumbers[i] = PlayerNumbers[i];
	}
}

void PrintResult()
{
	int MatchCount = 0;
	bool IsBonus = false;
	for (int i = 0; i < 7; i++)
	{
		cout << "��ǻ�Ͱ� �� ��ȣ : " + to_string(ComputerNumbers[i]) << endl;
		cout << "�÷��̾ �� ��ȣ : " + to_string(PlayerNumbers[i]) << endl;
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


	if (MatchCount == 6) // 1��
	{
		cout << "1�� ��÷ ����!";
	}
	else if (MatchCount == 5 && IsBonus) // 2��
	{
		cout << "2�� ��÷ ����!";
	}
	else if (MatchCount == 5 && !IsBonus) // 3��
	{
		cout << "3�� ��÷ ����!";
	}
	else if (MatchCount == 4) // 4��
	{
		cout << "4�� ��÷ ����!";
	}
	else if (MatchCount == 3) // 5��
	{
		cout << "5�� ��÷ ����!";
	}
	else
	{
		cout << "��÷ ����!";
	}
	cout << endl;
	return;
}

int main()
{

	Initialize(); // �ʱ�ȭ
	Shuffling(); // ��÷ ��ȣ �������� ��÷
	PickNumber();	// �÷��̾� ��ȣ ����(�� 7�� = 6 + ���ʽ� 1��)
	PrintResult();	// ��� ���



	return 0;
}