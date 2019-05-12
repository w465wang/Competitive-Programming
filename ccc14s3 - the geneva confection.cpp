/*
PEG
Date Started: 2017/07/19, Date Finished: 2017/07/19
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t, n, car;
	cin >> t;

	while (t--)
	{
		vector<int> top;
		vector<int> branch;
		vector<int> lake;
		int num = 1;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> car;
			top.push_back(car);
		}

		bool stuck = false;
		while (num != n && stuck == false)
		{
			bool t = false;
			bool b = false;
			if (top.size() > 0)
				t = true;
			if (branch.size() > 0)
				b = true;
			int lenT = top.size() - 1;
			int lenB = branch.size() - 1;

			if (t == true)
			{
				if (top[lenT] == num)
				{
					lake.push_back(top[lenT]);
					top.erase(top.begin() + lenT);
				}
				else if (top[lenT] != num)
				{
					if (b == true)
					{
						if (branch[lenB] == num)
						{
							lake.push_back(branch[lenB]);
							branch.erase(branch.begin() + lenB);
						}
					}

					if (branch.size() != lenB)
					{
						branch.push_back(top[lenT]);
						top.erase(top.begin() + lenT);
					}
				}
			}
			else if (t == false)
			{
				if (branch[lenB] == num)
				{
					lake.push_back(branch[lenB]);
					branch.erase(branch.begin() + lenB);
				}
				else if (branch[lenB] != num)
				{
					stuck = true;
				}
			}

			if (lake.size() == num)
			{
				num++;
			}
		}

		if (num == n)
		{
			cout << "Y" << "\n";
		}
		else if (stuck == true)
		{
			cout << "N" << "\n";
		}
	}

	system("pause");
}