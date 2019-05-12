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
	int x, n, c;
	cin >> x >> n;

	vector<int> coins, add;
	vector<vector<int>> mem;
	vector<int> zero(x + 1, 0);
	mem.push_back(zero);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &c);
		coins.push_back(c);
	}

	sort(coins.begin(), coins.end());

	int min = x + 1;
	for (int j = 0; j < n; j++)
	{
		add = { 0 };

		for (int k = 1; k <= x; k++)
		{
			if (k < coins[j])
				add.push_back(mem[j][k]);
			else if (k % coins[j] == 0)
				add.push_back(k / coins[j]);
			else
			{
				int k1 = k - coins[j];
				int temp;
				int it = 1;

				if (mem[j][k] > 0)
					temp = mem[j][k];
				else
					temp = x;

				while (k1 > 0)
				{
					if (mem[j][k1] != 0 && it + mem[j][k1] < temp)
						temp = it + mem[j][k1];

					k1 -= coins[j];
					it++;
				}

				if (temp == x)
					add.push_back(mem[j][k]);
				else if (mem[j][k] > 0)
					if (temp > mem[j][k])
						add.push_back(mem[j][k]);
					else
						add.push_back(temp);
				else if (mem[j][k] == 0 && temp < x)
					add.push_back(temp);
			}
		}

		if (add.back() < min && add.back() != 0)
			min = add.back();

		mem.push_back(add);
	}

	cout << min << "\n";

	system("pause");
}
