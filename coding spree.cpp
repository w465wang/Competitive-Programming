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
	int n, t, v, h;
	cin >> n >> t;

	pair<int, int> lol;
	vector<pair<int, int>> prob;

	vector<vector<int>> mem;
	vector<int> add;
	vector<int> zero(t + 1, 0);
	mem.push_back(zero);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &v);
		scanf_s("%d", &h);

		lol = { h, v };
		prob.push_back(lol);
	}

	sort(prob.begin(), prob.end());

	int time = 0;
	int max = 0;
	int temp;
	for (int j = 0; j < n; j++)
	{
		if (prob[j].first <= t)
		{
			add = { 0 };
			time += prob[j].first;

			for (int k = 1; k <= t; k++)
			{
				if (k < prob[j].first)
					add.push_back(mem[j][k]);
				else if (k > time)
					add.push_back(add[time]);
				else
				{
					temp = prob[j].second + mem[j][k - prob[j].first];
					
					if (temp >= mem[j][k])
						add.push_back(temp);
					else
						add.push_back(mem[j][k]);
				}
			}

			if (add.back() > max)
				max = add.back();

			mem.push_back(add);
		}
		else
			j = n + 1;
	}

	cout << max << "\n";

	system("pause");
}
