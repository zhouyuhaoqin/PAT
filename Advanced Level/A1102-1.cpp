/*
*	author:		zhouyuhao
*	created:	2023-03-28 22:20:41
*	modified:	2023-03-28 22:52:16
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int v, id;
	int lc, rc;
};

bool cmp(node a, node b) {
	return a.id < b.id;
}

vector<node> d;
vector<int> in;

void intra(int r, int i) {
	if (d[r].rc != -1) {
		intra(d[r].rc, 2 * i);
	}
	d[r].id = i;
	in.push_back(r);
	if (d[r].lc != -1) {
		intra(d[r].lc, 2 * i + 1);
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	d.resize(n);
	vector<bool> isroot(n);
	fill(isroot.begin(), isroot.end(), true);
	for (int i = 0; i < n; i++) {
		d[i].v = i;
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
	intra(r, 1);
	sort(d.begin(), d.end(), cmp);
	for (int i = 0; i < n; i++) {
	    cout << d[i].v;
	    if (i < n - 1) {
	        cout << " ";
	    } else {
	        cout << "\n";
	    }
	}
	for (int i = 0; i < n; i++) {
	    cout << in[i];
	    if (i < n - 1) {
	        cout << " ";
	    } else {
	        cout << "\n";
	    }
	}
	
	return 0;
}