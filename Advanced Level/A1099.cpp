/*
*	author:		zhouyuhao
*	created:	2023-03-29 20:39:04
*	modified:	2023-03-29 21:05:33
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int v, l, i;
	int lc, rc;
};

bool cmp(node a, node b) {
	if (a.l != b.l) {
		return a.l < b.l;
	} else {
		return a.i < b.i;
	}
}

vector<node> t;
vector<int> in;
int n, front = 0;

void intra(int r, int l, int i) {
	if (r == -1 || r >= n) {
		return;
	}
	intra(t[r].lc, l + 1, 2 * i + 1);
	t[r].v = in[front++];
	t[r].l = l;
	t[r].i = i;
	intra(t[r].rc, l + 1, 2 * i + 2);
}

vector<int> ans;
void bfs(int r) {
	queue<int> q;
	q.push(r);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		ans.push_back(t[now].v);
		if (t[now].lc != -1) {
			q.push(t[now].lc);
		}
		if (t[now].rc != -1) {
			q.push(t[now].rc);
		}
	}
}

int main(int argc, char const *argv[]) {

	cin >> n;
	t.resize(n);
	vector<bool> isroot(n);
	fill(isroot.begin(), isroot.end(), true);
	for (int i = 0; i < n; i++) {
		cin >> t[i].lc >> t[i].rc;
		if (t[i].lc != -1) {
			isroot[t[i].lc] = false;
		}
		if (t[i].rc != -1) {
			isroot[t[i].rc] = false;
		}
	}
	int r = -1;
	for (int i = 0; i < n; i++) {
		if (isroot[i]) {
			r = i;
			break;
		}
	}
	in.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	sort(in.begin(), in.end());
	intra(r, 1, 0);
	// sort(t.begin(), t.end(), cmp);
	// for (int i = 0; i < n; i++) {
	// 	cout << t[i].v;
	// 	if (i < n - 1) {
	// 		cout << " ";
	// 	} else {
	// 		cout << "\n";
	// 	}
	// }
	bfs(r);
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