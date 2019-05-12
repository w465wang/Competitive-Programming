/*
PEG
Date Started: 2017/08/19, Date Finished: 2017/08/23
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int m, n, c;
	cin >> m >> n;

	vector<int> club, add;
	vector<vector<int>> mem;

	vector<int> zero(m + 1, 0);
	mem.push_back(zero);

	for (int i = 0; i < n; i++)
	{
		cin >> c;
		club.push_back(c);
	}

	sort(club.begin(), club.end());

	int min = m + 1;
	for (int i1 = 0; i1 < n; i1++)
	{
		add = { 0 };

		for (int i2 = 1; i2 <= m; i2++)
		{
			if (i2 % club[i1] == 0)
				add.push_back(i2 / club[i1]);
			else
			{
				int i3 = i2 - club[i1];
				int temp;
				int it = 1;
				
				if (mem[i1][i2] > 0)
					temp = mem[i1][i2];
				else
					temp = m;

				while (i3 > 0)
				{
					if (mem[i1][i3] != 0 && it + mem[i1][i3] < temp)
						temp = it + mem[i1][i3];				


					i3 -= club[i1];
					it++;
				}

				if (temp == m)
					add.push_back(mem[i1][i2]);
				else if (mem[i1][i2] > 0)
					if (temp > mem[i1][i2])
						add.push_back(mem[i1][i2]);
					else
						add.push_back(temp);
				else if (mem[i1][i2] == 0 && temp < m)
					add.push_back(temp);
			}
		}

		if (add.back() < min && add.back() != 0)
			min = add.back();

		mem.push_back(add);
	}

	if (min <= m)
		printf("Roberta wins in %d strokes.\n", min);
	else
		printf("Roberta acknowledges defeat.\n");

	system("pause");
}
