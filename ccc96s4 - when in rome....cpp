/*
PEG
Date Started: 2017/07/19, Date Finished: 2017/07/19
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	map<char, int> letter_to_num = { { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };
	map<int, char> num_to_letter = { { 1, 'I' },{ 5, 'V' },{ 10, 'X' },{ 50, 'L' },{ 100, 'C' },{ 500, 'D' },{ 1000, 'M' } };
	map<char, string> left = { { 'I', "VX" },{ 'X', "LC" },{ 'C', "DM" } };

	int n;
	cin >> n;
	string line;

	while (n--)
	{
		vector<string> roman;

		cin >> line;

		int plus = line.find('+', 0);
		int equal = line.find('=', 0);
		
		roman.push_back(line.substr(0, plus));
		roman.push_back(line.substr(plus + 1, equal - plus - 1));

		int total = 0;
		for (int i = 0; i < 2; i++)
		{
			int len = roman[i].size();

			for (int j = 0; j < len; j++)
			{
				total += letter_to_num[roman[i][j]];
				if (left.find(roman[i][j]) != left.end() && j <= len - 2)
				{
					if (left[roman[i][j]].find(roman[i][j + 1], 0) != -1)
					{
						total -= 2 * letter_to_num[roman[i][j]];
					}
				}
			}
		}

		string add = "";
		if (total > 1000)
		{
			add = "CONCORDIA CUM VERITATE";
		}
		else
		{
			vector<int> parts;
			while (total)
			{
				parts.push_back(total % 10);
				total /= 10;
			}

			int lenT = parts.size();

			for (int k = 0; k < lenT; k++)
			{
				if (parts[k] < 4)
				{
					for (int k1 = 0; k1 < parts[k]; k1++)
					{
						add += num_to_letter[pow(10.0, k)];
					}
				}
				else if (parts[k] == 4)
				{
					add += num_to_letter[5 * pow(10.0, k)];
					add += num_to_letter[pow(10.0, k)];
				}
				else if (parts[k] > 4 && parts[k] < 9)
				{
					for (int k2 = 0; k2 < parts[k] - 5; k2++)
					{
						add += num_to_letter[pow(10.0, k)];
					}

					add += num_to_letter[5 * pow(10.0, k)];
				}
				else if (parts[k] == 9)
				{
					add += num_to_letter[10 * pow(10.0, k)];
					add += num_to_letter[pow(10.0, k)];
				}
			}

			reverse(add.begin(), add.end());
		}
		
		cout << line << add << "\n";
	}

	system("pause");
}