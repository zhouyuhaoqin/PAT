/*
*	author:		zhouyuhao
*	created:	2023-04-04 17:29:05
*	modified:	2023-04-04 18:22:07
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<vector<int>> d(n + 1);
	for (int i = 0; i < n + 1; i++) {
		d[i].resize(n + 1);
	}
	for (int i = 0; i < m; i++) {
		int a, b, dist;
		cin >> a >> b >> dist;
		d[a][b] = d[b][a] = dist;
	}
	int k;
	cin >> k;
	int minid = -1, mindist = INT_MAX;
	for (int q = 0; q < k; q++) {
		set<int> path;
		int nv, st;
		cin >> nv >> st;
		int en, lastid = st;
		int dist = 0;
		bool isarrive = true;
		for (int i = 1; i < nv; i++) {
			cin >> en;
			dist += d[lastid][en];
			if (d[lastid][en] == 0) {
				isarrive = false;
			}
			path.insert(en);
			lastid = en;
		}
		bool issimplecycle = false, iscycle = false;
		if (st == en && isarrive) {
			if (nv == n + 1 && path.size() == n) {
				issimplecycle = true;
			} else if (nv > n + 1 && path.size() == n) {
				iscycle = true;
			}
		}
		bool notacycle = !issimplecycle && !iscycle;
		cout << "Path " << q + 1 << ": ";
		if (isarrive) {
			cout << dist;
			if (!notacycle) {
				if (dist < mindist) {
					mindist = dist;
					minid = q + 1;
				}
			}
		} else {
			cout << "NA";
		}
		if (issimplecycle) {
			cout << " (TS simple cycle)\n";
		} else if (iscycle) {
			cout << " (TS cycle)\n";
		} else {
			cout << " (Not a TS cycle)\n";
		}
	}
	cout << "Shortest Dist(" << minid << ") = " << mindist << "\n";
	
	return 0;
}