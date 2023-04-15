/*
*	author:		zhouyuhao
*	created:	2023-04-06 08:29:36
*	modified:	2023-04-06 08:49:35
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

	string s;
	cin >> s;
	bool allprime = true;
	for (int i = 0; i < s.size(); i++) {
		cout << s.substr(i) << " ";
		if (isprime(stoi(s.substr(i)))) {
			cout << "Yes\n";
		} else {
			allprime = false;
			cout << "No\n";
		}
	}
	if (allprime) {
		cout << "All Prime!\n";
	}
	
	return 0;
}