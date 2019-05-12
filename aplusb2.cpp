/*
 PEG
 Date Started: 2017/07/29, Date Finished: 2017/07/29
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> digits;
    string A, B;
    cin >> A >> B;
    
    int neg = 0;
    if (A.find('-') != -1)
    {
        neg += 1;
        A.erase(A.begin());
    }
    if (B.find('-') != -1)
    {
        neg += 2;
        B.erase(B.begin());
    }
    
    int lenA = A.size();
    int lenB = B.size();
    
    int n;
    if (lenA >= lenB)
    {
        n = lenA;
        B = string(n - lenB, '0').append(B);
        
    }
    else
    {
        n = lenB;
        A = string(n - lenA, '0').append(A);
    }
    // Add
    if (neg == 0 || neg == 3)
    {
        int carry = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int d = A[i] + B[i] - 96 + carry;
            
            if (i > 0)
            {
                digits.push_back(d % 10);
            }
            else
            {
                digits.push_back(d);
            }
            
            carry = d / 10;
        }
        
        if (neg == 3)
        {
            cout << '-';
        }
    }
	// Subtract
    else if (neg == 1 || neg == 2)
    {
		if (A == B)
		{
			digits.push_back(0);
		}
		else
		{
			string X, Y;
			int take = 0;

			if (A > B)
			{
				X = A;
				Y = B;

				if (neg == 1)
				{
					cout << '-';
				}
			}
			else if (A < B)
			{
				X = B;
				Y = A;

				if (neg == 2)
				{
					cout << '-';
				}
			}

			for (int i = n - 1; i >= 0; i--)
			{
				if (X[i] < Y[i] + take)
				{
					int d = X[i] - Y[i] + 10 - take;
					digits.push_back(d);
					take = 1;
				}
				else
				{
					int d = X[i] - Y[i] - take;

					if (d >= 0)
					{
						digits.push_back(d);
					}
					else
					{
						digits.push_back(d + 10);
					}

					take = 0;
				}
			}

			while (digits[n - 1] == 0)
			{
				digits.erase(digits.end() - 1);
				n--;
			}
		}
    }
    
    for (int j = n - 1; j >= 0; j--)
    {
        printf("%d", digits[j]);
    }

    cout << "\n";
    
    system("pause");
}
