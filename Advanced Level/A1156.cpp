/*
*	author:		zhouyuhao
*	created:	2023-04-05 09:39:36
*	modified:	2023-04-05 09:51:29
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= (int) sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	if (isprime(n) && (isprime(n - 6) || isprime(n + 6))) {
		cout << "Yes\n";
		if (isprime(n - 6)) {
			cout << n - 6 << "\n";
		} else if (isprime(n + 6)) {
			cout << n + 6 << "\n";
		}
	} else {
		while (!(isprime(n) && (isprime(n - 6) || isprime(n + 6)))) {
			n++;
		}
		cout << "No\n";
		cout << n << "\n";
	}
	
	return 0;
}