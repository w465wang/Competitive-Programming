/*
PEG
Date Started: 2018/02/03, Date Finished: 2018/02/03
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
typedef pair<int, int> pi;

int n, a, b, cost, num, len, prime[5000005];
vector<int> divi;

void init(int it, int stop) {
	if (it > stop)
		divi.push_back(num);
	else if (num % it == 0)
		return;
	else
		init(it + 1, stop);
}

void sieve(int it, int stop) {
	if (it == len || divi[it] > stop)
		return;
	else {
		for (int j = divi[it] * 2; j <= n; j += divi[it])
			prime[j] = 1;

		sieve(it + 1, stop);
	}
}

int main() {
    scanf("%d", &n);

	for (int i = 2; i <= (int)sqrt(n); i++) {
		num = i; 

		init(2, (int)sqrt(num));
	}

	len = divi.size();
	sieve(0, (int)sqrt(n));
    
    a = 1;
    
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			a = i;
			break;
		}
	}
    
    b = n / a;

	while (n > 1) {
		cout << n << " " << a << " " << b << " " << cost << "\n";
		if (a == 1) {
			if (!prime[b]) {
				n--;
				b--;
				cost += b;
			} else {
				for (int i = 2; i <= sqrt(n); i++) {
					if (n % i == 0) {
						a = i;
						break;
					}
				}

				b = n / a;
			}
		} else if (!prime[a]) {
			n -= b;
			a--;
			cost += a;
		} else {
			for (int i = 2; i <= sqrt(n); i++) {
				if (n % i == 0) {
					a = i;
					break;
				}
			}

			b = n / a;
		}
	}
    
    printf("%d\n", cost);
    
    system("pause");
}
