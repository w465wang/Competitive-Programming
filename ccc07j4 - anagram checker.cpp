/*
PEG
Date Started: 2017/07/03, Date Finished: 2017/07/03
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b, anagram;
	getline(cin, a);
	getline(cin, b);

	anagram = "Yes";
	for (int i = 0; i < a.length(); i++)
	{
		int found = b.find(a[i], 0);
		//cout << found << "\n";
		if (found == -1)
		{
			anagram = "No";
		}
		else if (found != -1)
		{
			b[found] = ' ';
		}
	}

	if (anagram == "Yes")
	{
		cout << "Is an anagram.\n";
	}
	else if (anagram == "No")
	{
		cout << "Is not an anagram.\n";
	}

	system("pause");
}


