/*
PEG
Date Started: 2017/07/11, Date Finished: 2017/07/13
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

void diff(vector<int> list)
{
	int len = list.size();
	for (int j = 0; j < len; j++)
	{
		for (int k = 0; k < len - 1; k++)
		{
			if (list[k] > list[k + 1])
			{
				int temp = list[k];
				list[k] = list[k + 1];
				list[k + 1] = temp;
			}
		}
	}

	cout << list[len-1] - list[0] << "\n";
}

int main()
{
	int n, r;
	cin >> n;

	vector<int> read;
	set<int> indiv;

	while (n--)
	{
		cin >> r;
		indiv.insert(r);
		read.push_back(r);
	}

	int maxCount1 = 0;
	int maxCount2 = 0;
	vector<int> most1 = {};
	vector<int> most2 = {};
	for (set<int>::iterator i = indiv.begin(); i != indiv.end(); i++)
	{
		int itCount = count(read.begin(), read.end(), *i);
		if (itCount > maxCount1)
		{
			maxCount2 = maxCount1;
			maxCount1 = itCount;
			most2 = most1;
			most1 = { *i };
		}
		else if (itCount == maxCount1)
		{
			most1.push_back(*i);
		}
		else if (itCount < maxCount1)
		{
			if (itCount > maxCount2)
			{
				maxCount2 = itCount;
				most2 = { *i };
			}
			else if (itCount == maxCount2)
			{
				most2.push_back(*i);
			}
		}
	}

	if (most1.size() == 1)
	{
		int maxAbs = 0;
		int len = most2.size();
		for (int i1 = 0; i1 < len; i1++)
		{
			if (abs(most1[0] - most2[i1]) > maxAbs)
			{
				maxAbs = abs(most1[0] - most2[i1]);
			}
		}

		cout << maxAbs << "\n";
	}
	else
	{
		diff(most1);
	}

	system("pause");
}