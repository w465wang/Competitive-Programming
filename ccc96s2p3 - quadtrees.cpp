/*
Peg
Date Started: 2017/08/11, Date Finished: 2017/08/11
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int len, num;
vector<string> quads;

int pow(int it)
{
	int num = 1;
	for (int i1 = 0; i1 < it; i1++)
	{
		num *= 4;
	}

	return num;
}

void quad(string tree, vector<int> level, string total, int count)
{
	if (level.size() == 0)
	{
		quads.push_back(total);
	}
	else
	{
		if (tree[0] == 'p')
		{
			level.push_back(0);

			if (level.size() > count)
			{
				len = total.size();
				string copy = "";

				for (int j = 0; j < len; j++)
				{
					if (total[j] == '0')
						copy += "0000";
					else if (total[j] == '1')
						copy += "1111";
				}

				total = copy;
				count++;
			}
		}
		else
		{
			if (tree[0] == 'f')
			{
				len = total.size();
				int start = 0;
				int siz = level.size();

				for (int k = 0; k < siz; k++)
				{
					num = pow(k + 1);
					start += len / num * level[k];
				}

				num = len / pow(siz);
				for (int k1 = 0; k1 < num; k1++)
				{
					total[start + k1] = '1';
				}
			}

			level.back()++;
		}

		if (level.back() == 4)
		{
			while (level.size() > 0 && level.back() == 4)
			{
				level.erase(level.end() - 1);

				if (level.size() > 0)
					level.back()++;
			}
		}

		tree.erase(tree.begin());
		quad(tree, level, total, count);
	}
}

int main()
{
	int n;
	cin >> n;
	string tree, tlong, tshort, tnew;

	for (int i = 0; i < n; i++)
	{
		for (int i1 = 0; i1 < 2; i1++)
		{
			cin >> tree;
			
			if (tree[0] == 'p')
			{
				tree.erase(tree.begin());
				quad(tree, { 0 }, "0000", 1);
			}
			else if (tree[0] == 'e')
				quads.push_back("0");
			else if (tree[0] == 'f')
				quads.push_back("1");
		}

		if (quads[0].size() <= quads[1].size())
		{
			tshort = quads[0];
			tlong = quads[1];
		}
		else if (quads[0].size() > quads[1].size())
		{
			tshort = quads[1];
			tlong = quads[0];
		}

		num = tlong.size() / tshort.size();
		tnew = "";

		for (int i2 = 0; i2 < tshort.size(); i2++)
		{
			string add(num, tshort[i2]);
			
			tnew += add;
		}

		int pix = 0;
		for (int i3 = 0; i3 < tlong.size(); i3++)
		{
			if (tnew[i3] == '1' || tlong[i3] == '1')
				pix++;
		}

		printf("There are %d black pixels.\n", pix * 1024 / tlong.size());

		quads.clear();
	}

	system("pause");
}