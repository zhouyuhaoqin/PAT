/*
*	author:		zhouyuhao
*	created:	2023-03-23 16:12:36
*	modified:	2023-03-23 16:21:17
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {

	map<int, float> a;
	int k1;
	cin >> k1;
	for (int i = 0; i < k1; i++) {
		int a1;
		float a2;
		cin >> a1 >> a2;
		a[a1] = a2;
	}
	map<int, float, greater<int> > b;
	int k2;
	cin >> k2;
	for (int i = 0; i < k2; i++) {
		int a1;
		float a2;
		cin >> a1 >> a2;
		for (auto it : a) {
			b[a1 + it.first] += a2 * it.second;
		}
	}
	int cnt = 0;
	for (auto it : b) {
		if (it.second != 0) {
			cnt++;
		}
	}
	cout << cnt;
	for (auto it : b) {
		if (it.second != 0) {
			if (cnt--) {
				cout << " ";
			}
			cout << it.first << " " << fixed << setprecision(1) << it.second;
		}
	}
	cout << "\n";
	
	return 0;
}