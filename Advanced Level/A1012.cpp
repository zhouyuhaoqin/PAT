/*
*	author:		zhouyuhao
*	created:	2023-03-23 13:29:01
*	modified:	2023-03-24 19:58:17
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct stu {
	int id;
	int s[4];
	int r[4];
	int rank;
	char subject;
};

vector<stu> d;

int idx;

bool cmp(stu a, stu b) {
	return a.s[idx] > b.s[idx];
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		stu t;
		cin >> t.id;
		double avg = 0;
		for (int j = 0; j < 3; j++) {
			cin >> t.s[j + 1];
			avg += t.s[j + 1];
		}
		t.s[0] = avg / 3 + 0.5;
		d.push_back(t);
	}
	for (idx = 0; idx < 4; idx++) {
		sort(d.begin(), d.end(), cmp);
		d[0].r[idx] = 1;
		for (int i = 1; i < n; i++) {
			if (d[i].s[idx] == d[i - 1].s[idx]) {
				d[i].r[idx] = d[i - 1].r[idx];
			} else {
				d[i].r[idx] = i + 1;
			}
		}
	}
	char trans[4] = {'A', 'C', 'M', 'E'};
	for (int i = 0; i < n; i++) {
		d[i].rank = d[i].r[0];
		d[i].subject = 'A';
		for (int j = 1; j < 4; j++) {
			if (d[i].r[j] < d[i].rank) {
				d[i].rank = d[i].r[j];
				d[i].subject = trans[j];
			}
		}
	}
	map<int, stu> q;
	for (auto it : d) {
		q.insert(make_pair(it.id, it));
	}
	for (int i = 0; i < m; i++) {
		int id;
		cin >> id;
		if (q.find(id) == q.end()) {
			cout << "N/A" << "\n";
		} else {
			cout << q[id].rank << " " << q[id].subject << "\n";
		}
	}
	
	return 0;
}