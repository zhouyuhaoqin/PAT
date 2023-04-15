/*
*	author:		zhouyuhao
*	created:	2023-04-13 18:15:46
*	modified:	2023-04-13 18:50:17
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> d;

struct node {
	int id, dis;
	friend bool operator< (node a, node b) {
		if (a.dis != b.dis) {
			return a.dis > b.dis;
		} else {
			return a.id > b.id;
		}
	}
};

void floyd(int n) {
	for (int k = 0; k <= n; k++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (d[i][k] != INT_MAX && d[k][j] != INT_MAX) {
					if (d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	d.resize(n + 1, vector<int> (n + 1, INT_MAX));
	for (int i = 0; i < m; i++) {
		int u, v, dis;
		cin >> u >> v >> dis;
		d[u][v] = d[v][u] = dis;
	}
	floyd(n);
	vector<int> ans;
	int sum = 0;
	vector<bool> vis(n + 1, false);
	int st = 0;
	vis[st] = true;
	ans.push_back(st);
	while (true) {
		priority_queue<node> q;
		for (int i = 0; i <= n; i++) {
			if (!vis[i]) {
				q.push({i, d[st][i]});
			}
		}
		if (q.empty()) {
			break;
		}
		node t = q.top();
		if (t.dis == INT_MAX) {
			break;
		}
		ans.push_back(t.id);
		sum += t.dis;
		vis[t.id] = true;
		st = t.id;
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i < ans.size() - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	if (ans.size() == n + 1) {
		cout << sum << "\n";
	} else {
		vector<int> notvis;
		for (int i = 0; i <= n; i++) {
			if (!vis[i]) {
				notvis.push_back(i);
			}
		}
		for (int i = 0; i < notvis.size(); i++) {
			cout << notvis[i];
			if (i < notvis.size() - 1) {
				cout << " ";
			} else {
				cout << "\n";
			}
		}
	}
	
	return 0;
}