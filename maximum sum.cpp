/*
PEG
Date Started: 2017/08/19, Date Finished: 2017/08/19
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, num;
	cin >> n;
	vector<int> mem;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);

		if (i < 2)
			mem.push_back(num);
		else
		{
			if (num + mem[i - 2] > mem[i - 1])
				mem.push_back(num + mem[i - 2]);
			else
				mem.push_back(mem[i - 1]);
		}
	}

	cout << mem.back() << "\n";
	system("pause");
}