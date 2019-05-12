/*
PEG
Date Started: 2017/07/04, Date Finished: 2017/07/04
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string city, cityLow;
	int temp, low;

	cin >> city;
	cin >> temp;
	
	cityLow = city;
	low = temp;
	while (city != "Waterloo")
	{
		cin >> city;
		cin >> temp;

		if (temp < low)
		{
			low = temp;
			cityLow = city;
		}

	}

	cout << cityLow << "\n";

	system("pause");
}


