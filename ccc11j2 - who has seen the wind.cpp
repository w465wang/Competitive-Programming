/*
PEG
Date Started: 2017/07/06, Date Finished: 2017/07/06
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int h, m, a, t;
	cin >> h;
	cin >> m;
	
	a = h - 3;
	t = 1;
	while (a > 0 && t <= m)
	{
		t++;
		a = -6 * t*t*t*t + h*t*t*t + 2 * t*t + t;
	}

	if (t > m)
	{
		cout << "The balloon does not touch ground in the given time.\n";
	}
	else if (a <= 0)
	{
		cout << "The balloon first touches ground at hour:\n";
		cout << t << "\n";
	}

	system("pause");
}
