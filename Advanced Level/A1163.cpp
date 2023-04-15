/*
*	author:		zhouyuhao
*	created:	2023-04-05 20:10:52
*	modified:	2023-04-05 20:36:00
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct node {
	int v, w;
	friend bool operator< (node a, node b) {
		return a.w > b.w;
	}
};

vector<int> d;
vector<bool> vis;
vector<vector<node>> g;

void dijkstra(int s) {
	fill(d.begin(), d.end(), INT_MAX);
	fill(vis.begin(), vis.end(), false);
	d[s] = 0;
	priority_queue<node> q;
	q.push({s, 0});
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		int u = t.v;
		if (d[u] < t.w) {
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v;
			if (!vis[v]) {
				if (d[u] + g[u][i].w < d[v]) {
					d[v] = d[u] + g[u][i].w;
					q.push({v, d[v]});
				}
			}
		}
	}
}

int main(int argc, char const *argv[]) {

	int nv, ne;
	cin >> nv >> ne;
	g.resize(nv + 1);
	for (int i = 0; i < ne; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		vector<int> p(nv);
		for (int i = 0; i < nv; i++) {
			cin >> p[i];
		}
		d.resize(nv + 1);
		vis.resize(nv + 1);
		dijkstra(p[0]);
		bool flag = true;
		for (int i = 1; i < nv; i++) {
			if (d[p[i]] < d[p[i - 1]]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	
	return 0;
}