/*
*	author:		zhouyuhao
*	created:	2023-03-26 21:58:13
*	modified:	2023-03-27 16:16:55
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<vector<string> > s(k);
	for (int i = 0; i < n; i++) {
		string name;
		int nc;
		cin >> name >> nc;
		for (int j = 0; j < nc; j++) {
			int no;
			cin >> no;
			s[no - 1].push_back(name);
		}
	}
	for (int i = 0; i < k; i++) {
		cout << i + 1 << " " << s[i].size() << "\n";
		sort(s[i].begin(), s[i].end());
		for (auto it : s[i]) {
			cout << it << "\n";
		}
	}
	
	return 0;
}