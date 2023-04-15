/*
*	author:		zhouyuhao
*	created:	2023-03-26 21:36:09
*	modified:	2023-03-26 22:07:59
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	map<string, set<int> > c;
	for (int i = 0; i < k; i++) {
		int no, ns;
		cin >> no >> ns;
		for (int j = 0; j < ns; j++) {
			string name;
			cin >> name;
			c[name].insert(no);
		}
	}
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		cout << name << " " << c[name].size();
		for (auto it : c[name]) {
			cout << " " << it;
		}
		cout << "\n";
	}
	
	return 0;
}