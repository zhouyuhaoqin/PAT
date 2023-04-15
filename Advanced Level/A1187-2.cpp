/*
*	author:		zhouyuhao
*	created:	2023-04-13 20:48:13
*	modified:	2023-04-13 22:55:09
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int key, pri;
	node *lc, *rc;
};

bool cmp(node a, node b) {
	return a.pri < b.pri;
}

vector<node> t, level;

node* create(node* r, int i) {
	if (r == NULL) {
		r = new node; // new operator
		r->key = t[i].key;
		r->pri = t[i].pri;
		r->lc = r->rc = NULL;
		return r;
	}
	if (r->key > t[i].key) {
		r->lc = create(r->lc, i);
	} else {
		r->rc = create(r->rc, i);
	}
	return r;
}

void leveltra(node* r) {
	queue<node> q;
	q.push(*r); // pointer
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		level.push_back(t);
		if (t.lc != NULL) {
			q.push(*t.lc);
		}
		if (t.rc != NULL) {
			q.push(*t.rc);
		}
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	t.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> t[i + 1].key >> t[i + 1].pri;
	}
	sort(t.begin() + 1, t.end(), cmp); // +1
	node* r = NULL;
	for (int i = 1; i <= n; i++) {
		r = create(r, i);
	}
	leveltra(r);
	for (int i = 0; i < level.size(); i++) {
		cout << level[i].key;
		if (i < level.size() - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	for (int i = 0; i < level.size(); i++) {
		cout << level[i].pri;
		if (i < level.size() - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	
	return 0;
}