/*
*	author:		zhouyuhao
*	created:	2023-03-27 20:44:34
*	modified:	2023-03-27 21:47:40
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int main(int argc, char const *argv[]) {

	int np, ng;
	cin >> np >> ng;
	vector<int> w(np);
	for (int i = 0; i < np; i++) {
		cin >> w[i];
	}
	vector<int> id(np);
	for (int i = 0; i < np; i++) {
		cin >> id[i];
	}
	queue<int> q;
	for (auto it : id) {
		q.push(it);
	}
	vector<int> r(np);
	while(q.size() > 1) {
		vector<int> nowid;
		while (!q.empty()) {
			nowid.push_back(q.front());
			q.pop();
		}
		for (int i = 0; i <= nowid.size() / ng; i++) {
			int maxw = INT_MIN, maxwid = -1;
			for (int j = 0; j < ng && i * ng + j < nowid.size(); j++) {
				int loc = i * ng + j;
				if (w[nowid[loc]] > maxw) {
					maxw = w[nowid[loc]];
					maxwid = nowid[loc];
				}
			}
			if (maxwid != -1) {
				q.push(maxwid);
			}
		}
		for (auto it : nowid) {
			r[it] = q.size() + 1;
		}
	}
	if (q.size() == 1) {
		r[q.front()] = 1;
	}
	for (int i = 0; i < np; i++) {
		cout << r[i];
		if (i < np - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	
	return 0;
}