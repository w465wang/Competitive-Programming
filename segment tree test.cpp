/*
PEG
Date Started: 2017/10/04, Date Finished: 2017/10/05
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[100001] = {}, c[100001] = {}, tree[500001] = {};

void init(int low, int high, int pos)
{
	if (low == high)
	{
		tree[pos] = a[low];
		c[low] = pos;
		return;
	}

	int mid = (low + high) / 2;

	init(low, mid, 2 * pos + 1);
	init(mid + 1, high, 2 * pos + 2);

	tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
}

int query(int qLow, int qHigh, int low, int high, int pos)
{
	if (qLow <= low && qHigh >= high) //total overlap
		return tree[pos];

	if (qLow > high || qHigh < low) //no overlap
		return 1000001;

	int mid = (low + high) / 2;

	return min(query(qLow, qHigh, low, mid, 2 * pos + 1), query(qLow, qHigh, mid + 1, high, 2 * pos + 2));
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	init(0, n - 1, 0);

	char q;
	for (int i = 0, l, r; i < m; i++)
	{
		cin >> q;
		cin >> l >> r;

		if (q == 'Q')
		{
			printf("%d\n", query(l, r, 0, n - 1, 0));
		}
		else if (q == 'M')
		{
			a[l] = r;

			int it = c[l];
			tree[it] = r;

			while (it != 0)
			{
				if (it % 2 == 0)
					it = (it - 2) / 2;
				else
					it = (it - 1) / 2;

				tree[it] = min(tree[2 * it + 1], tree[2 * it + 2]);
			}
		}
	}

	system("pause");
}