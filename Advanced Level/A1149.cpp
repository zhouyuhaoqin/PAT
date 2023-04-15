/*
*	author:		zhouyuhao
*	created:	2023-04-04 17:03:57
*	modified:	2023-04-04 17:23:06
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int maxn = 1e5;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	map<int, bool> dan;
	map<int, bool> isdan;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		dan[a * maxn + b] = true;
		dan[b * maxn + a] = true;
		isdan[a] = true;
		isdan[b] = true;
	}
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		bool issafe = true;
		vector<int> goods;
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			if (issafe && isdan[a]) {
				for (auto it : goods) {
					if (dan[it * maxn + a]) {
						issafe = false;
						break;
					}
				}
			}
			if (isdan[a]) {
				goods.push_back(a);
			}
		}
		if (issafe) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	
	return 0;
}