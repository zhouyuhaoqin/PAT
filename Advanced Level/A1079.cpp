/*
*	author:		zhouyuhao
*	created:	2023-03-29 11:21:26
*	modified:	2023-03-29 14:36:57
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double p, r, s = 0;
vector<double> a;
vector<vector<int> > t;

void dfs(int rr, int l) {
	if (t[rr].size() == 0) {
		s += p * pow(r, l) * a[rr];
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
	a.resize(n);
	for (int i = 0; i < n; i++) {
	    int k;
	    cin >> k;
	    if (k != 0) {
		    for (int j = 0; j < k; j++) {
		        int id;
		        cin >> id;
		        t[i].push_back(id);
		    }
	    } else {
	    	cin >> a[i];
	    }
	}
	dfs(0, 0);
	cout << fixed << setprecision(1) << s << "\n";

	return 0;
}