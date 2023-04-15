/*
*	author:		zhouyuhao
*	created:	2023-04-04 13:28:41
*	modified:	2023-04-04 14:12:36
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node {
	int v;
	node *lc, *rc;
};

vector<int> pre, in;
map<int, bool> exist;
map<int, int> loc;

node* create(node* root, int r, int s, int e) {
	if (s > e) {
		return NULL;
	}
	root = new node;
	root->v = pre[r];
	int i = loc[pre[r]];
	root->lc = create(root->lc, r + 1, s, i - 1);
	root->rc = create(root->rc, r + i - s + 1, i + 1, e);
	return root;
}

void dfs(node* root, int u, int v, int &lca) {
	if (root == NULL) {
		return;
	}
	if (root->v > u && root->v <= v) {
		lca = root->v;
		return;
	} else if (root->v == u && root->v <= v) {
		lca = root->v;
		return;
	}
	if (v < root->v) {
		dfs(root->lc, u, v, lca);
	}
	if (u >= root->v) {
		dfs(root->rc, u, v, lca);
	}
	// dfs(root->lc, u, v, lca);
	// dfs(root->rc, u, v, lca);
}

int main(int argc, char const *argv[]) {

	int m, n;
	cin >> m >> n;
	pre.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
		in.push_back(pre[i]);
		exist[pre[i]] = true;
	}
	sort(in.begin(), in.end());
	for (int i = 0; i < n; i++) {
		loc[in[i]] = i;
	}
	node* root = NULL;
	root = create(root, 0, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (exist[u] && exist[v]) {
			int a = u, b = v;
			if (a > b) {
				swap(a, b);
			}
			int lca = -1;
			dfs(root, a, b, lca);
			// cout << lca << "\n";
			if (lca != u && lca != v) {
				cout << "LCA of " << u << " and " << v << " is " << lca << ".\n";
			} else if (lca == u && lca != v) {
				cout << u << " is an ancestor of " << v << ".\n";
			} else {
			// } else if (lca != u && lca == v) {
				cout << v << " is an ancestor of " << u << ".\n";
			}
		} else if (exist[u] && !exist[v]) {
			cout << "ERROR: " << v << " is not found.\n";
		} else if (!exist[u] && exist[v]) {
			cout << "ERROR: " << u << " is not found.\n";
		} else {
			cout << "ERROR: " << u << " and " << v << " are not found.\n";
		}
	}
	
	return 0;
}