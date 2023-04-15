/*
*	author:		zhouyuhao
*	created:	2023-04-05 09:51:43
*	modified:	2023-04-05 10:02:06
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<string, bool> al;
	for (int i = 0; i < n; i++) {
		string id;
		cin >> id;
		al[id] = true;
	}
	int m;
	cin >> m;
	int cntal = 0;
	string oal, ogu;
	string oalbd = "99999999";
	string ogubd = oalbd;
	for (int i = 0; i < m; i++) {
		string id;
		cin >> id;
		if (al[id]) {
			cntal++;
			if (id.substr(6, 8) < oalbd) {
				oalbd = id.substr(6, 8);
				oal = id;
			}
		} else {
			if (id.substr(6, 8) < ogubd) {
				ogubd = id.substr(6, 8);
				ogu = id;
			}
		}
	}
	cout << cntal << "\n";
	if (cntal == 0) {
		cout << ogu << "\n";
	} else {
		cout << oal << "\n";
	}
	
	return 0;
}