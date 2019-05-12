/*
Peg
Date Started: 2017/08/04, Date Finished: 2017/08/04
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> breakdown(long long x)
{
	vector<int> r;

	while (x >= 5)
	{
		int mod = x % 5;

		if (mod == 3)
			mod = 1;
		else if (mod == 4)
			mod = 0;

		r.insert(r.begin(), mod);
		x /= 5;
	}

	if (x == 3)
		x = 1;
	else if (x == 4)
		x = 0;

	r.insert(r.begin(), x);

	return r;
}

void height(vector<int> r, long long h, long long y)
{
	if (r.size() == 0)
	{
		if (y < h)
			cout << "crystal\n";
		else
			cout << "empty\n";
	}
	else if (h == 0)
	{
		h = r[0];
		r.erase(r.begin());
		height(r, h, y);
	}
	else
	{
		h *= 5;

		if (r[0] == 1)
			h += 1;
		else if (r[0] == 2)
			h += 2;

		r.erase(r.begin());
		height(r, h, y);
	}
}

int main()
{
	int t, m;
	long long x, y;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int pow = 1;
		vector<int> remain;

		cin >> m >> x >> y;

		for (int i = 0; i < m - 1; i++)
		{
			pow *= 5;
		}
		
		if (x < pow || x >= 4 * pow)
		{
			cout << "empty\n";
		}
		else
		{
			remain = breakdown(x);

			height(remain, 0, y);
		}
	}

	system("pause");
}