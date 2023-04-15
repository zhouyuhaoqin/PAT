/*
*	author:		zhouyuhao
*	created:	2023-04-04 19:54:51
*	modified:	2023-04-04 19:59:37
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {

	int l, k;
	cin >> l >> k;
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - k + 1; i++) {
		if (isprime(stoi(s.substr(i, k)))) {
			cout << s.substr(i, k) << "\n";
			return 0;
		}
	}
	cout << "404\n";
	
	return 0;
}