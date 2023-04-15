/*
*	author:		zhouyuhao
*	created:	2023-03-29 13:12:14
*	modified:	2023-03-29 15:00:45
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int h = 1;
map<int, int> cnt;
vector<vector<int> > t;

void dfs(int r, int l) {
	h = max(h, l);
	if (t[r].size() == 0) {
		cnt[l]++;
		return;
	}
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
	for (int i = 1; i <= h; i++) {
	    cout << cnt[i];
	    if (i <= h - 1) {
	        cout << " ";
	    } else {
	        cout << "\n";
	    }
	}

	return 0;
}