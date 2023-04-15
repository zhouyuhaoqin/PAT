/*
*	author:		zhouyuhao
*	created:	2023-03-29 12:29:53
*	modified:	2023-03-29 14:40:10
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int cnt = 0;
double p, r, ms = -1;
vector<vector<int> > t;

void dfs(int rr, int l) {
	if (t[rr].size() == 0) {
		if (p * pow(r, l) > ms) {
			ms = p * pow(r, l);
			cnt = 1;
		} else if (p * pow(r, l) == ms) {
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
	cin >> n >> p >> r;
	r = r / 100 + 1;
	t.resize(n);
	int rr = -1;
	for (int i = 0; i < n; i++) {
	    int k;
	    cin >> k;
	    if (k == -1) {
	    	rr = i;
	    } else {
	    	t[k].push_back(i);
	    }
	}
	dfs(rr, 0);
	cout << fixed << setprecision(2) << ms << " " << cnt << "\n";

	return 0;
}