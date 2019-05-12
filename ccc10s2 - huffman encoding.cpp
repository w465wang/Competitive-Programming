/*
PEG
Date Started: 2017/07/26, Date Finished: 2017/07/26
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int k;
	cin >> k;
	map<string, string> conv;

	string c, n;
	while (k--)
	{
		cin >> c >> n;
		conv[n] = c;
	}

	string code;
	cin >> code;
	int len = code.size();
	string part = "";

	for (int i = 0; i < len; i++)
	{
		part += code[i];
		
		if (conv.find(part) != conv.end())
		{
			cout << conv[part];
			part = "";
		}
	}

	cout << "\n";

	system("pause");
}
