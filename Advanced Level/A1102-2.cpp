/*
*	author:		zhouyuhao
*	created:	2023-03-28 22:52:29
*	modified:	2023-03-28 23:22:01
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int id;
	int lc, rc;
};

vector<node> d;
vector<int> level, in;

void posttra(int r) {
	if (r == -1){
		return;
	}
	posttra(d[r].lc);
	posttra(d[r].rc);
	swap(d[r].lc, d[r].rc);
}

void bfs(int r) {
	queue<int> s;
	s.push(r);
	while (!s.empty()) {
		int t = s.front();
		s.pop();
		level.push_back(t);
		if (d[t].lc != -1) {
			s.push(d[t].lc);
		}
		if (d[t].rc != -1) {
			s.push(d[t].rc);
		}
	}
}

void intra(int r) {
	if (d[r].lc != -1) {
		intra(d[r].lc);
	}
	in.push_back(r);
	if (d[r].rc != -1) {
		intra(d[r].rc);
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
	posttra(r);
	bfs(r);
	intra(r);
	for (int i = 0; i < n; i++) {
	    cout << level[i];
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