/*
*	author:		zhouyuhao
*	created:	2023-03-30 13:46:48
*	modified:	2023-03-30 14:31:26
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int maxl = -1;
vector<bool> vis;
vector<int> f, temp;
set<int> ans;
vector<vector<int>> g;

void dfs(int s, int l) {
	vis[s] = true;
	if (l > maxl) {
		maxl = l;
		temp.clear();
		temp.push_back(s);
	} else if (l == maxl) {
		temp.push_back(s);
	}
	for (int i = 0; i < g[s].size(); i++) {
		if (!vis[g[s][i]]) {
			dfs(g[s][i], l + 1);
		}
	}
}

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

	int n;
	cin >> n;
	g.resize(n + 1);
	vis.resize(n + 1);
	f.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		f[i] = i;
		vis[i] = false;
	}
	for (int i = 0; i < n - 1; i++) {
		int s, e;
		cin >> s >> e;
		g[s].push_back(e);
		g[e].push_back(s);
		joint(s, e);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[find(i)]) {
			cnt++;
			vis[find(i)] = true;
		}
	}
	if (cnt == 1) {
		fill(vis.begin(), vis.end(), false);
		dfs(1, 1);
		set<int> ans;
		for (auto it : temp) {
			ans.insert(it);
		}
		// maxl = -1;
		// temp.clear();
		fill(vis.begin(), vis.end(), false);
		dfs(temp[0], 1);
		for (auto it : temp) {
			ans.insert(it);
		}
		for (auto it : ans) {
			cout << it << "\n";
		}
	} else {
		cout << "Error: " << cnt << " components\n";
	}
	
	return 0;
}