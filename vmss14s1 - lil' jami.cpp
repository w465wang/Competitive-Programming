/*
PEG
Date Started: 2017/07/27, Date Finished: 2017/07/27 
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k, ki, q, a, b;
	cin >> n >> k;
	vector<int> cup(n, 0);

	for (int i = 0; i < k; i++)
	{
		scanf_s("%d", &ki);
		cup[ki]++;
	}

	for (int j = 1; j < n; j++)
	{
		cup[j] += cup[j - 1];
	}

	cin >> q;
	while (q--)
	{
		scanf_s("%d", &a);
		scanf_s("%d", &b);

		if (a == 0)
		{
			printf("%d\n", cup[b]);
		}
		else
		{
			printf("%d\n", cup[b] - cup[a - 1]);
		}
	}

	system("pause");
}

