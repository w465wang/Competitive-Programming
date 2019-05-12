/*
PEG
Date Started: 2017/07/06, Date Finished: 2017/07/06
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int k;
	string line1, line2, line3;
	cin >> k;
	
	line1 = "";
	for (int i = 0; i < k * 3; i++)
	{
		if (i >= k && i < k * 2)
		{
			line1.push_back('x');
		}
		else
		{
			line1.push_back('*');
		}
	}

	for (int i1 = 0; i1 < k; i1++)
	{
		cout << line1 << "\n";
	}

	line2 = "";
	for (int j = 0; j < k * 3; j++)
	{
		if (j >= k)
		{
			line2.push_back('x');
		}
		else
		{
			line2.push_back(' ');
		}
	}

	for (int j1 = 0; j1 < k; j1++)
	{
		cout << line2 << "\n";
	}

	line3 = "";
	for (int l = 0; l < k * 3; l++)
	{
		if (l >= k && l < k * 2)
		{
			line3.push_back(' ');
		}
		else
		{
			line3.push_back('*');
		}
	}

	for (int l1 = 0; l1 < k; l1++)
	{
		cout << line3 << "\n";
	}

	system("pause");
}
