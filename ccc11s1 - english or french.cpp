/*
PEG
Date Started: 2017/07/04, Date Finished: 2017/07/04
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, t, s, tCaps, sCaps;
	string line;
	cin >> n;
	t = 0;
	s = 0;
	tCaps = 0;
	sCaps = 0;

	for (int i = 0; i <= n; i++)
	{
		getline(cin, line);
		t += count(line.begin(), line.end(), 't');
		s += count(line.begin(), line.end(), 's');
		tCaps += count(line.begin(), line.end(), 'T');
		sCaps += count(line.begin(), line.end(), 'S');
	}

	if (t + tCaps > s + sCaps)
	{
		cout << "English\n";
	}
	else if (t + tCaps <= s + sCaps)
	{
		cout << "French\n";
	}

	system("pause");
}

