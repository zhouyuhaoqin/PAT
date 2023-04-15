/*
*	author:		zhouyuhao
*	created:	2023-04-04 19:59:56
*	modified:	2023-04-04 20:46:20
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct stu {
	string id;
	int sco;
};

struct site {
	string num;
	int nt;
};

bool cmpstu(stu a, stu b) {
	if (a.sco != b.sco) {
		return a.sco > b.sco;
	} else {
		return a.id < b.id;
	}
}

map<string, int> siten;
bool cmpsite(site a, site b) {
	if (a.nt != b.nt) {
		return a.nt > b.nt;
	} else {
		return a.num < b.num;
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	map<string, int> sites;
	map<string, map<string, int>> date;
	vector<stu> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i].id >> s[i].sco;
		siten[s[i].id.substr(1, 3)]++;
		sites[s[i].id.substr(1, 3)] += s[i].sco;
		date[s[i].id.substr(4, 6)][s[i].id.substr(1, 3)]++;
	}
	sort(s.begin(), s.end(), cmpstu);
	for (int q = 0; q < m; q++) {
		int type;
		string term;
		cin >> type >> term;
		cout << "Case " << q + 1 << ": " << type << " " << term << "\n";
		bool isempty = true;
		if (type == 1) {
			for (auto it : s) {
				if (it.id[0] == term[0]) {
					cout << it.id << " " << it.sco << "\n";
					isempty = false;
				}
			}
		} else if (type == 2) {
			if (siten[term] != 0) {
				cout << siten[term] << " " << sites[term] << "\n";
				isempty = false;
			}
		} else {
			vector<site> ans;
			for (auto it : date[term]) {
				ans.push_back({it.first, it.second});
			}
			sort(ans.begin(), ans.end(), cmpsite);
			for (auto it : ans) {
				cout << it.num << " " << it.nt << "\n";
				isempty = false;
			}
		}
		if (isempty) {
			cout << "NA\n";
		}
	}
	
	return 0;
}