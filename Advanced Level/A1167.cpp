/*
*	author:		zhouyuhao
*	created:	2023-04-05 23:24:58
*	modified:	2023-04-05 23:55:14
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node {
	int v, i, l;
	node *lc, *rc;
};

bool cmp(node a, node b) {
	if (a.l != b.l) {
		return a.l < b.l;
	} else {
		return a.i < b.i;
	}
}

vector<int> in, temp;
map<int, int> loc;
vector<node> ans;

node* create(node* root, int l, int r, int i, int h) {
	if (l > r) { // segmentation fault
		return NULL;
	}
	temp.assign(in.begin() + l, in.begin() + r + 1);
	sort(temp.begin(), temp.end());
	int m = loc[temp[0]];
	root = new node;
	root->v = temp[0];
	root->i = i;
	root->l = h;
	root->lc = create(root->lc, l, m - 1, 2 * i + 1, h + 1);
	root->rc = create(root->rc, m + 1, r, 2 * i + 2, h + 1);
	ans.push_back(*root); //*
	return root;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	in.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		loc[in[i]] = i;
	}
	node* root = NULL;
	root = create(root, 0, n - 1, 0, 1);
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].v;
		if (i < ans.size() - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	
	return 0;
}