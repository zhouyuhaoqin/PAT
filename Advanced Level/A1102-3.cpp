/*
*	author:		zhouyuhao
*	created:	2023-03-28 23:24:10
*	modified:	2023-03-28 23:33:21
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int v;
	int lc, rc;
	int l, i;
};

bool cmp(node a, node b) {
	if (a.l != b.l) {
		return a.l < b.l;
	} else {
		return a.i > b.i;
	}
}

vector<node> d, in;

void dfs(int r, int l, int i) {
	if (d[r].rc != -1) {
		dfs(d[r].rc, l + 1, 2 * i + 1);
	}
	in.push_back({r, -1, -1, l, i});
	if (d[r].lc != -1) {
		dfs(d[r].lc, l + 1, 2 * i);
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	d.resize(n);
	vector<bool> isroot(n);
	fill(isroot.begin(), isroot.end(), true);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (isdigit(c)) {
			d[i].lc = c - '0';
			isroot[d[i].lc] = false;
		} else {
			d[i].lc = -1;
		}
		cin >> c;
		if (isdigit(c)) {
			d[i].rc = c - '0';
			isroot[d[i].rc] = false;
		} else {
			d[i].rc = -1;
		}
	}
	int r = -1;
	for (int i = 0; i < n; i++) {
		if (isroot[i]) {
			r = i;
			break;
		}
	}
	dfs(r, 1, 1);
	vector<node> level(in);
	sort(level.begin(), level.end(), cmp);
	for (int i = 0; i < n; i++) {
	    cout << level[i].v;
	    if (i < n - 1) {
	        cout << " ";
	    } else {
	        cout << "\n";
	    }
	}
	for (int i = 0; i < n; i++) {
	    cout << in[i].v;
	    if (i < n - 1) {
	        cout << " ";
	    } else {
	        cout << "\n";
	    }
	}
	
	return 0;
}