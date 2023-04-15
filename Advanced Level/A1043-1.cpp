/*
*	author:		zhouyuhao
*	created:	2023-03-29 14:14:51
*	modified:	2023-03-29 18:48:45
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>

using namespace std;

struct node {
	int v;
	node *lc, *rc;
};

void insert(node* &r, int v) {
	if (r == NULL) {
		r = new node;
		r->v = v;
		r->lc = r->rc = NULL;
		return;
	}
	if (v < r->v) {
		insert(r->lc, v);
	} else {
		insert(r->rc, v);
	}
}

void pre(node *r, vector<int> &d) {
	if (r == NULL) {
		return;
	}
	d.push_back(r->v);
	pre(r->lc, d);
	pre(r->rc, d);
}

void prem(node *r, vector<int> &d) {
	if (r == NULL) {
		return;
	}
	d.push_back(r->v);
	prem(r->rc, d);
	prem(r->lc, d);
}

void post(node *r, vector<int> &d) {
	if (r == NULL) {
		return;
	}
	post(r->lc, d);
	post(r->rc, d);
	d.push_back(r->v);
}

void postm(node *r, vector<int> &d) {
	if (r == NULL) {
		return;
	}
	postm(r->rc, d);
	postm(r->lc, d);
	d.push_back(r->v);
}

void print(vector<int> d) {
	for (int i = 0; i < d.size(); i++) {
		cout << d[i];
		if (i < d.size() - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
}

vector<int> d, dpre, dprem, dpost, dpostm;

int main(int argc, char const *argv[]) {	
	
	int n;
	cin >> n;
	node* r = NULL;
	d.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		insert(r, d[i]);
	}
	pre(r, dpre);
	prem(r, dprem);
	post(r, dpost);
	postm(r, dpostm);
	if (d == dpre) {
		cout << "YES\n";
		print(dpost);
	} else if (d == dprem) {
		cout << "YES\n";
		print(dpostm);
	} else {
		cout << "NO\n";
	}

	return 0;
}