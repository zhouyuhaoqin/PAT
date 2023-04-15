/*
*	author:		zhouyuhao
*	created:	2023-04-05 19:33:11
*	modified:	2023-04-05 20:57:47
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const int maxn = 1e5;

struct node {
	int addr, data, next;
};

vector<node> d(maxn);

int main(int argc, char const *argv[]) {

	int l1, l2, n;
	cin >> l1 >> l2 >> n;
	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		d[id].addr = id;
		cin >> d[id].data >> d[id].next;
	}
	vector<node> d1, d2;
	do {
		d1.push_back(d[l1]);
		l1 = d[l1].next;
	} while (l1 != -1);
	do {
		d2.push_back(d[l2]);
		l2 = d[l2].next;
	} while (l2 != -1);
	if (d1.size() < d2.size()) {
		swap(d1, d2);
	}
	vector<node> ans;
	int ib = d2.size() - 1;
	for (int i = 0; i < d1.size(); i++) {
		// if (i % 2 == 0 && i != 0) {
		ans.push_back(d1[i]);
		if ((i + 1) % 2 == 0) {
			if (ib >= 0) {
				ans.push_back(d2[ib--]);
			}
		}
		// ans.push_back(d1[i]);
	}
	// for (int i = 0; i < d1.size() && ib >= 0; i++) {
	// 	if (i % 2 == 0 && i != 0) {
	// 		ans.push_back(d2[ib--]);
	// 	}
	// 	ans.push_back(d1[i]);
	// }
	for (int i = 0; i < ans.size(); i++) {
		cout << setfill('0') << setw(5) << ans[i].addr << " " << ans[i].data << " ";
		if (i < ans.size() - 1) {
			cout << setfill('0') << setw(5) << ans[i + 1].addr << "\n";
		} else {
			cout << "-1\n";
		}
	}
	
	return 0;
}