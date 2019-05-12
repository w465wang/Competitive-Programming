/*
PEG
Date Started: 2017/08/12, Date Finished: 2017/08/13
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int num, n, m, start, len;
vector<int> primes(5000001, 0);
vector<int> divi;

void init(int it, int stop)
{
	if (it > stop)
		divi.push_back(num);
	else if (num % it == 0)
		return;
	else
		init(it + 1, stop);
}

void sieve(int it, int stop)
{
	if (it == len || divi[it] > stop)
		for (int p = 0; p <= m - n; p++)
		{
			if (primes[p] == 0)
				printf("%d\n", p + n);
		}
	else
	{ 
		if (divi[it] < n)
		{
			if (n % divi[it] != 0)
				start = n + divi[it] - n % divi[it];
			else
				start = n;
		}
		else
			start = divi[it] * 2;

		for (int j = start; j <= m; j += divi[it])
			primes[j - n] = 1;

		sieve(it + 1, stop);
	}
}

int main()
{
	cin >> n >> m;

	for (int i1 = 2; i1 <= (int)sqrt(1000000000); i1++)
	{
		num = i1;

		init(2, (int)sqrt(num));
	}

	len = divi.size();

	if (n == 1)
		n = 2;

	sieve(0, (int)sqrt(m));

	system("pause");
}
