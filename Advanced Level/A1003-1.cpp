/*
*	author:		zhouyuhao
*	created:	2023-03-30 17:47:38
*	modified:	2023-03-30 19:06:54
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct node {
	int v, dis;
	friend bool operator< (node a, node b) {
		return a.dis > b.dis;
	}
};

vector<int> t, ct, d, p;
vector<bool> vis;
vector<vector<node>> g;

void dijkstra(int s, int e) {
	fill(d.begin(), d.end(), INT_MAX);
	fill(ct.begin(), ct.end(), 0);
	fill(p.begin(), p.end(), 0);
	fill(vis.begin(), vis.end(), false);
	d[s] = 0;
	ct[s] = t[s];
	p[s] = 1;
	priority_queue<node> q;
	q.push({s, 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int u = f.v;
		if (d[u] < f.dis) {
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v;
			if (!vis[v]) {
				if (d[u] + g[u][i].dis < d[v]) {
					d[v] = d[u] + g[u][i].dis;
					ct[v] = ct[u] + t[v];
					p[v] = p[u];
					q.push({v, d[v]});
				} else if (d[u] + g[u][i].dis == d[v]) {
					if (ct[v] < ct[u] + t[v]) {
						ct[v] = ct[u] + t[v];
					}
					p[v] += p[u];
				}
			}
		}
	}
}

int main(int argc, char const *argv[]) {

	int n, m, s, e;
	cin >> n >> m >> s >> e;
	t.resize(n);
	ct.resize(n);
	d.resize(n);
	p.resize(n);
	vis.resize(n);
	g.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < m; i++) {
		int c1, c2, l;
		cin >> c1 >> c2 >> l;
		g[c1].push_back({c2, l});
		g[c2].push_back({c1, l});
	}
	dijkstra(s, e);
	cout << p[e] << " " << ct[e] << "\n";
	
	return 0;
}