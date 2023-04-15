/*
*	author:		zhouyuhao
*	created:	2023-03-28 13:12:18
*	modified:	2023-03-28 15:55:19
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, k, p;
int mfs = -1;
vector<int> fp(1), temp, ans;

void dfs(int f, int i, int fs, int sum) {
	if (i == k) {
		if (sum == n && fs > mfs) {
			mfs = fs;
			ans = temp;
		}
		return;
	}
	while (f >= 1) {
		if (sum + fp[f] <= n) {
			temp[i] = f;
			dfs(f, i + 1, fs + f, sum + fp[f]);
		}
		f--;
	}
}

int main(int argc, char const *argv[]) {

	cin >> n >> k >> p;
	int e = 1;
	while (pow(e, p) <= n) {
		fp.push_back(pow(e, p));
		e++;
	}
	temp.resize(k);
	dfs(e - 1, 0, 0, 0);
	if (mfs != -1) {
		cout << n << " = " << ans[0] << "^" << p;
		for (int i = 1; i < ans.size(); i++) {
			cout << " + " << ans[i] << "^" << p;
		}
		cout << "\n";
	} else {
		cout << "Impossible\n";
	}
	
	return 0;
}