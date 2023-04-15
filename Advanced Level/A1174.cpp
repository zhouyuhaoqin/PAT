/*
*	author:		zhouyuhao
*	created:	2023-04-14 14:35:28
*	modified:	2023-04-14 14:59:21
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> pre, ans;
map<int, int> in;
map<int, bool> vis;

void pretra(int r, int s, int e, int l) {
	if (s > e) {
		return;
	}
	if (!vis[l]) {
		vis[l] = true;
		ans.push_back(pre[r]);
	}
	int i = in[pre[r]];
	pretra(r + 1, s, i - 1, l + 1);
	pretra(r + i - s + 1, i + 1, e, l + 1);
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	pre.resize(n);
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		in[v] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	pretra(0, 0, n - 1, 0);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i < ans.size() - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	
	return 0;
}