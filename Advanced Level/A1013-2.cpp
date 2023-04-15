/*
*	author:		zhouyuhao
*	created:	2023-03-30 13:32:42
*	modified:	2023-03-30 13:45:37
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>

using namespace std;

vector<bool> vis;
vector<int> f;
vector<vector<int>> g;

int find(int x) {
	int t = x;
	while (x != f[x]) {
		x = f[x];
	}
	while (t != f[t]) {
		int tt = t;
		t = f[t];
		f[tt] = x;
	}
	return x;
}

void joint(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if (fa != fb) {
		f[fa] = fb;
	}
}

int main(int argc, char const *argv[]) {

	int n, m, k;
	cin >> n >> m >> k;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		g[s].push_back(e);
		g[e].push_back(s);
	}
	vis.resize(n + 1);
	f.resize(n + 1);
	for (int q = 0; q < k; q++) {
		int id;
		cin >> id;
		for (int i = 0; i <= n; i++) {
			f[i] = i;
			vis[i] = false;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < g[i].size(); j++) {
				int u = i, v = g[i][j];
				if (u != id && v != id) {
					joint(u, v);
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (i != id && !vis[find(i)]) {
				cnt++;
				vis[find(i)] = true;
			}
		}
		cout << cnt - 1 << "\n";
	}
	
	return 0;
}