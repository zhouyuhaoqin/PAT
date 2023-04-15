/*
*	author:		zhouyuhao
*	created:	2023-03-25 22:47:27
*	modified:	2023-03-25 22:47:40
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/

//B1020

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct mc {
	float st, ts;
	float s;
};

bool cmp(mc a, mc b) {
	return a.s > b.s;
}

int main(int argc, char const *argv[]) {

	int n, d;
	cin >> n >> d;
	vector<mc> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i].st;
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i].ts;
		c[i].s = c[i].ts / c[i].st;
	}
	sort(c.begin(), c.end(), cmp);
	float tr = 0;
	for (int i = 0; i < n; i++) {
		if (d > c[i].st) {
			tr += c[i].ts;
			d -= c[i].st;
		} else {
			tr += d * c[i].s;
			break;
		}
	}
	cout << fixed << setprecision(2) <<tr << "\n";
	
	return 0;
}