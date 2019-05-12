/*
PEG
Date Started: 2017/08/12, Date Finished: 2017/08/12
*/

#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int m;

void sieve(int it, int stop, int count)
{
	if (it > stop)
	{
		if (m != 1)
			count++;

		printf("%d\n", count);
	}
	else if (m % it == 0)
	{
		while (m % it == 0)
			m /= it;

		sieve(2, (int)sqrt(m), count + 1);
	}
	else
	{
		sieve(it + 1, stop, count);
	}
}

int main()
{
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		m = i;
		sieve(2, (int)sqrt(m), 0);
	}

	system("pause");
}