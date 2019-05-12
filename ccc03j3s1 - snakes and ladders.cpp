/*
PEG
Date Started: 2017/07/05, Date Finished: 2017/07/05
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int roll, pos;
	cin >> roll;
	pos = 1;

	while (roll != 0 && pos != 100)
	{
		if (pos + roll <= 100)
		{
			pos += roll;
		}

		if (pos == 54)
		{
			pos = 19;
		}
		else if (pos == 90)
		{
			pos = 48;
		}
		else if (pos == 99)
		{
			pos = 77;
		}
		else if (pos == 9)
		{
			pos = 34;
		}
		else if (pos == 40)
		{
			pos = 64;
		}
		else if (pos == 67)
		{
			pos = 86;
		}

		cout << "You are now on square " << pos << "\n";
		if (pos != 100)
		{	
			cin >> roll;
		}
		
	}

	if (roll == 0)
	{
		cout << "You Quit!\n";
	}
	else if (pos == 100)
	{
		cout << "You Win!\n";
	}

	system("pause");
}
