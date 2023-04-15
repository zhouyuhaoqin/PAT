/*
*	author:		zhouyuhao
*	created:	2023-03-23 15:53:43
*	modified:	2023-03-23 16:09:13
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {

	map<int, float, greater<int> > p;
	for (int i = 0; i < 2; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int a;
			float b;
			cin >> a >> b;
			p[a] += b;
		}
	}
	int cnt = 0;
	for (auto it : p) {
		if (it.second != 0) {
			cnt++;
		}
	}
	cout << cnt;
	for (auto it : p) {
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