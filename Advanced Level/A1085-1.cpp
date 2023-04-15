/*
*	author:		zhouyuhao
*	created:	2023-03-27 10:46:47
*	modified:	2023-03-27 10:53:12
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, p;
	cin >> n >> p;
	vector<long long int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	int ans = 1;
	for (int i = 0; i < n; i++) {
		int j = upper_bound(d.begin(), d.end(), d[i] * p) - d.begin();
		ans = max(ans, j - i);
	}
	cout << ans << "\n";
	
	return 0;
}