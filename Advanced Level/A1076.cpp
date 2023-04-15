/*
*	author:		zhouyuhao
*	created:	2023-03-30 15:54:25
*	modified:	2023-03-30 16:21:10
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>

using namespace std;

vector<bool> vis;
vector<int> level;
vector<vector<int>> g;

int bfs(int s, int l) {
	int cnt = 0;
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < g[t].size(); i++) {
			if (level[g[t][i]] == 0) {
				level[g[t][i]] = level[t] + 1;
			}
			if (!vis[g[t][i]] && level[g[t][i]] <= l) {
				q.push(g[t][i]);
				vis[g[t][i]] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main(int argc, char const *argv[]) {
	
	int n, l;
	cin >> n >> l;
	g.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int id;
			cin >> id;
			g[id].push_back(i + 1);
		}
	}
	int k;
	cin >> k;
	vis.resize(n + 1);
	level.resize(n + 1);
	for (int q = 0; q < k; q++) {
		int id;
		cin >> id;
		fill(vis.begin(), vis.end(), false);
		fill(level.begin(), level.end(), 0);
		level[id] = 0;
		cout << bfs(id, l) << "\n";
	}
	
	return 0;
}