/*
PEG
Date Started: 2017/08/24, Date Finished: 2017/08/24
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int r, c, k, r1, c1;
	cin >> r >> c >> k;

	vector<int> col(c, 0);
	vector<vector<int>> cage(r, col);

	for (int i = 0; i < k; i++)
	{
		cin >> r1 >> c1;
		cage[r1 - 1][c1 - 1] = -1;
	}

	for (int j = 0; j < r; j++)
	{
		for (int k = 0; k < c; k++)
		{
			if (cage[j][k] == -1)
				continue;
			else if (j == 0 && k == 0)
				cage[j][k] = 1;
			else
			{
				int tempJ = 0;
				int tempK = 0;

				if (j > 0 && cage[j - 1][k] != -1)
					tempJ = cage[j - 1][k];
				if (k > 0 && cage[j][k - 1] != -1)
					tempK = cage[j][k - 1];

				cage[j][k] = tempJ + tempK;
			}
		}
	}

	cout << cage[r - 1][c - 1] << "\n";

	system("pause");
}