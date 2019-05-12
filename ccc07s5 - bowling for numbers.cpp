/*
PEG
Date Started: 2017/10/02, Date Finished: 2017/10/04
*/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int t, n, k, w, pin[30001] = {}, start[30001] = {}, check[30001][501] = {};

int main()
{
	scanf_s("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf_s("%d%d%d", &n, &k, &w);

		for (int j = 1; j <= w; j++)
		{
			scanf_s("%d", &pin[j]);
			start[1] += pin[j];

			check[1][1] = start[1];
		}

		for (int j = w + 1; j <= n; j++)
		{
			scanf_s("%d", &pin[j]);
			start[j - w + 1] = start[j - w] + pin[j] - pin[j - w];

			check[j - w + 1][1] = max(start[j - w + 1], check[j - w][1]);
		}

		int ind = 1;
		for (int j = w + 1; j <= n - w + 1; j++)
		{
			if (ind <= k)
			{
				if (w != 1 && j % w == 1)
					ind++;
				else if (w == 1)
					ind++;
			}
			else
				j = n;

			for (int l = 2; l <= ind; l++)
			{
				check[j][l] = max(start[j] + check[j - w][l - 1], check[j - 1][l]);
			}
		}

		printf("%d\n", check[n - w + 1][k]);
		memset(check, 0, sizeof(check[30001][501]) * 30001 * 501);
		memset(pin, 0, sizeof(pin[30001]) * 30001);
		memset(start, 0, sizeof(start[30001]) * 30001);
	}

	system("pause");
}
