/*
PEG
Date Started: 2017/07/08, Date Finished: 2017/07/08
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, d, a;
	cin >> n;
	cin >> d;

	a = n / d; 
	n %= d;

	int common = 1;
	for (int i = 1; i < n + 1; i++)
	{
		if (n%i == 0 && d%i == 0)
		{
			common = i;
		}
	}

	n /= common;
	d /= common;
	
	if (a > 0)
	{
		cout << a << " ";
	}

	if (n != 0)
	{
		cout << n << "/" << d << "\n";
	}
	else
	{
		cout << endl;
	}

	system("pause");
}