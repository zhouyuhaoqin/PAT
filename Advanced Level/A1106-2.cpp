/*
*	author:		zhouyuhao
*	created:	2023-03-29 14:53:34
*	modified:	2023-03-29 14:57:36
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <iomanip>

using namespace std;

int cnt = 0, ll = INT_MAX;
vector<vector<int> > t;

void dfs(int rr, int l) {
	if (l > ll) {
		return;
	}
	if (t[rr].size() == 0) {
		if (l < ll) {
			ll = l;
			cnt = 1;
		} else if (l == ll) {
			cnt++;
		}
		return;
	}
	for (int i = 0; i < t[rr].size(); i++) {
		dfs(t[rr][i], l + 1);
	}
}

int main(int argc, char const *argv[]) {

	int n;
	double p, r;
	cin >> n >> p >> r;
	r = r / 100 + 1;
	t.resize(n);
	vector<bool> isroot(n);
	fill(isroot.begin(), isroot.end(), true);
	for (int i = 0; i < n; i++) {
	    int k;
	    cin >> k;
    	for (int j = 0; j < k; j++) {
    		int id;
    		cin >> id;
    		t[i].push_back(id);
    		isroot[id] = false;
    	}
	}
	int rr = -1;
	for (int i = 0; i < n; i++) {
		if (isroot[i]) {
			rr = i;
			break;
		}
	}
	dfs(rr, 0);
	cout << fixed << setprecision(4) << p * pow(r, ll) << " " << cnt << "\n";

	return 0;
}