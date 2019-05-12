/*
PEG
Date Started: 2017/09/18, Date Finished: 2017/09/27
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, a[5001] = {}, c[5001] = {};

int main()
{
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);

	for (int i = 0; i < n; i++)
	{
		c[i] = 1;

		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
				c[i] = max(c[i], c[j] + 1);
		}
	}

	sort(begin(c), begin(c) + n);
	cout << c[n - 1] << "\n";

	system("pause");
}