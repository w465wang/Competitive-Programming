/*
Peg
Date Started: 2017/08/06, Date Finished: 2017/08/06
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string check(string a, string b)
{
	if (a.size() > b.size())
		return "great";
	else if (a.size() < b.size())
		return "less";
	else if (a == b)
		return "equal";
	else if (a.size() == b.size())
	{
		if (a < b)
			return "less";
		else
			return "great";
	}
}

int main()
{
	int n;
	string a, b, c;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		c = check(a, b);

		if (c == "great")
		{
			int diff = a.size() - b.size();
			string div = "";

			for (int i1 = diff; i1 >= 0; i1--)
			{
				char count = '0';
				string copyB = b;
				copyB.insert(copyB.end(), i1, '0');

				c = check(a, copyB);
				while (c == "great" || c == "equal")
				{
					int lenA = a.size();
					int lenB = copyB.size();
					int it = lenA - lenB;

					for (int i2 = 0; i2 < it; i2++)
						copyB.insert(copyB.begin(), '0');

					string aNew = "";

					int take = 0;
					char add;
					for (int j = lenA - 1; j >= 0; j--)
					{
						if (a[j] - copyB[j] - take >= 0)
						{
							add = '0' + a[j] - copyB[j] - take;
							take = 0;
						}
						else
						{
							add = '0' + a[j] - copyB[j] + 10 - take;
							take = 1;
						}

						aNew.insert(aNew.begin(), add);
					}

					a = aNew;
					a.erase(0, a.find_first_not_of('0'));
					copyB.erase(0, copyB.find_first_not_of('0'));
					count++;

					c = check(a, copyB);
				}

				div.push_back(count);
			}

			div.erase(0, div.find_first_not_of('0'));
			a.erase(0, a.find_first_not_of('0'));
			if (a == "")
				a = "0";

			cout << div << "\n";
			cout << a << "\n";
		}
		else if (c == "less")
		{
			cout << "0\n";
			cout << a << "\n";
		}
		else if (c == "equal")
		{
			cout << "1\n";
			cout << "0\n";
		}
		
		cout << "\n";
	}

	system("pause");
}