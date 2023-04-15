/*
*	author:		zhouyuhao
*	created:	2023-03-28 22:14:12
*	modified:	2023-03-28 22:18:33
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

struct node {
	int v;
	node *lc, *rc;
};

vector<int> pre, in, ans;

node *create(int r, int s, int e) {
	if (s > e) {
		return NULL;
	}
	int i = s;
	while (i <= e && in[i] != pre[r]) {
		i++;
	}
	node *root = new node;
	root->lc = create(r + 1, s, i - 1);
	root->rc = create(r + i - s + 1, i + 1, e);
	root->v = pre[r];
	return root;
}

void post(node *r) {
	if (r->lc != NULL) {
		post(r->lc);
	}
	if (r->rc != NULL) {
		post(r->rc);
	}
	ans.push_back(r->v);
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < 2 * n; i++) {
	    string ss;
	    cin >> ss;
	    if (ss.size() == 4) {
	    	int num;
	    	cin >> num;
	    	s.push(num);
	    	pre.push_back(num);
	    } else {
	    	in.push_back(s.top());
	    	s.pop();
	    }
	}
	node *r = create(0, 0, n - 1);
	post(r);
	for (int i = 0; i < n; i++) {
	    cout << ans[i];
	    if (i < n - 1) {
	        cout << " ";
	    } else {
	        cout << "\n";
	    }
	}
	
	return 0;
}