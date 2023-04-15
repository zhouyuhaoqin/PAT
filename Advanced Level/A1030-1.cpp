/*
*	author:		zhouyuhao
*	created:	2023-03-30 19:49:55
*	modified:	2023-03-31 11:10:12
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct node {
	int v, dis, cost;
	friend bool operator< (node a, node b) {
		return a.dis > b.dis;
	}
};

vector<bool> vis;
vector<int> d, c, pre;
vector<vector<node>> g;

void dijkstra(int s) {
	fill(vis.begin(), vis.end(), false);
	fill(d.begin(), d.end(), INT_MAX);
	fill(c.begin(), c.end(), INT_MAX);
	d[s] = 0;
	c[s] = 0;
	priority_queue<node> q;
	q.push({s, 0, 0});
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		int u = t.v;
		if (d[u] < t.dis) {
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v;
			if (!vis[v]) {
				if (d[u] + g[u][i].dis < d[v]) {
					d[v] = d[u] + g[u][i].dis;
					c[v] = c[u] + g[u][i].cost;
					// g[u][i].cost = cost[u][v];
					pre[v] = u;
					q.push({v, d[v], c[v]});
				} else if (d[u] + g[u][i].dis == d[v]) {
					if (c[u] + g[u][i].cost < c[v]) {
						c[v] = c[u] + g[u][i].cost;
						pre[v] = u;
					}
				}
			}
		}
	}
}

vector<int> ans;
void print(int s, int v) {
	if (v == s) {
		ans.push_back(v);
		return;
	}
	print(s, pre[v]);
	ans.push_back(v);
}

int main(int argc, char const *argv[]) {

	int n, m, s, e;
	cin >> n >> m >> s >> e;
	vis.resize(n);
	d.resize(n);
	c.resize(n);
	pre.resize(n);
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int c1, c2, dis, cost;
		cin >> c1 >> c2 >> dis >> cost;
		g[c1].push_back({c2, dis, cost});
		g[c2].push_back({c1, dis, cost});
	}
	dijkstra(s);
	print(s, e);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << d[e] << " " << c[e] << "\n";
	
	return 0;
}