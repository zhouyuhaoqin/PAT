/*
*	author:		zhouyuhao
*	created:	2023-04-13 22:07:11
*	modified:	2023-04-13 22:13:52
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>

using namespace std;

vector<bool> isprime;

void sieve(int n) {
	isprime.resize(n + 1, true);
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (isprime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				isprime[j] = false;
			}
		}
	}
}

int main(int argc, char const *argv[]) {

	int n, maxp;
	cin >> n >> maxp;
	sieve(maxp);
	while (!isprime[maxp]) {
		maxp--;
	}
	if (n == 1) {
		cout << maxp << "\n";
		return 0;
	}
	int maxdif = -1, lastn = -1;
	for (int dif = (maxp - 2) / (n - 1); dif >= 1; dif--) {
		bool succeed = false;
		for (int e = maxp; e > maxp - dif; e--) { //lower bound of e
			if (!isprime[e]) {
				continue;
			}
			bool flag = true;
			for (int i = 0; i < n; i++) {
				if (!isprime[e - i * dif]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				succeed = true;
				maxdif = dif;
				lastn = e;
				break;
			}
		}
		if (succeed) {
			break;
		}
	}
	if (maxdif != -1) {
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			ans.push_back(lastn - i * maxdif);
		}
		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i];
			if (i > 0) {
				cout << " ";
			} else {
				cout << "\n";
			}
		}	
	} else {
		cout << maxp << "\n";
	}

	return 0;
}