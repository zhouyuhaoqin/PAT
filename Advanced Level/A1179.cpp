/*
*	author:		zhouyuhao
*	created:	2023-04-14 22:17:40
*	modified:	2023-04-14 22:17:43
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

map<int, int> rea;
vector<int> pro;
map<int, set<vector<int>>> equ;
map<int, vector<int>> ans;

bool dfs(int ps, int pe) {
	if (ps == pe) {
		return true;
	}
	int pi = pro[ps];
	for (auto it : equ[pi]) {
		bool equisok = true;
		for (auto is : it) {
			if (rea[is] == 0) {
				equisok = false;
				break;
			}
		}
		if (!equisok) {
			continue;
		}
		ans[pi] = it;
		for (auto is : it) {
			rea[is]--;
		}
		if (dfs(ps + 1, pe)) {
			return true;
		}
		for (auto is : it) {
			rea[is]++;
		}
		ans[pi].clear();
	}
	return false;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		rea[id]++;
	}
	int m;
	cin >> m;
	pro.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> pro[i];
		equ[pro[i]].insert({pro[i]});
		if (rea[pro[i]] == 0) {
			rea[pro[i]]++;
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		vector<int> temp;
		int id;
		cin >> id;
		temp.push_back(id);
		string ch;
		while (cin >> ch) {
			cin >> id;
			if (ch == "+") {
				temp.push_back(id);
			} else {
				equ[id].insert(temp);
				break;
			}
		}
	}
	dfs(0, m);
	for (auto it : pro) {
		for (int i = 0; i < ans[it].size(); i++) {
			cout << setfill('0') << setw(2) << ans[it][i];
			if (i < ans[it].size() - 1) {
				cout << " + ";
			} else {
				cout << " -> ";
			}
		}
		cout << setfill('0') << setw(2) << it << "\n";
	}
	
	return 0;
}