/*
PEG
Date Started: 2017/09/05, Date Finished: 2017/09/24
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int a[251][251][251] = {};
char done[251][251][251] = {};

int get_ways(int sum, int parts, int start)
{
	if (parts == 0)
	{
		if (sum > 0)
			return 0;
		else if (sum == 0)
			return 1;
	}

	if (start * parts > sum)
		return 0;

	if (done[sum][parts][start])
		return a[sum][parts][start];

	int total = 0;
	for (int i = start; i <= sum; i++)
	{
		total += get_ways(sum - i, parts - 1, i);
	}

	done[sum][parts][start] = 1;
	a[sum][parts][start] = total;

	return total;
}

int main()
{
	//cout << sizeof(a) + sizeof(done) << "\n";
	int n, k;
	cin >> n >> k;

	cout << get_ways(n, k, 1) << "\n";

	system("pause");
}