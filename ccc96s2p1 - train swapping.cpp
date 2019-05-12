/*
PEG
Date Started: 2017/07/11, Date Finished: 2017/07/11
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sort(vector<int> list)
{
	int len = list.size();
	int count = 0;

	for (int j = 0; j < len; j++)
	{
		for (int k = 0; k < len - 1; k++)
		{
			if (list[k] > list[k + 1])
			{
				int temp = list[k];
				list[k] = list[k + 1];
				list[k + 1] = temp;
				count++;
			}
		}
	}

	cout << "Optimal train swapping takes " << count << " swap(s).\n";
}

int main()
{
	int n, l;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		vector<int> train;
		int car;

		cin >> l;

		for (int i1 = 0; i1 < l; i1++)
		{
			cin >> car;
			train.push_back(car);
		}

		sort(train);
	}

	system("pause");
}