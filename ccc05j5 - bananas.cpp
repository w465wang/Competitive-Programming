/*
Peg
Date Started: 2017/08/10, Date Finished: 2017/08/10
*/

#include <iostream>
#include <string>
using namespace std;

void monkey(string w)
{
	if (w.size() == 1 && w == "A")
	{
		cout << "YES\n";
	}
	else if (w[0] == 'A')
	{
		if (w[1] == 'N')
		{
			w.erase(0, 2);
			monkey(w);
		}
		else
		{
			cout << "NO\n";
		}
	}
	else if (w[0] == 'B')
	{
		int sLast = w.find_last_of('S');

		if (sLast != w.size() - 1 && w[sLast + 1] != 'N')
		{
			cout << "NO\n";
		}
		else
		{
			int bFirst = w.find_first_of('B', 1);
			int sFirst = w.find_first_of('S');

			if (sFirst == -1)
			{
				cout << "NO\n";
			}
			else
			{
				if (bFirst == -1)
				{
					bFirst = sFirst + 1;
				}

				if (bFirst < sFirst)
				{
					int b = 2;
					int s = 0;
					int it = bFirst + 1;

					while (b != s)
					{
						if (w[it] == 'B')
							b++;
						else if (w[it] == 'S')
							s++;

						it++;
					}

					w.erase(w.begin() + it - 1);
				}
				else
				{
					w.erase(w.begin() + sFirst);
				}

				w.erase(w.begin());
				monkey(w);
			}
		}
	}
	else
	{
		cout << "NO\n";
	}
}

int main()
{
	string w;
	cin >> w;

	while (w != "X")
	{
		monkey(w);

		cin >> w;
	}

	system("pause");
}