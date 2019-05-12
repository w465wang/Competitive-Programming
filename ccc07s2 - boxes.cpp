/*
PEG
Date Started: 2017/07/11, Date Finished: 2017/07/11
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> sort(vector<int> list)
{
	int len = list.size();
	for (int j = 0; j < len; j++)
	{
		for (int k = 0; k < len - 1; k++)
		{
			if (list[k] > list[k + 1])
			{
				int temp = list[k];
				list[k] = list[k + 1];
				list[k + 1] = temp;
			}
		}
	}

	return list;
}

int main()
{
	int n, m;
	int max = 0;
	vector<vector<int>> box;
	vector<int> vol;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> standard;

		int a, b, c;
		cin >> a >> b >> c;

		standard.push_back(a);
		standard.push_back(b);
		standard.push_back(c);

		standard = sort(standard);

		box.push_back(standard);
		vol.push_back(a * b * c);
		if (a * b * c > max)
		{
			max = a * b * c;
		}
	}

	cin >> m;
	while (m--)
	{
		vector<int> pack;

		int d, e, f;
		cin >> d >> e >> f;

		pack.push_back(d);
		pack.push_back(e);
		pack.push_back(f);

		pack = sort(pack);

		int small = max + 1;
		for (int i1 = 0; i1 < n; i1++)
		{
			if (pack[0] <= box[i1][0] && pack[1] <= box[i1][1] && pack[2] <= box[i1][2])
			{
				if (vol[i1] < small)
				{
					small = vol[i1];
				}
			}
		}

		if (small < max + 1)
		{
			cout << small << "\n";
		}
		else
		{
			cout << "Item does not fit.\n";
		}
	}

	system("pause");
}