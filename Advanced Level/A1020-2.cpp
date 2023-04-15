/*
*	author:		zhouyuhao
*	created:	2023-03-28 21:39:33
*	modified:	2023-03-28 22:01:10
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>

using namespace std;

struct node {
	int v;
	node *lc, *rc;
};

vector<int> post, in, level;

// node *create(int r, int s, int e) {
// 	if (s > e) {
// 		return NULL;
// 	}
// 	node *root = new node;
// 	root->v = post[r];
// 	int i = s;
// 	while (s <= e && in[i] != post[r]) {
// 		i++;
// 	}
// 	root->lc = create(r - e + i - 1, s, i - 1);
// 	root->rc = create(r - 1, i + 1, e);
// 	// root->rc = create(r - e + i, i + 1, e);
// 	return root;
// }

node *create(int pl, int pr, int il, int ir) {
	if (pl > pr) {
		return NULL;
	}
	node *r = new node;
	r->v = post[pr];
	int i = il;
	while (il <= ir && in[i] != post[pr]) {
		i++;
	}
	r->lc = create(pl, pr - ir + i - 1, il, i - 1);
	// r->rc = create(pr - ir + i + 1, pr - 1, i + 1, ir);
	r->rc = create(pr - ir + i, pr - 1, i + 1, ir);
	// r->lc = create(pl, pl + i - il - 1, il, i - 1);
	// r->rc = create(pl + i - il, pr - 1, i + 1, ir);
	return r;
}

void bfs(node *r) {
	queue<node *> q;
	q.push(r);
	while (!q.empty()) {
		node *t = q.front();
		q.pop();
		level.push_back(t->v);
		if (t->lc != NULL) {
			q.push(t->lc);
		}
		if (t->rc != NULL) {
			q.push(t->rc);
		}
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	post.resize(n);
	for (int i = 0; i < n; i++) {
	    cin >> post[i];
	}
	in.resize(n);
	for (int i = 0; i < n; i++) {
	    cin >> in[i];
	}
	// node *r = create(n - 1, 0, n - 1);
	node *r = create(0, n - 1, 0, n - 1);
	bfs(r);
	for (int i = 0; i < n; i++) {
	    cout << level[i];
	    if (i < n - 1) {
	        cout << " ";
	    } else {
	        cout << "\n";
	    }
	}
	
	return 0;
}