/*
*	author:		zhouyuhao
*	created:	2023-04-11 14:51:46
*	modified:	2023-04-12 00:55:25
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	m %= n;
	if (m != 0) {
		int g = gcd(n, m);
		for (int i = n - m; i < n - m + g; i++) {
			int now = i;
			int t = d[now];
			do {
				int next = (now - m + n) % n;
				if (next != i) {
					d[now] = d[next];
				} else {
					d[now] = t;
				}
				now = next;
			} while (now != i);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << d[i];
		if (i < n - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	
	return 0;
}