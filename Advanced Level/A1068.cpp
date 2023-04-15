/*
*	author:		zhouyuhao
*	created:	2023-04-12 14:38:00
*	modified:	2023-04-12 15:25:37
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i + 1];
	}
	sort(v.begin() + 1, v.end(), greater<int> ());
	vector<int> dp(m + 1);
	vector<vector<bool>> c(n + 1, vector<bool> (m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= v[i]; j--) {
			if (dp[j] <= dp[j - v[i]] + v[i]) {
			// if (dp[j] < dp[j - v[i]] + v[i]) { not the smallest sequence
				dp[j] = dp[j - v[i]] + v[i];
				c[i][j] = true;
			}
		}
	}
	if (dp[m] != m) {
		cout << "No Solution\n";
	} else {
		vector<int> ans;
		for (int i = n; i >= 1; i--) {
			if (c[i][m]) {
				ans.push_back(i);
				m -= v[i];
			}
		}
		for (int i = 0; i < ans.size(); i++) {
			cout << v[ans[i]];
			if (i < ans.size() - 1) {
				cout << " ";
			} else {
				cout << "\n";
			}
		}
	}
	
	return 0;
}