/*
*	author:		zhouyuhao
*	created:	2023-03-26 22:10:10
*	modified:	2023-03-26 22:17:22
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<set<int> > s(n + 1);
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			s[i + 1].insert(num);
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		int count = 0;
		for (auto it : s[a]) {
			if (s[b].find(it) != s[b].end()) {
				count++;
			}
		}
		float r = float(count) / (s[a].size() + s[b].size() - count) * 100;
		cout << fixed << setprecision(1) << r << "%\n";
	}
	
	return 0;
}