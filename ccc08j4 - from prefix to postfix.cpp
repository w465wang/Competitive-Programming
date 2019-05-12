/*
Peg
Date Started: 2017/08/03, Date Finished: 2017/08/06
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string line;
	getline(cin, line);

	while (line != "0")
	{
		string post = "";

		int len = line.size();
		int pos;

		for (int i = len - 1; i >= 0; i -= 2)
		{
			if (line[i] == '+' || line[i] == '-')
			{
				if (post == "" || i == pos - 6)
				{
					post.insert(post.begin(), line[i + 2]);
					post.insert(post.begin() + 1, ' ');
					post.insert(post.begin() + 2, line[i + 4]);
					post.insert(post.begin() + 3, ' ');
					post.insert(post.begin() + 4, line[i]);
					post.insert(post.begin() + 5, ' ');

					line.erase(i, 6);
				}
				else
				{
					if (i == pos - 4)
					{
						post.insert(post.begin(), ' ');
						post.insert(post.begin(), line[i + 2]);
						post.push_back(line[i]);
						post.push_back(' ');
					}
					else if (i == pos - 2)
					{
						if (i + 2 < line.size())
						{
							post.push_back(line[i + 2]);
							post.push_back(' ');
						}

						post.push_back(line[i]);
						post.push_back(' ');
					}

					line.erase(i, 4);
				}

				pos = i;
			}
		}

		cout << post << "\n";

		getline(cin, line);
	}

	system("pause");
}