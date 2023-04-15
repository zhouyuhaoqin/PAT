/*
*	author:		zhouyuhao
*	created:	2023-04-12 21:59:05
*	modified:	2023-04-12 23:42:02
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

struct cus {
	int arr, p;
	friend bool operator< (cus a, cus b) {
		return a.arr > b.arr;
	}
};

int trans(int h, int m, int s) {
	return h * 60 * 60 + m * 60 + s;
}

int main(int argc, char const *argv[]) {

	int n, k;
	cin >> n >> k;
	priority_queue<cus> c;
	int be = trans(8, 0, 0), en = trans(17, 0, 0);
	for (int i = 0; i < n; i++) {
		int h, m, s, p;
		scanf("%d:%d:%d %d", &h, &m, &s, &p);
		if (trans(h, m, s) > en) {
			continue;
		}
		c.push({trans(h, m, s), p * 60});
	}
	n = c.size();
	int wait = 0;
	priority_queue<int, vector<int>, greater<int>> w;
	for (int i = 0; i < k; i++) {
		if (!c.empty()) {
			cus t = c.top();
			c.pop();
			if (t.arr < be) {
				wait += be - t.arr;
				t.arr = be; // @important!
			}
			w.push(t.arr + t.p);
		} else {
			break;
		}
	}
	while (!c.empty()) {
		cus tc = c.top();
		c.pop();
		int tw = w.top();
		w.pop();
		if (tc.arr < tw) {
			wait += tw - tc.arr;
			w.push(tw + tc.p);
		} else { // @important!
			w.push(tc.arr + tc.p);
		}
	}
	cout << fixed << setprecision(1) << (double) wait / n / 60 << "\n";
	
	return 0;
}