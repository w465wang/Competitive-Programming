/*
PEG
Date Started: 2017/07/19, Date Finished: 2017/10/09
*/

#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int main()
{
	int n, temp, a[21];
	scanf("%d", &n);

	while (n)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			a[i - 1] = a[i] - a[i - 1];
		}

		if (n == 1)
			printf("0\n");
		else
		{
			int len = 1, start = 1;
			bool lol = false;
			for (int i = 2; i < n; i++)
			{
				if (a[i] == a[start])
				{
					if (lol = false)
						start = i + 1;
					else
						start++;

					lol = true;
				}
				else
				{
					if (lol = true)
					{
						len = i;
						start = 1;
						lol = false;
					}
					else
						len++;
				}
			}

			printf("%d\n", len);
		}

		scanf("%d", &n);
	}

	system("pause");
}