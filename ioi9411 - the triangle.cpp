/*
PEG
Date Started: 2017/08/23, Date Finished: 2017/08/23
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, t1, t2;
	scanf_s("%d", &n);
	scanf_s("%d", &m);

	vector<int> sums = { m };

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			scanf_s("%d", &m);

			if (j == 0 || j == i - 1)
				sums.push_back(sums[0] + m);
			else
			{
				t1 = sums[0] + m;
				t2 = sums[1] + m;

				if (t2 >= t1)
					sums.push_back(t2);
				else
					sums.push_back(t1);

				sums.erase(sums.begin());
			}
		}

		sums.erase(sums.begin());
	}

	sort(sums.begin(), sums.end());

	cout << sums.back() << "\n";

	system("pause");
}
