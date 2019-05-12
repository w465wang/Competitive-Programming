/*
Peg
Date Started: 2017/08/01, Date Finished: 2017/08/09
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void patt(vector<int> pos, vector<int> fin, string base, int n, int k)
{
	if (pos == fin)
	{
		for (int j = 0; j < k; j++)
		{
			base[pos[j]] = '1';
		}

		cout << base << "\n";
	}
	else
	{
		string copy = base;
		for (int j = 0; j < k; j++)
		{
			copy[pos[j]] = '1';
		}

		cout << copy << "\n";

		if (pos[k - 1] == fin[k - 1])
		{
			int it = k - 2;
			while (pos[it] == fin[it])
			{
				it--;
			}

			pos[it]++;
			for (int j1 = it + 1; j1 < k; j1++)
			{
				pos[j1] = pos[j1 - 1] + 1;
			}
		}
		else
		{
			pos[k - 1]++;
		}

		patt(pos, fin, base, n, k);
	}
}

int main()
{
    int a, n, k;
    cin >> a;
    
    for (int i = 0; i < a; i++)
    {
        scanf_s("%d", &n);
        scanf_s("%d", &k);

		vector<int> pos;
		vector<int> fin;
		for (int i1 = 0; i1 < k; i1++)
		{
			pos.push_back(i1);
			fin.insert(fin.begin(), n - i1 - 1);
		}

		string base = "";
		for (int i2 = 0; i2 < n; i2++)
		{
			base.push_back('0');
		}

        printf("The bit patterns are\n");
		patt(pos, fin, base, n, k);
    }
    
    system("pause");
}
