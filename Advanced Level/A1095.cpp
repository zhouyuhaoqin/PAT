/*
*	author:		zhouyuhao
*	created:	2023-03-25 17:35:20
*	modified:	2023-03-25 17:56:35
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct car {
	string id;
	int time;
	string status;
};

int trans(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}

bool cmp(car a, car b) {
	if (a.id != b.id) {
		return a.id < b.id;
	} else {
		return a.time < b.time;
	}
}

bool cmptime(car a, car b) {
	return a.time < b.time;
}

int main(int argc, char const *argv[]) {

	int n, k;
	cin >> n >> k;
	vector<car> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i].id;
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		c[i].time = trans(h, m, s);
		cin >> c[i].status;
	}
	sort(c.begin(), c.end(), cmp);
	vector<car> cp;
	map<string, int> during;
	int maxduring = -1;
	for (int i = 0; i < n; i++) {
		if (c[i].id == c[i + 1].id && c[i].status == "in" && c[i + 1].status == "out") {
			cp.push_back(c[i]);
			cp.push_back(c[i + 1]);
			during[c[i].id] += c[i + 1].time - c[i].time;
			maxduring = max(during[c[i].id], maxduring);
		}
	}
	sort(cp.begin(), cp.end(), cmptime);
	int count = 0, idx = 0;
	for (int q = 0; q < k; q++) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int time = trans(h, m, s);
		for ( ; idx < cp.size(); idx++) {
			if (cp[idx].time <= time) {
				if (cp[idx].status == "in") {
					count++;
				} else {
					count--;
				}
			} else {
				break;
			}
		}
		cout << count << "\n";
	}
	for (auto it : during) {
		if (it.second == maxduring) {
			cout << it.first << " ";
		}
	}
	printf("%02d:%02d:%02d\n", maxduring / 3600, maxduring % 3600 / 60, maxduring % 3600 % 60);

	return 0;
}