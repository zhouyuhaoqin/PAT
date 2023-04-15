/*
*	author:		zhouyuhao
*	created:	2023-04-04 16:16:37
*	modified:	2023-04-04 17:03:46
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> d(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> d[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int cntwl = 0;
			if (d[i] > 0) {
				if (d[i] == i || d[i] == j) {
					cntwl++;
				}
			} else {
				if (abs(d[i]) != i && abs(d[i]) != j) {
					cntwl++;
				}
			}
			if (d[j] > 0) {
				if (d[j] == i || d[j] == j) {
					cntwl++;
				}
			} else {
				if (abs(d[j]) != i && abs(d[j]) != j) {
					cntwl++;
				}
			}
			int cntal = 0;
			for (int k = 1; k <= n; k++) {
				if (d[k] > 0) {
					if (d[k] == i || d[k] == j) {
						cntal++;
					}
				} else {
					if (abs(d[k]) != i && abs(d[k]) != j) {
						cntal++;
					}
				}
			}
			if (cntwl == 1 && cntal == 2) {
				cout << i << " " << j << "\n";
				return 0;
			}
		}
	}
	cout << "No Solution\n";
	
	return 0;
}