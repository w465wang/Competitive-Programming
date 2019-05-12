/*
PEG
Date Started: 2017/08/12, Date Finished: 2017/08/13
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> give, rec;
int num = 0;

void func(int g, int r)
{
	if (give[g] >= rec[r])
	{
		give[g] -= rec[r];
		num += rec[r];
		rec[r] = 0;
	}
	else
	{
		rec[r] -= give[g];
		num += give[g];
		give[g] = 0;
	}
}

int main()
{
	int blood;

	for (int i = 0; i < 8; i++)
	{
		cin >> blood;
		give.push_back(blood);
	}

	for (int j = 0; j < 8; j++)
	{
		cin >> blood;
		rec.push_back(blood);
	}

	for (int b = 0; b < 8; b++)
	{
		func(b, b);
	}

	vector<vector<int>> rem = { { 1, 2, 4 }, { 3, 5 }, { 3, 6 }, { }, { 5, 6 } };

	for (int e = 0; e < 4; e++)
	{
		int len = rem[e].size();
		for (int l = 0; l < len; l++)
		{
			func(e, rem[e][l]);
		}
	}

	for (int abp = 0; abp <= 6; abp++)
	{
		func(abp, 7);
	}

	vector<int> zero = { 3, 5, 6 };

	for (int z = 0; z < 3; z++)
	{
		func(0, zero[z]);
	}

	cout << num << "\n";

	system("pause");
}