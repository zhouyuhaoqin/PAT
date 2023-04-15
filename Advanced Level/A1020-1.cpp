/*
*	author:		zhouyuhao
*	created:	2023-03-28 17:21:19
*	modified:	2023-03-28 21:38:44
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int v, i;
};

bool cmp(node a, node b) {
	return a.i < b.i;
}

vector<int> post, in;
vector<node> level;

void pre(int r, int s, int e, int i) {
	if (s > e) {
		return;
	}
	level.push_back({post[r], i});
	int j = s;
	while (j <= e && in[j] != post[r]) {
		j++;
	}
	pre(r - e + j - 1, s, j - 1, 2 * i);
	pre(r - 1, j + 1, e, 2 * i + 1);
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
	pre(n - 1, 0, n - 1, 1);
	sort(level.begin(), level.end(), cmp);
	for (int i = 0; i < n; i++) {
	    cout << level[i].v;
	    if (i < n - 1) {
	        cout << " ";
	    } else {
	        cout << "\n";
	    }
	}
	
	return 0;
}