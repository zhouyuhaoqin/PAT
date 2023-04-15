/*
*	author:		zhouyuhao
*	created:	2023-03-29 21:35:37
*	modified:	2023-03-29 22:06:17
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int v, h;
	node *lc, *rc;
} *r;

node *newn(int v) {
	node *p = new node;
	p->v = v;
	p->h = 1;
	p->lc = p->rc = NULL;
	return p;
}

int geth(node *r) {
	if (r == NULL) {
		return 0;
	} else {
		return r->h;
	}
}

void updateh(node *r) {
	r->h = max(geth(r->lc), geth(r->rc)) + 1;
}

int getbf(node *r) {
	return geth(r->lc) - geth(r->rc);
}

node *connect34(node *a, node *b, node *c, 
	node *t0, node *t1, node *t2, node *t3) {
	a->lc = t0;
	a->rc = t1;
	updateh(a);
	c->lc = t2;
	c->rc = t3;
	updateh(c);
	b->lc = a;
	b->rc = c;
	updateh(b);
	return b;
}

void insert(node* &r, int v) {
	if (r == NULL) {
		r = newn(v);
		return;
	}
	if (v < r->v) {
		insert(r->lc, v);
		updateh(r);
		if (getbf(r) == 2) {
			if (getbf(r->lc) == 1) {
				r = connect34(r->lc->lc, r->lc, r, 
					r->lc->lc->lc, r->lc->lc->rc, r->lc->rc, r->rc);
			} else if (getbf(r->lc) == -1) {
				r = connect34(r->lc, r->lc->rc, r, 
					r->lc->lc, r->lc->rc->lc, r->lc->rc->rc, r->rc);
			}
		}
	} else {
		insert(r->rc, v);
		updateh(r);
		if (getbf(r) == -2) {
			if (getbf(r->rc) == 1) {
				r = connect34(r, r->rc->lc, r->rc, 
					r->lc, r->rc->lc->lc, r->rc->lc->rc, r->rc->rc);
			} else if (getbf(r->rc) == -1) {
				r = connect34(r, r->rc, r->rc->rc, 
					r->lc, r->rc->lc, r->rc->rc->lc, r->rc->rc->rc);
			}
		}
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		insert(r, v);
	}
	cout << r->v << "\n";
	
	return 0;
}