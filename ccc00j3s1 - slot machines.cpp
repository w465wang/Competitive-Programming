/*
PEG
Date Started: 2017/07/07, Date Finished: 2017/07/07
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int q, m1, m2, m3;
	cin >> q;
	cin >> m1;
	cin >> m2;
	cin >> m3;

	int t = 0;
	while (q > 0)
	{
		q--;
		t++;

		if (t % 3 == 1)
		{
			m1++;
			if (m1 % 35 == 0)
			{
				q += 30;
			}
		}
		else if (t % 3 == 2)
		{
			m2++;
			if (m2 % 100 == 0)
			{
				q += 60;
			}
		}
		else if (t % 3 == 0)
		{
			m3++;
			if (m3 % 10 == 0)
			{
				q += 9;
			}
		}
	}

	cout << "Martha plays " << t << " times before going broke.\n";

	system("pause");
}
