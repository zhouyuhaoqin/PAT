/*
*	author:		zhouyuhao
*	created:	2023-03-30 14:31:33
*	modified:	2023-03-30 14:33:09
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int maxl = -1;
vector<bool> vis;
vector<int> temp;
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

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	g.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int s, e;
		cin >> s >> e;
		g[s].push_back(e);
		g[e].push_back(s);
	}
	vis.resize(n + 1);
	fill(vis.begin(), vis.end(), false);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt++;
			dfs(i, 1);
		}
	}
	if (cnt == 1) {
		fill(vis.begin(), vis.end(), false);
		dfs(1, 1);
		set<int> ans;
		for (auto it : temp) {
			ans.insert(it);
		}
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