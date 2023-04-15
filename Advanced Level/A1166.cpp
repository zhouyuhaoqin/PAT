/*
*	author:		zhouyuhao
*	created:	2023-04-05 23:05:58
*	modified:	2023-04-05 23:24:39
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> r(n + 1, vector<bool> (n + 1));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		r[a][b] = r[b][a] = true;
	}
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		int l;
		cin >> l;
		vector<int> area(l);
		vector<bool> inarea(n + 1);
		for (int i = 0; i < l; i++) {
			cin >> area[i];
			inarea[area[i]] = true;
		}
		bool isfriend = true;
		for (auto ix : area) {
			for (auto iy : area) {
				if (ix != iy && !r[ix][iy]) {
					isfriend = false;
					break;
				}
			}
			if (!isfriend) {
				break;
			}
		}
		if (!isfriend) {
			cout << "Area " << q + 1 << " needs help.\n";
			continue;
		}
		int h = 0;
		for (int i = 1; i <= n; i++) {
			if (!inarea[i]) {
				bool hasmorefriend = true;
				for (auto it : area) {
					if (!r[i][it]) {
						hasmorefriend = false;
						break;
					}
				}
				if (hasmorefriend) {
					h = i;
					break;
				}
			}
		}
		if (h) {
			cout << "Area " << q + 1 << " may invite more people, such as "<< h << ".\n";
			continue;
		}
		cout << "Area " << q + 1 << " is OK.\n";
	}
	
	return 0;
}