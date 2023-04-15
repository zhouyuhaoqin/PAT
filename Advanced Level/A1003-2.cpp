/*
*	author:		zhouyuhao
*	created:	2023-03-30 19:07:00
*	modified:	2023-03-30 19:30:26
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct node {
	int v, d;
	friend bool operator< (node a, node b) {
		return a.d > b.d;
	}
};

vector<bool> vis;
vector<int> d, t;
vector<vector<int>> pre;
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

int cnt = 0, maxt = -1;
vector<int> temp;

void dfs(int s, int v) {
	if (v == s) {
		cnt++;
		temp.push_back(v);
		int sumt = 0;
		for (int i = 0; i < temp.size(); i++) {
			sumt += t[temp[i]];
		}
		if (sumt > maxt) {
			maxt = sumt;
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

	int n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;
	vis.resize(n);
	d.resize(n);
	t.resize(n);
	pre.resize(n);
	g.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < m; i++) {
		int id1, id2, l;
		cin >> id1 >> id2 >> l;
		g[id1].push_back({id2, l});
		g[id2].push_back({id1, l});
	}
	dijkstra(c1);
	dfs(c1, c2);
	cout << cnt << " " << maxt << "\n";
	
	return 0;
}