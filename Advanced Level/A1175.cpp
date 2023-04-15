/*
*	author:		zhouyuhao
*	created:	2023-04-14 14:59:32
*	modified:	2023-04-14 18:54:50
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct node {
	int v, s;
	friend bool operator< (node a, node b) {
		return a.s > b.s;
	}
};

vector<int> ind, indtemp;
vector<int> s, d, pre;
vector<bool> vis;
vector<vector<int>> vouch;
vector<vector<node>> g;

bool topologicalsort(int n) {
	queue<int> q;
	q.push(n);
	int cnt = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v;
			indtemp[v]--;
			if (indtemp[v] == 0) {
				q.push(v);
			}
		}
	}
	if (cnt == n + 1) {
		return true;
	} else {
		return false;
	}
}

void dijkstra(int st) {
	s[st] = 0;
	d[st] = 0; // start
	priority_queue<node> q;
	q.push({st, 0});
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		int u = t.v;
		if (s[u] < t.s) {
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v;
			if (!vis[v]) {
				if (s[u] + g[u][i].s < s[v]) {
					s[v] = s[u] + g[u][i].s;
					d[v] = d[u] + vouch[u][v]; // not need dfs
					pre[v] = u;
					q.push({v, s[v]});
				} else if (s[u] + g[u][i].s == s[v]) {
					if (d[u] + vouch[u][v] > d[v]) {
						d[v] = d[u] + vouch[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	ind.resize(n + 1);
	s.resize(n + 1, INT_MAX);
	d.resize(n + 1, INT_MIN);
	pre.resize(n + 1);
	vis.resize(n + 1);
	g.resize(n + 1);
	vouch.resize(n + 1, vector<int> (n + 1));
	for (int i = 0; i < m; i++) {
		int u, v, sco, vou;
		cin >> u >> v >> sco >> vou;
		ind[v]++;
		g[u].push_back({v, sco});
		vouch[u][v] = vou;
	}
	indtemp = ind;
	for (int i = 0; i < n; i++) {
		if (indtemp[i] == 0) {
			indtemp[i]++; // super source point
			g[n].push_back({i, 0});
		}
	}
	int k;
	cin >> k;
	if (topologicalsort(n)) {
		cout << "Okay.\n";
		dijkstra(n);
		for (int q = 0; q < k; q++) {
			int en;
			cin >> en;
			if (ind[en] == 0) {
				cout << "You may take test " << en << " directly.\n";
			} else {
				vector<int> ans;
				while (en != n) {
					ans.push_back(en);
					en = pre[en];
				}
				for (int i = ans.size() - 1; i >= 0; i--) {
					cout << ans[i];
					if (i > 0) {
						cout << "->";
					} else {
						cout << "\n";
					}
				}
			}
		}
	} else {
		cout << "Impossible.\n";
		for (int q = 0; q < k; q++) {
			int en;
			cin >> en;
			if (ind[en] == 0) {
				cout << "You may take test " << en << " directly.\n";
			} else {
				cout << "Error.\n";
			}
		}
	}
	
	return 0;
}