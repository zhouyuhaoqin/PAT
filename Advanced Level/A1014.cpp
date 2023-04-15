/*
*	author:		zhouyuhao
*	created:	2023-04-12 23:42:25
*	modified:	2023-04-13 08:50:22
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

struct cus {
	int cid, wid, pt, et;
	friend bool operator< (cus a, cus b) {
		if (a.et != b.et) {
			return a.et > b.et;
		} else {
			return a.wid > b.wid;
		}
	}
};

int main(int argc, char const *argv[]) {

	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<int> d(k + 1);
	for (int i = 0; i < k; i++) {
		cin >> d[i + 1];
	}
	vector<queue<cus>> w(n + 1);
	priority_queue<cus> c;
	vector<int> et(k + 1), wet(n + 1);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int id = (i - 1) * n + j;
			if (id <= k) {
				wet[j] += d[id];
				et[id] = wet[j];
				w[j].push({id, j, d[id], wet[j]});
				if (i == 1) {
					c.push({id, j, d[id], wet[j]});
				}
			} else {
				break;
			}
		}
	}
	for (int i = m * n + 1; i <= k; i++) {
		cus t = c.top();
		c.pop();
		w[t.wid].pop();
		wet[t.wid] += d[i];
		et[i] = wet[t.wid];
		w[t.wid].push({i, t.wid, d[i], wet[t.wid]});
		cus tw = w[t.wid].front();
		c.push(tw);
	}
	for (int qq = 0; qq < q; qq++) {
		int id;
		cin >> id;
		if (et[id] - d[id] >= 540) {
			cout << "Sorry\n";
		} else {
			cout << setfill('0') << setw(2) << 8 + et[id] / 60 << ":" << setfill('0') << setw(2) << et[id] % 60 << "\n";
		}
	}
	
	return 0;
}