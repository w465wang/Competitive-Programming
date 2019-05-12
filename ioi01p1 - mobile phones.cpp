/*
PEG
Date Started: 2017/09/15, Date Finished: 2017/10/09
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, s, tree[1025][1025] = {};

void update(int x, int y, int a)
{
	while (x <= s) 
	{
		int y1 = y;
		while (y1 <= s) 
		{
			tree[x][y1] += a;
			y1 += (y1 & -y1);
		}

		x += (x & -x);
	}
}

int add(int x, int y)
{
	int sum = 0;
	
	while (x > 0)
	{
		int y1 = y;
		while (y1 > 0)
		{
			sum += tree[x][y1];
			y1 -= (y1 & -y1);
		}

		x -= (x & -x);
	}

	return sum;
}

int main()
{
	scanf_s("%d%d%d", &n, &s, &n);

	while (n != 3)
	{
		if (n == 1)
		{
			int x, y, a;
			scanf_s("%d%d%d", &x, &y, &a);

			update(x + 1, y + 1, a);
		}
		else if (n == 2)
		{
			int l, r, b, t;
			scanf_s("%d%d%d%d", &l, &r, &b, &t);

			printf("%d\n", add(b + 1, t + 1) - add(b + 1, r) - add(l, t + 1) + add(l, r));
		}

		scanf_s("%d", &n);
	}

	system("pause");
}