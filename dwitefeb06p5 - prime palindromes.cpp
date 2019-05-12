/*
PEG
Date Started: 2017/08/14, Date Finished: 2017/08/14
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int num, n, m, start, len, cnt, siz;
vector<int> primes(1000000, 0);
vector<int> divi;

void palin(int p)
{
	vector<int> digits;
	while (p != 0)
	{
		digits.push_back(p % 10);
		p /= 10;
	}

	bool pal = true;
	siz = digits.size();
	for (int c = 0; c < siz / 2; c++)
	{
		if (digits[c] != digits[siz - c - 1])
			pal = false;
	}

	if (pal == true)
		cnt++;
}

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
	{
		for (int p = n; p <= m; p++)
		{
			if (primes[p] == 0)
				palin(p);
		}
		
		cout << cnt << "\n";
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
			primes[j] = 1;

		sieve(it + 1, stop);
	}
}

int main()
{
	for (int z = 0; z < 5; z++)
	{
		cnt = 0;
		cin >> n >> m;

		for (int i1 = 2; i1 <= (int)sqrt(999999); i1++)
		{
			num = i1;

			init(2, (int)sqrt(num));
		}

		len = divi.size();

		if (n == 1)
			n = 2;

		sieve(0, (int)sqrt(m));
	}

	system("pause");
}
