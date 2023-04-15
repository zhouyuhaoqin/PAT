/*
*	author:		zhouyuhao
*	created:	2023-04-06 08:50:22
*	modified:	2023-04-06 11:05:43
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 1;
vector<bool> dif(maxn), dup(maxn); //unordered_map

int main(int argc, char const *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n1, n2;
	cin >> n1 >> n2;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> d(n + 1, vector<int> (m + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> d[i + 1][j + 1];
		}
	}
	vector<bool> isout(n + 1);
	dif[abs(n1 - n2)] = true;
	dup[n1] = true, dup[n2] = true;
	vector<int> prenum;
	prenum.push_back(n1);
	prenum.push_back(n2);
	int cntout = 0;
	for (int q = 1; q <= m; q++) {
		vector<int> isoutid;
		for (int i = 1; i <= n; i++) {
			if (!isout[i]) {
				int num = d[i][q];
				if (dif[num] && !dup[num]) {
					dup[num] = true;
					for (auto it : prenum) {
						dif[abs(it - num)] = true;
					}
					prenum.push_back(num);
				} else {
					cntout++;
					isout[i] = true;
					isoutid.push_back(i);
					if (cntout == n) {
						break;
					}
				}
			}
		}
		if (isoutid.size() != 0) {
			sort(isoutid.begin(), isoutid.end());
			for (auto it : isoutid) {
				cout << "Round #" << q << ": " << it << " is out.\n";
			}
		}
		if (cntout == n) {
			break;
		}
	}
	vector<int> win;
	for (int i = 1; i <= n; i++) {
		if (!isout[i]) {
			win.push_back(i);
		}
	}
	if (win.size() != 0) {
		cout << "Winner(s):";
		sort(win.begin(), win.end());
		for (auto it : win) {
			cout << " " << it;
		}
		cout << "\n";
	} else {
		cout << "No winner.\n";
	}
	
	return 0;
}