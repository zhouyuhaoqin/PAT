/*
*	author:		zhouyuhao
*	created:	2023-03-29 12:45:43
*	modified:	2023-03-29 14:49:47
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

map<int, int> cnt;
vector<vector<int> > t;

typedef pair<int, int> PAIR;
bool cmp(const PAIR &a, const PAIR &b) {
	return a.second > b.second;
}

void dfs(int r, int l) {
	cnt[l]++;
	// if (t[r].size() == 0) {
	// 	return;
	// }
	for (int i = 0; i < t[r].size(); i++) {
		dfs(t[r][i], l + 1);
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	t.resize(n + 1);
	vector<bool> isroot(n + 1);
	fill(isroot.begin(), isroot.end(), true);
	for (int i = 0; i < m; i++) {
		int id, k;
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			int c;
			cin >> c;
			t[id].push_back(c);
			isroot[c] = false;
		}
	}
	int r = -1;
	for (int i = 1; i <= n; i++) {
	    if (isroot[i]) {
	    	r = i;
	    	break;
	    }
	}
	dfs(r, 1);
	vector<PAIR> ans(cnt.begin(), cnt.end());
	sort(ans.begin(), ans.end(), cmp);
	cout << ans[0].second << " " << ans[0].first << "\n";

	return 0;
}