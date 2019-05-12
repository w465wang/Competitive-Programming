/*
PEG
Date Started: 2017/07/05, Date Finished: 2017/07/05
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int k, shift;
	string code;
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string msg = "";
	
	cin >> k;
	cin >> code;
	int len = code.length();

	for (int i = 0; i < len; i++)
	{
		shift = 3 * (i + 1) + k;
		int letter = code[i];
		letter -= shift;

		while (letter < 65)
		{
			letter += 26;
		}

		msg.push_back(alpha[letter - 65]);
		
	}

	cout << msg << "\n";

	system("pause");
}

