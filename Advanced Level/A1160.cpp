/*
*	author:		zhouyuhao
*	created:	2023-04-05 19:28:28
*	modified:	2023-04-05 21:55:49
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int n) {
	if (n <= 2) {
		return false;
	}
	for (int i = 2; i <= (int) sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int gcd(int a, int b) {
	if (!b) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int getsum(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int getsuffix(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum * 10 + 9;
	}
	return sum;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	for (int q = 0; q < n; q++) {
		int k, m;
		cin >> k >> m;
		cout << "Case " << q + 1 << "\n";
		bool flag = false;
		for (int i = 3; i < m; i++) {
			if (isprime(gcd(m, i))) {
				if ((m - i + 1) % 9 == 0) {
					int rc = (m - i + 1) / 9;
					int suffix = getsuffix(rc);
					int lc = k - rc;
					int sum = m - rc * 9;
					if (sum >= 1 && sum <= lc * 9) {
						for (int j = pow(10, lc - 1); j <= pow(10, lc) - 1; j++) {
							if (getsum(j) == sum && j % 10 != 9) {
								cout << i << " " << j << suffix << "\n";
								flag = true;
							}
						}
					}
				}
			}
		}
		if (!flag) {
			cout << "No Solution\n";
		}
	}
	
	return 0;
}