/*
*	author:		zhouyuhao
*	created:	2023-03-30 14:36:06
*	modified:	2023-03-31 14:06:38
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<bool> vis;
vector<int> pw;
vector<vector<int>> g, w, ans;

void dfs(vector<int> &temp, int s) {
	vis[s] = true;
	temp.push_back(s);
	for (int i = 0; i < g[s].size(); i++) {
		if (!vis[g[s][i]]) {
			dfs(temp, g[s][i]);
		}
	}
}

int cnt = 1;
map<string, int> mid;
map<int, string> mstr;
void getid(string s) {
	if (mid[s] == 0) {
		mid[s] = cnt;
		mstr[cnt] = s;
		cnt++;
	}
}

bool cmp(int a, int b) {
	if (pw[a] != pw[b]) {
		return pw[a] > pw[b];
	} else {
		return mstr[a] < mstr[b];
	}
}

int main(int argc, char const *argv[]) {

	int n, k;
	cin >> n >> k;
	vector<vector<int>> d(n);
	for (int i = 0; i < n; i++) {
		string n1, n2;
		int t;
		cin >> n1 >> n2 >> t;
		getid(n1);
		getid(n2);
		d[i].push_back(mid[n1]);
		d[i].push_back(mid[n2]);
		d[i].push_back(t);
	}
	g.resize(cnt);
	w.resize(cnt);
	for (int i = 0; i < cnt; i++) {
		w[i].resize(cnt);
	}
	pw.resize(cnt);
	for (int i = 0; i < n; i++) {
		g[d[i][0]].push_back(d[i][1]);
		g[d[i][1]].push_back(d[i][0]);
		w[d[i][0]][d[i][1]] += d[i][2];
		w[d[i][1]][d[i][0]] += d[i][2];
		pw[d[i][0]] += d[i][2];
		pw[d[i][1]] += d[i][2];
	}
	vis.resize(cnt);
	fill(vis.begin(), vis.end(), false);
	for (int i = 1; i <= cnt - 1; i++) {
		if (!vis[i]) {
			vector<int> temp;
			dfs(temp, i);
			ans.push_back(temp);
		}
	}
	map<string, int> gang;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].size() > 2) {
			int sum = 0;
			for (int j = 0; j < ans[i].size(); j++) {
				for (int k = j + 1; k < ans[i].size(); k++) {
					sum += w[ans[i][j]][ans[i][k]];
				}
			}
			// for (int j = 0; j < ans[i].size(); j++) {
			// 	sum += w[ans[i][j]][ans[i][(j + 1) % ans[i].size()]];
			// }
			if (sum > k) {
				sort(ans[i].begin(), ans[i].end(), cmp);
				gang[mstr[ans[i][0]]] = ans[i].size();
			}
		}
	}
	cout << gang.size() << "\n";
	for (auto it : gang) {
		cout << it.first << " " << it.second << "\n";
	}
	
	return 0;
}