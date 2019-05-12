/*
PEG
Date Started: 2017/07/03, Date Finished: 2017/07/03
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int x, y, count;
	cin >> x;
	cin >> y;
	count = 0;
	double p = 1.0 / 3.0;
	double w = pow(x, p);

	for (int a = sqrt(x); a*a <= y; a++)
	{
		for (int b = w; b*b*b <= y; b++)
		{
			if (a*a == b*b*b)
			{
				count++;
			}
		}
	}

	cout << count << "\n";

	system("pause");
}
