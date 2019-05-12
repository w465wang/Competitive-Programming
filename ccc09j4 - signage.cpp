/*
PEG
Date Started: 2017/07/16, Date Finished: 2017/07/17
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int w;
	cin >> w;

	vector<string> words = { "WELCOME","TO","CCC","GOOD","LUCK","TODAY" };

	while (words.size() > 0)
	{
		int size = words.size();
		int sum = words[0].size();
		vector<int> letters = { sum };

		for (int l = 1; l < size; l++)
		{
			sum += words[l].size() + 1;
			letters.push_back(sum);
		}

		vector<string> line;

		int len = 0;
		int it = 0;

		while (it < size && letters[it] <= w)
		{
			len = letters[it];
			line.push_back(words[it]);
			it++;
		}

		int gaps = line.size() - 1;
		int dots = w - len + gaps;
		vector<int> space(gaps, 0);

		if (gaps > 0)
		{
			for (int i = 0; i < dots; i++)
			{
				space[i % gaps] += 1;
			}

			space.push_back(0);
		}
		else if (gaps == 0)
		{
			space = { dots };
		}

		for (int j = 0; j < gaps + 1; j++)
		{
			cout << line[j];

			for (int k = 0; k < space[j]; k++)
			{
				cout << ".";
			}

			words.erase(words.begin());
		}

		cout << endl;
	}

	system("pause");
}