/*
PEG
Date Started: 2017/08/03, Date Finished: 2017/08/24
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int len, t, temp;
vector<vi> points = { { 0,0,0,0,0 } };
vector<pii> games = { { 1,2 },{ 1,3 },{ 1,4 },{ 2,3 },{ 2,4 },{ 3,4 } };

void add(vi temp, pii game, int p1, int p2)
{
	temp[game.first] += p1;
	temp[game.second] += p2;

	points.push_back(temp);
}

void outcome()
{
	len = points.size();

	if (games.size() == 0)
	{
		int count = 0;
		
		for (int k = 0; k < len; k++)
		{
			temp = points[k][t];

			sort(points[k].begin(), points[k].end());

			if (temp == points[k][4] && temp > points[k][3])
				count++;
		}

		cout << count << "\n";
	}
	else
	{
		for (int j = 0; j < len; j++)
		{
			add(points[0], games[0], 3, 0);
			add(points[0], games[0], 1, 1);
			add(points[0], games[0], 0, 3);

			points.erase(points.begin());
		}

		games.erase(games.begin());
		outcome();
	}
}

int main()
{
	int g, a, b, sa, sb;
	cin >> t >> g;

	for (int i = 0; i < g; i++)
	{
		cin >> a >> b >> sa >> sb;

		if (sa > sb) 
			points[0][a] += 3;
		else if (sa < sb) 
			points[0][b] += 3;
		else if (sa == sb) {
			points[0][a] += 1;
			points[0][b] += 1;
		}

		pii lol = { a,b };
		int fnd = find(games.begin(), games.end(), lol) - games.begin();
		games.erase(games.begin() + fnd);
	}

	outcome();

	system("pause");
}