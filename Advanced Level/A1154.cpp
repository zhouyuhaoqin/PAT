/*
*	author:		zhouyuhao
*	created:	2023-04-04 20:46:37
*	modified:	2023-04-04 21:01:01
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct edge {
	int st, en;
};

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<edge> g;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g.push_back({a, b});
	}
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		vector<int> c(n);
		set<int> color;
		for (int i = 0; i < n; i++) {
			cin >> c[i];
			color.insert(c[i]);
		}
		bool iscoloring = true;
		for (auto it : g) {
			if (c[it.st] == c[it.en]) {
				iscoloring = false;
				break;
			}
		}
		if (iscoloring) {
			cout << color.size() << "-coloring\n";
		} else {
			cout << "No\n";
		}
	}
	
	return 0;
}