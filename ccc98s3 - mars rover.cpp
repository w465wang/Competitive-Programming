/*
PEG
Date Started: 2017/07/16, Date Finished: 2017/07/16
*/

#include <iostream>
using namespace std;
//direction: '0up', '1right', '2down', '3left'
int main()
{
	int n, comm, dist;
	cin >> n;
	pair<int, int> start = { 0, 0 };

	while (n--)
	{
		pair<int, int> rover = { 0, 0 };
		int face = 0;

		cin >> comm;
		while (comm != 0)
		{
			if (comm == 1)
			{
				cin >> comm;
				if (face == 0)
				{
					rover.second += comm;
				}
				else if (face == 1)
				{
					rover.first += comm;
				}
				else if (face == 2)
				{
					rover.second -= comm;
				}
				else if (face == 3)
				{
					rover.first -= comm;
				}
			}
			else if (comm == 2)
			{
				face = (face + 1) % 4;
			}
			else if (comm == 3)
			{
				face = (face + 3) % 4;
			}

			cin >> comm;
		}

		dist = abs(rover.first) + abs(rover.second);
		cout << "Distance is " << dist << "\n";

		if (dist > 0)
		{
			while (rover != start)
			{
				if (face == 0)
				{
					if (rover.second < 0)
					{
						cout << 1 << "\n";
						cout << abs(rover.second) << "\n";
						rover.second = 0;
					}
					else if (rover.second >= 0)
					{
						if (rover.first < 0)
						{
							cout << 2 << "\n";
							face = 1;
						}
						else if (rover.first > 0)
						{
							cout << 3 << "\n";
							face = 3;
						}
						else if (rover.first == 0)
						{
							cout << 2 << "\n";
							cout << 2 << "\n";
							face = 2;
						}
					}
				}
				else if (face == 1)
				{
					if (rover.first < 0)
					{
						cout << 1 << "\n";
						cout << abs(rover.first) << "\n";
						rover.first = 0;
					}
					else if (rover.first >= 0)
					{
						if (rover.second < 0)
						{
							cout << 3 << "\n";
							face = 0;
						}
						else if (rover.second > 0)
						{
							cout << 2 << "\n";
							face = 2;
						}
						else if (rover.second == 0)
						{
							cout << 2 << "\n";
							cout << 2 << "\n";
							face = 3;
						}
					}
				}
				else if (face == 2)
				{
					if (rover.second > 0)
					{
						cout << 1 << "\n";
						cout << abs(rover.second) << "\n";
						rover.second = 0;
					}
					else if (rover.second <= 0)
					{
						if (rover.first < 0)
						{
							cout << 3 << "\n";
							face = 1;
						}
						else if (rover.first > 0)
						{
							cout << 2 << "\n";
							face = 3;
						}
						else if (rover.first == 0)
						{
							cout << 2 << "\n";
							cout << 2 << "\n";
							face = 0;
						}
					}
				}
				else if (face == 3)
				{
					if (rover.first > 0)
					{
						cout << 1 << "\n";
						cout << abs(rover.first) << "\n";
						rover.first = 0;
					}
					else if (rover.first <= 0)
					{
						if (rover.second < 0)
						{
							cout << 2 << "\n";
							face = 0;
						}
						else if (rover.second > 0)
						{
							cout << 3 << "\n";
							face = 2;
						}
						else if (rover.second == 0)
						{
							cout << 2 << "\n";
							cout << 2 << "\n";
							face = 1;
						}
					}
				}
			}
		}

		cout << endl;
	}

	system("pause");
}