/*
*	author:		zhouyuhao
*	created:	2023-04-13 20:24:13
*	modified:	2023-04-13 20:48:04
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<set<int>> g;
vector<bool> vis;
vector<vector<int>> p;

void dfs(int ne, int st) {
	vis[ne] = true;
	p[st].push_back(ne);
	for (auto it : g[ne]) {
		if (!vis[it]) {
			dfs(it, st);
			return; // or break @important!
		}
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	g.resize(n + 1);
	vis.resize(n + 1);
	p.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	for (int i = 1; i <= n; i++) {
		fill(vis.begin(), vis.end(), false);
		dfs(i, i);
	}
	int st = 1, maxl = -1;
	for (int i = 1; i <= n; i++) {
		if ((int) p[i].size() > maxl) {
			maxl = p[i].size();
			st = i;
		}
	}
	cout << st << " " << maxl << "\n";
	
	return 0;
}