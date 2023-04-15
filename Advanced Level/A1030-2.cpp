/*
*	author:		zhouyuhao
*	created:	2023-03-30 20:56:23
*	modified:	2023-03-30 21:14:50
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct node {
	int v, d;
	friend bool operator< (node a, node b) {
		return a.d > b.d;
	}
};

vector<bool> vis;
vector<int> d;
vector<vector<int>> c, pre;
vector<vector<node>> g;

void dijkstra(int s) {
	fill(vis.begin(), vis.end(), false);
	fill(d.begin(), d.end(), INT_MAX);
	d[s] = 0;
	priority_queue<node> q;
	q.push({s, 0});
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		int u = t.v;
		if (d[u] < t.d) {
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v;
			if (!vis[v]) {
				if (d[u] + g[u][i].d < d[v]) {
					d[v] = d[u] + g[u][i].d;
					pre[v].clear();
					pre[v].push_back(u);
					q.push({v, d[v]});
				} else if (d[u] + g[u][i].d == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

int minc = INT_MAX;
vector<int> temp, ans;
void dfs(int s, int v) {
	if (v == s) {
		temp.push_back(v);
		int sumc = 0;
		for (int i = temp.size() - 1; i > 0; i--) {
			sumc += c[temp[i]][temp[i - 1]];
		}
		// for (int i = 0; i < temp.size() - 1; i++) {
		// 	sumc += c[temp[i]][temp[i + 1]];
		// }
		if (sumc < minc) {
			minc = sumc;
			ans = temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(s, pre[v][i]);
	}
	temp.pop_back();
}

int main(int argc, char const *argv[]) {

	int n, m, s, e;
	cin >> n >> m >> s >> e;
	vis.resize(n);
	d.resize(n);
	c.resize(n);
	pre.resize(n);
	g.resize(n);
	for (int i = 0; i < n; i++) {
		c[i].resize(n);
	}
	for (int i = 0; i < m; i++) {
		int s, e, d, cost;
		cin >> s >> e >> d >> cost;
		g[s].push_back({e, d});
		g[e].push_back({s, d});
		c[s][e] = c[e][s] = cost;
	}
	dijkstra(s);
	dfs(s, e);
	reverse(ans.begin(), ans.end());
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << d[e] << " " << minc << "\n";
	
	return 0;
}