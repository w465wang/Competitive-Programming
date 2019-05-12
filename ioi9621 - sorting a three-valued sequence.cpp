/*
Peg
Date Started: 2017/07/31, Date Finished: 2017/07/31
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> swit(vector<int> seq, int first, int last)
{
	int temp = seq[first];
	seq[first] = seq[last];
	seq[last] = temp;

	return seq;
}

int main()
{
	int n, q;
	cin >> n;
	vector<int> seq;
	vector<pair<int, int>> swap;

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &q);
		seq.push_back(q);
	}

	int c = 0;
	
	vector<int> counts = { 0 };
	for (int i0 = 1; i0 <= 3; i0++)
	{
		counts.push_back(count(seq.begin(), seq.end(), i0) + counts[i0 - 1]);
	}

	vector<int> copy = seq;
	sort(copy.begin(), copy.end());

	for (int lol = 1; lol <= 2; lol++)
	{
		for (int lmao = counts[lol - 1]; lmao < counts[lol]; lmao++)
		{
			int p = seq[lmao];
			int f = find(seq.begin() + counts[p - 1], seq.begin() + counts[p], lol) - seq.begin();

			if (f < counts[p] && lmao < f)
			{
				seq = swit(seq, lmao, f);

				swap.push_back({ lmao + 1,f + 1 });
				c++;
			}
		}
	}

	int num = 1;
	for (int j = 0; j < n; j++)
	{
		if (seq[j] != num)
		{
			int found = find(seq.begin() + counts[num], seq.begin() + counts[3], num) - seq.begin();
			seq = swit(seq, j, found);

			swap.push_back({ j + 1,found + 1 });
			c++;
		}

		if (j == counts[num] - 1)
		{
			num++;
		}
	}

	cout << c << "\n";
	
	for (int k = 0; k < c; k++)
	{
		printf("%d ", swap[k].first);
		printf("%d\n", swap[k].second);
	}

	system("pause");
}