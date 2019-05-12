/*
PEG
Date Started: 2017/07/04, Date Finished: 2017/07/04
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, y, m, d;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> y;
		cin >> m;
		cin >> d;

		if (y < 1989)
		{
			cout << "Yes\n";
		}
		else if (y > 1989)
		{
			cout << "No\n";
		}
		else if (y == 1989)
		{
			if (m < 2)
			{
				cout << "Yes\n";
			}
			else if (m > 2)
			{
				cout << "No\n";
			}
			else if (m == 2)
			{
				if (d <= 27)
				{
					cout << "Yes\n";
				}
				else if (d > 27)
				{
					cout << "No\n";
				}

			}
				
		}

	}

	system("pause");
}


