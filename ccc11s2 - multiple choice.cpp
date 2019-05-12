/*
PEG
Date Started: 2017/07/04, Date Finished: 2017/07/04
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, count;
	string ques, ans;
	char a, b;
	cin >> n;
	ques = "";
	count = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		ques.push_back(a);
	}

	for (int j = 0; j < n; j++)
	{
		cin >> b;
		if (b == ques[j])
		{
			count++;
		}
	}

	cout << count << "\n";

	system("pause");
}

