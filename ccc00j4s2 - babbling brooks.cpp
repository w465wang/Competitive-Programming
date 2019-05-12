/*
PEG
Date Started: 2017/07/06, Date Finished: 
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void printVec(vector<double> vec)
{
	int len = vec.size();
	for (int j = 0; j < len; j++)
	{
		cout << round(vec[j]) << " ";
	}
	cout << endl;
}

int main()
{
	int n, flow;
	cin >> n;
	vector<double> stream;

	while (n--)
	{
		cin >> flow;
		stream.push_back(flow);
	}

	int inp, cmd;
	cin >> inp;
	while (inp != 77)
	{
		cin >> cmd;
		if (inp == 99)
		{
			int per;
			cin >> per;
			double split = stream[cmd - 1] * per / 100.0;
			stream.insert(stream.begin() + cmd, stream[cmd - 1] - split);
			stream[cmd - 1] = split;
		}
		else if (inp == 88)
		{
			stream[cmd - 1] += stream[cmd];	
			stream.erase(stream.begin() + cmd);
		}

		cin >> inp;
	}

	printVec(stream);

	system("pause");
}
