/*
PEG
Date Started: 2017/09/16, Date Finished: 2017/09/16
*/

#include <iostream>
#include <algorithm>
using namespace std;

int t, s, a[100001] = {}, b[100001] = {}, arr[100001] = {};

void update(int it, int w)
{
	while (it <= 100001)
	{
		arr[it] += w;
		it += (it & -it);
	}
}

int add(int it)
{
	int sum = 0;
	while (it > 0)
	{
		sum += arr[it];
		it -= (it & -it);
	}

	return sum;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> s;
		a[i] = s;
		b[i] = s;
	}

	sort(begin(b), begin(b) + t);

	double tot = 0.0;
	for (int i = 0; i < t; i++)
	{
		a[i] = lower_bound(begin(b), begin(b) + t, a[i]) - begin(b) + 1;
		update(a[i], 1);

		tot += i - add(a[i]) + 2;
	}

	printf("%0.2f\n", tot / t);

	system("pause");
}
