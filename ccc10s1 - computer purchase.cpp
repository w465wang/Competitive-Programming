/*
PEG
Date Started: 2017/07/05, Date Finished: 2017/07/06
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n, r, s, d;
	string name;

	cin >> n;
	vector<string> names(2);
	vector<int> sums(2);
	
	for (int i = 0; i < 2; i++)
	{
		names[i] = " ";
		sums[i] = 0;
	}

	for (int j = 0; j < n; j++)
	{
		cin >> name;
		cin >> r;
		cin >> s;
		cin >> d;
		int sum = 2 * r + 3 * s + d;

		if (sum > sums[0])
		{
			names[1] = names[0];
			sums[1] = sums[0];
			names[0] = name;
			sums[0] = sum;
		}
		else if (sum == sums[0])
		{
			if (name < names[0])
			{
				names[1] = names[0];
				sums[1] = sums[0];
				names[0] = name;
				sums[0] = sum;
			}
			else if (name > names[0])
			{
				if (sum > sums[1])
				{
					names[1] = name;
					sums[1] = sum;
				}
				else if (sum == sums[1])
				{
					if (name < names[1])
					{
						names[1] = name;
						sums[1] = sum;
					}
				}
			}
		}
		else if (sum < sums[0])
		{
			if (sum > sums[1])
			{
				names[1] = name;
				sums[1] = sum;
			}
			else if (sum == sums[1])
			{
				if (name < names[1])
				{
					names[1] = name;
					sums[1] = sum;
				}
			}
		}
	}

	cout << names[0] << "\n";
	cout << names[1] << "\n";
	
	system("pause");
}
