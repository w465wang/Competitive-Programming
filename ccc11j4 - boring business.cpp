/*
PEG
Date Started: 2017/07/08, Date Finished: 2017/07/09
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

bool check(set<pair<int, int>> tunnel, pair<int, int> temp)
{
	bool danger = false;

	const bool found = tunnel.find(temp) != tunnel.end();
	if (found == true)
	{
		danger = true;
	}

	return danger;
}

int main()
{
	char dir;
	int len;

	string safe = "safe";
	bool danger = false;

	set<pair<int, int>> tunnel;

	pair<int, int> pos;
	pos.first = 0;
	pos.second = -1;
	pair<int, int> temp;

	string input = "d2r3d2r2u2r2d4l8u2";
	int it = 0;
	dir = input[it];
	string num(1, input[it+1]);
	len = stoi(num);

	while (dir != 'q' && safe == "safe")
	{
		if (dir == 'd')
		{
			temp.first = pos.first;
			for (int i = 1; i < len + 1; i++)
			{
				temp.second = pos.second - i;
				danger = check(tunnel, temp);
				if (danger == true)
				{
					safe = "DANGER";
				}
				tunnel.insert(temp);
			}
		}
		else if (dir == 'u')
		{
			temp.first = pos.first;
			for (int i1 = 1; i1 < len + 1; i1++)
			{
				temp.second = pos.second + i1;
				danger = check(tunnel, temp);
				if (danger == true)
				{
					safe = "DANGER";
				}
				tunnel.insert(temp);
			}
		}
		else if (dir == 'l')
		{
			temp.second = pos.second;
			for (int i2 = 1; i2 < len + 1; i2++)
			{
				temp.first = pos.first - i2;
				danger = check(tunnel, temp);
				if (danger == true)
				{
					safe = "DANGER";
				}
				tunnel.insert(temp);
			}
		}
		else if (dir == 'r')
		{
			temp.second = pos.second;
			for (int i3 = 1; i3 < len + 1; i3++)
			{
				temp.first = pos.first + i3;
				danger = check(tunnel, temp);
				if (danger == true)
				{
					safe = "DANGER";
				}
				tunnel.insert(temp);
			}
		}

		pos.first = temp.first;
		pos.second = temp.second;

		it += 2;
		if (it > 17)
		{
			if (it > 18)
			{
				cout << temp.first << " " << temp.second << " " << safe << "\n";
			}
			cin >> dir >> len;
		}
		else 
		{
			dir = input[it];
			string num(1, input[it + 1]);
			len = stoi(num);
		}
	}

	system("pause");
}