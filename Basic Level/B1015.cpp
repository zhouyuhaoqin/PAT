/*
*	author:		zhouyuhao
*	created:	2023-03-23 13:27:25
*	modified:	2023-03-23 13:27:37
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/

//A1062

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct per {
	int id;
	int vir, tal, tot;
	int flag;
};

bool cmp(per a, per b) {
	if (a.flag != b.flag) {
		return a.flag < b.flag;
	} else if (a.tot != b.tot) {
		return a.tot > b.tot;
	} else if (a.vir != b.vir) {
		return a.vir > b.vir;
	} else {
		return a.id < b.id;
	}
}

int main(int argc, char const *argv[]) {

	int n, l, h;
	cin >> n >> l >> h;
	vector<per> p;
	for (int i = 0; i < n; i++) {
		per t;
		cin >> t.id >> t.vir >> t.tal;
		t.tot = t.vir + t.tal;
		if (t.vir < l || t.tal < l) {
			continue;
		} else if (t.vir >= h && t.tal >= h) {
			t.flag = 1;
		} else if (t.vir >= h && t.tal < h) {
			t.flag = 2;
		} else if (t.vir < h && t.tal < h && t.vir >= t.tal) {
			t.flag = 3;
		} else {
			t.flag = 4;
		}
		p.push_back(t);
	}
	sort(p.begin(), p.end(), cmp);
	cout << p.size() << "\n";
	for (auto it : p) {
		cout << it.id << " " << it.vir << " " << it.tal << "\n";
	}
	
	return 0;
}