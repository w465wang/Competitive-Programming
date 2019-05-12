/*
PEG
Date Started: 2017/07/05, Date Finished: 2017/07/05
*/

#include <iostream>
#include <string>
using namespace std;

string star(int space, int j, string line)
{
	for (int k = space + 1; k < j; k++)
	{
		line[k] = '*';
	}

	return line;
}


int main()
{
	int n;
	string line;
	cin >> n;
	
	for (int i = 0; i <= n; i++)
	{
		getline(cin, line);
		int len = line.length();
		int space = -1;

		for (int j = 0; j < len; j++)
		{
			if (line[j] == ' ')
			{
				if (j - space == 5)
				{
					line = star(space, j, line);
				}
				space = j;
			}
			else if (j == len - 1 && space == j - 4)
			{
				line[j] = '*';
				line = star(space, j, line);
			}
		}

		cout << line << "\n";
	}

	system("pause");
}
