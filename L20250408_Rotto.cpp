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
			cout << "´çÃ· ½ÇÆÐ!" << endl;
			return 0;
		}
	}
	cout << "·Î¶Ç ´çÃ·!" << endl;

	return 0;
}