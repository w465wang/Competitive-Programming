/*
PEG
Date Started: 2017/07/13, Date Finished: 2017/07/13
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sort(vector<vector<int>> list, int ind)
{
	int len = list.size();
	for (int i1 = 0; i1 < len; i1++)
	{
		for (int i2 = 0; i2 < len - 1; i2++)
		{
			if (list[i2][ind - 1] > list[i2 + 1][ind - 1])
			{
				vector<int> temp = list[i2];
				list[i2] = list[i2 + 1];
				list[i2 + 1] = temp;
			}
		}
	}

	return list;
}

int main()
{
	int r, c, cell, n;
	cin >> r >> c;

	vector<vector<int>> spread;
	for (int i = 0; i < r; i++)
	{
		vector<int> col;
		for (int j = 0; j < c; j++)
		{
			cin >> cell;
			col.push_back(cell);
		}

		spread.push_back(col);
	}

	cin >> n;
	int s;
	for (int k = 0; k < n; k++)
	{
		cin >> s;
		spread = sort(spread, s);
	}

	for (int l = 0; l < r; l++)
	{
		for (int m = 0; m < c; m++)
		{
			cout << spread[l][m] << " ";
		}
		cout << "\n";
	}

	system("pause");
}