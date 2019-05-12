/*
PEG
Date Started: 2017/07/24, Date Finished: 2017/07/30
*/

#include <iostream>
using namespace std;

int move(char a, char b, char c, int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		move(a, c, b, n - 1);

		printf("%c", a);
		printf("%c\n", c);

		move(b, a, c, n - 1);
	}
}

int main()
{
	int n;
	cin >> n;

	move('A', 'B', 'C', n);

	system("pause");
}
