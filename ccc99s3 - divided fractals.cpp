/*
Peg
Date Started: 2017/08/10, Date Finished: 2017/08/10
*/

#include <iostream>
#include <vector>
using namespace std;

int pow(int n)
{
	int num = 1;
	for (int j = 0; j < n; j++)
	{
		num *= 3;
	}

	return num;
}

void rem(vector<vector<char>> frac, int len, int copy)
{
	if (len == 1)
	{
		int b, t, l, r;
		cin >> b >> t >> l >> r;

		for (int i1 = t - 1; i1 >= b - 1; i1--)
		{
			for (int i2 = l - 1; i2 < r; i2++)
				printf("%c ", frac[i1][i2]);

			cout << "\n";
		}
	}
	else
	{
		for (int k = 0; k < copy; k++)
		{
			for (int k1 = 0; k1 < copy; k1++)
			{
				if (k % len >= len / 3 && k % len < 2 * len / 3 && k1 % len >= len / 3 && k1 % len < 2 * len / 3)
					frac[k][k1] = ' ';
			}
		}

		rem(frac, len / 3, copy);
	}
}

int main()
{
	int d, n;
	cin >> d;

	for (int i = 0; i < d; i++)
	{
		cin >> n;

		int len = pow(n);
		vector<char> row(len, '*');
		vector<vector<char>> frac(len, row);
		
		rem(frac, len, len);
	}

	system("pause");
}