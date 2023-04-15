/*
*	author:		zhouyuhao
*	created:	2023-03-22 16:57:07
*	modified:	2023-03-22 17:25:54
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

char pos[3] = {'B', 'C', 'J'};
int trans(char c) {
	if (c == 'B') {
		return 0;
	} else if (c == 'C') {
		return 1;
	} else {
		return 2;
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> a(3), b(3);
	vector<int> ap(3), bp(3);
	for (int i = 0; i < n; i++) {
		char ca, cb;
		cin >> ca >> cb;
		int ia = trans(ca);
		int ib = trans(cb);
		if ((ia + 1) % 3 == ib) {
			a[0]++, b[2]++;
			ap[ia]++;
		} else if ((ib + 1) % 3 == ia) {
			a[2]++, b[0]++;
			bp[ib]++;
		} else {
			a[1]++, b[1]++;
		}
	}
	int am = max_element(ap.begin(), ap.end()) - ap.begin();
	int bm = max_element(bp.begin(), bp.end()) - bp.begin();
	for (int i = 0; i < 3; i++) {
		cout << a[i];
		if (i < 2) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << b[i];
		if (i < 2) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	cout << pos[am] << " " << pos[bm] << "\n";
	
	return 0;
}