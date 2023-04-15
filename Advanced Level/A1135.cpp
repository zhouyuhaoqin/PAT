/*
*	author:		zhouyuhao
*	created:	2023-04-04 00:44:58
*	modified:	2023-04-04 09:09:25
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
	int v, bh;
	node *lc, *rc;
};

vector<int> pre, in;

bool cmp(int a, int b) {
	return abs(a) < abs(b);
}

int getbh(node* r) {
	if (r == NULL) {
		return 0;
	} else {
		return r->bh;
	}
}

void updatebh(node* r) {
	r->bh = max(getbh(r->lc), getbh(r->rc));
	if (r->v > 0) {
		r->bh++;
	}
}

node* create(int r, int s, int e) {
	if (s > e) {
		return NULL;
	}
	node* root = new node;
	root->v = pre[r];
	if (root->v > 0) {
		root->bh = 1;
	}
	int i = s;
	while (s <= e && in[i] != pre[r]) {
		i++;
	}
	root->lc = create(r + 1, s, i - 1);
	updatebh(root); // updatebh(root->lc);
	root->rc = create(r + i - s + 1, i + 1, e);
	updatebh(root); // updatebh(root->rc);
	return root;
}

void dfs(node* root, bool &flag) {
	if (root->v < 0) {
		if (root->lc != NULL && root->lc->v < 0) {
			flag = false;
			return;
		}
		if (root->rc != NULL && root->rc->v < 0) {
			flag = false;
			return;
		}
	}
	if (getbh(root->lc) != getbh(root->rc)) {
		flag = false;
		return;
	}
	if (root->lc == NULL && root->rc == NULL) {
		return;
	}
	if (root->lc != NULL) {
		dfs(root->lc, flag);
	}
	if (root->rc != NULL) {
		dfs(root->rc, flag);
	}
}

int main(int argc, char const *argv[]) {

	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		int n;
		cin >> n;
		pre.resize(n);
		in.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> pre[i];
			in[i] = pre[i];
		}
		if (pre[0] < 0) {
			cout << "No\n";
			continue;
		}
		sort(in.begin(), in.end(), cmp);
		node* root = create(0, 0, n - 1);
		bool flag = true;
		dfs(root, flag);
		if (flag) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	
	return 0;
}