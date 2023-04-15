/*
*	author:		zhouyuhao
*	created:	2023-03-29 15:00:01
*	modified:	2023-03-29 15:12:48
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int hh = -1;
vector<int> h;
map<int, int> cnt;
vector<vector<int> > t;

void bfs(int r) {
	queue<int> q;
	q.push(r);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		hh = max(hh, h[now]);
		if (t[now].size() == 0) {
			cnt[h[now]]++;
		}
		for (int i = 0; i < t[now].size(); i++) {
			h[t[now][i]] = h[now] + 1;
			q.push(t[now][i]);
		}
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
	h.resize(n);
	h[r] = 1;
	bfs(r);
	for (int i = 1; i <= hh; i++) {
	    cout << cnt[i];
	    if (i <= hh - 1) {
	        cout << " ";
	    } else {
	        cout << "\n";
	    }
	}

	return 0;
}