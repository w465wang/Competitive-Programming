/*
PEG
Date Started: 2017/07/17, Date Finished: 2017/07/17
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b, x, y;
	cin >> a >> b >> x >> y;

	pair<int, int> knight = { a,b };
	pair<int, int> end = { x,y };
	vector<pair<int, int>> coor = { knight };
	
	bool fin = false;
	int count = 0;

	if (knight == end)
	{
		fin = true;
	}

	while (fin == false)
	{
		int len = coor.size();
		for (int i = 0; i < len; i++)
		{
			a = coor[0].first;
			b = coor[0].second;

			if (a + 1 <= 8)
			{
				if (b + 2 <= 8)
				{
					coor.push_back({ a + 1, b + 2 });
				}
				if (b - 2 >= 1)
				{
					coor.push_back({ a + 1, b - 2 });
				}
			}
			if (a + 2 <= 8)
			{
				if (b + 1 <= 8)
				{
					coor.push_back({ a + 2, b + 1 });
				}
				if (b - 1 >= 1)
				{
					coor.push_back({ a + 2, b - 1 });
				}
			}
			if (a - 1 >= 1)
			{
				if (b + 2 <= 8)
				{
					coor.push_back({ a - 1, b + 2 });
				}
				if (b - 2 >= 1)
				{
					coor.push_back({ a - 1, b - 2 });
				}
			}
			if (a - 2 >= 1)
			{
				if (b + 1 <= 8)
				{
					coor.push_back({ a - 2, b + 1 });
				}
				if (b - 1 >= 1)
				{
					coor.push_back({ a - 2, b - 1 });
				}
			}

			coor.erase(coor.begin());
		}

		len = coor.size();
		for (int j = 0; j < len; j++)
		{
			if (coor[j] == end)
			{
				fin = true;
				break;
			}
		}

		count += 1;
	}

	cout << count << "\n";

	system("pause");
}