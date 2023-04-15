/*
*	author:		zhouyuhao
*	created:	2023-03-29 13:18:41
*	modified:	2023-03-29 16:43:01
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

bool cmp(vector<int> a, vector<int> b) {
	for (int i = 0; i < min(a.size(), b.size()); i++) {
		if (a[i] != b[i]) {
			return a[i] > b[i];
		}
	}
}

void dfs(int r, int sum, int l) {
	temp.resize(l + 1);
	temp[l] = w[r];
	sum += w[r];
	if (t[r].size() == 0) {
		if (sum == s) {
			ans.push_back(temp);
		}
		return;
	}
	if (sum > s) {
		return;
	}
	for (int i = 0; i < t[r].size(); i++) {
		dfs(t[r][i], sum, l + 1);
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
	dfs(r, 0, 0);
	sort(ans.begin(), ans.end(), cmp);
	// sort(ans.begin(), ans.end(), greater<vector<int> > ());
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