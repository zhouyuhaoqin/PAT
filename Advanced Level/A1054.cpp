/*
*	author:		zhouyuhao
*	created:	2023-03-26 22:24:59
*	modified:	2023-03-26 22:29:43
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int m, n;
	cin >> m >> n;
	map<int, int> count;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			count[num]++;
		}
	}
	int r, hc = -1;
	for (auto it : count) {
		if (it.second > hc) {
			hc = it.second;
			r = it.first;
			if (it.second > m * n / 2) {
				break;
			}
		}
	}
	cout << r << "\n";
	
	return 0;
}