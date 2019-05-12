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
	int n, one;
	cin >> n;
	n++;
	bool same = true;

	while (same == true)
	{
		one = 0;
		string s = to_string(n);
		int len = s.length();

		for (int i = 0; i < len; i++)
		{
			char letter = s[i];
			int c = count(s.begin(), s.end(), letter);

			if (c == 1)
			{
				one++;
			}
		}

		if (one == len)
		{
			same = false;
		}
		if (same == true)
		{
			n++;
		}
	}
	
	cout << n << "\n";
	
	system("pause");
}


