#include <iostream>
#define PASSWORD	"645"
using namespace std;

int main()
{
	char InputPassword[10] = { '0', };

	cin >> InputPassword;

	cout << InputPassword << endl;

	for (int i = 0; i < 3; i++)
	{
		if (PASSWORD[i] != InputPassword[i])
		{
			cout << "��÷ ����!" << endl;
			return 0;
		}
	}
	cout << "�ζ� ��÷!" << endl;

	return 0;
}