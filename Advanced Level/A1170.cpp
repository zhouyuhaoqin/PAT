/*
*	author:		zhouyuhao
*	created:	2023-04-06 08:34:34
*	modified:	2023-04-06 08:49:05
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, r, k;
	cin >> n >> r >> k;
	vector<pair<int, int>> rel; 
	for (int i = 0; i < r; i++) {
		int a, b;
		cin >> a >> b;
		rel.push_back(make_pair(a, b));
	}
	int m;
	cin >> m;
	for (int q = 0; q < m; q++) {
		vector<int> d(n);
		set<int> s;
		for (int i = 0; i < n; i++) {
			cin >> d[i];
			s.insert(d[i]);
		}
		if (s.size() > k) {
			cout << "Error: Too many species.\n";
		} else if (s.size() < k) {
			cout << "Error: Too few species.\n";
		} else {
			bool issame = true;
			for (auto it : rel) {
				if (d[it.first - 1] == d[it.second - 1]) {
					issame = false;
				}
			}
			if (issame) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
	
	return 0;
}