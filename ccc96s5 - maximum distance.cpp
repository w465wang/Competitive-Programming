/*
PEG
Date Started: 2017/07/18, Date Finished: 2017/07/22
3.0/10: 2017/07/18
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int m, n, o;
	cin >> m;

	while (m--)
	{
		cin >> n;
		vector<int> x;
		vector<int> y;
		int max = 0;

		for (int k = 0; k < n; k++)
		{
			scanf_s("%d", &o); //scanf for judge
			x.push_back(o);
		}

		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &o);
			y.push_back(o);
		}

		sort(y.begin(), y.end());

		for (int j = 0; j < n; j++)
		{
			int i = lower_bound(y.begin(), y.begin() + n, x[j]) - y.begin();

			if (n - 1 - i - j > max)
			{
				max = n - 1 - i - j;
			}
		}

		cout << "The maximum distance is " << max << "\n";
	}

	system("pause");
}
