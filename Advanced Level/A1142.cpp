/*
*	author:		zhouyuhao
*	created:	2023-04-04 13:13:21
*	modified:	2023-04-04 13:28:21
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>

using namespace std;

const int maxv = 201;

int e[maxv][maxv];

int main(int argc, char const *argv[]) {

	int nv, ne;
	cin >> nv >> ne;
	for (int i = 0; i < ne; i++) {
		int a, b;
		cin >> a >> b;
		e[a][b] = e[b][a] = 1;
	}
	int m;
	cin >> m;
	for (int q = 0; q < m; q++) {
		int k;
		cin >> k;
		vector<int> s(k);
		vector<bool> vis(nv);
		for (int i = 0; i < k; i++) {
			cin >> s[i];
			vis[s[i]] = true;
		}
		bool isclique = true;
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if (e[s[i]][s[j]] != 1) {
					isclique = false;
					break;
				}
			}
			if (!isclique) {
				break;
			}
		}
		if (!isclique) {
			cout << "Not a Clique\n";
			continue;
		}
		bool ismaximal = true;
		for (int i = 1; i <= nv; i++) {
			if (!vis[i]) {
				bool isconnected = true;
				for (int j = 0; j < k; j++) {
					if (e[i][s[j]] != 1) {
						isconnected = false;
						break;
					}
				}
				if (isconnected) {
					ismaximal = false;
					break;
				}
			}
		}
		if (!ismaximal) {
			cout << "Not Maximal\n";
			continue;
		}
		cout << "Yes\n";
	}
	
	return 0;
}