/*
*	author:		zhouyuhao
*	created:	2023-03-29 16:09:30
*	modified:	2023-03-29 16:47:59
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int s;
vector<int> w, temp;
vector<vector<int> > t, ans;

void dfs(int r, int sum) {
	if (sum > s) {
		return;
	}
	if (sum == s) {
		if (t[r].size() != 0) {
			return;
		}
		ans.push_back(temp);
		return;
	}
	for (int i = 0; i < t[r].size(); i++) {
		temp.push_back(w[t[r][i]]);
		dfs(t[r][i], sum + w[t[r][i]]);
		temp.pop_back();
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m >> s;
	w.resize(n);
	for (int i = 0; i < n; i++) {
	    cin >> w[i];
	}
	t.resize(n);
	vector<bool> isroot(n);
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
	for (int i = 0; i < n; i++) {
	    if (isroot[i]) {
	    	r = i;
	    	break;
	    }
	}
	temp.push_back(w[r]);
	dfs(r, w[r]);
	sort(ans.begin(), ans.end(), greater<vector<int> > ());
	for (auto it : ans) {
		for (int i = 0; i < it.size(); i++) {
		    cout << it[i];
		    if (i < it.size() - 1) {
		        cout << " ";
		    } else {
		        cout << "\n";
		    }
		}
	}

	return 0;
}