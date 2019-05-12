/*
PEG
Date Started: 2017/07/22, Date Finished: 2017/08/03
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int g, p, gi;
	cin >> g >> p;
	vector<int> gates(g, 0);
	int count = 0;

	for (int i = 0; i < p; i++)
	{
		scanf_s("%d", &gi);
		if (gates[gi - 1] == 0)
		{
			gates[gi - 1] = 1;
			count++;
		}
		else
		{
			int low = lower_bound(gates.begin(), gates.begin() + gi, 1) - gates.begin() - 1;

			if (low < 0)
			{
				i = p;
			}
			else
			{
				gates[low] = 1;
				count++;
			}
		}
	}
    
    cout << count << "\n";

	system("pause");
}
