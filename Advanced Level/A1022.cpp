/*
*	author:		zhouyuhao
*	created:	2023-03-26 23:15:25
*	modified:	2023-03-26 23:46:00
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[]) {

	vector<map<string, set<string> > > m(6);
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		string id;
		getline(cin, id);
		for (int j = 1; j < 6; j++) {
			string s;
			getline(cin, s);
			if (j != 3) {
				m[j][s].insert(id);
			} else {
				int p = 0, q = 0;
				while (p < s.size() && q < s.size()) {
					if (!isspace(s[p])) {
						q = p;
						while(!isspace(s[q]) && q < s.size()) {
							q++;
						}
						string w = s.substr(p, q - p);
						m[j][w].insert(id);
						p = q;
					} else {
						p++;
					}
				}
			}
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l;
		scanf("%d: ", &l);
		string s;
		getline(cin, s);
		cout << l << ": " << s << "\n";
		if (m[l][s].size() == 0) {
			cout << "Not Found\n";
		} else {
			for (auto it : m[l][s]) {
				cout << it << "\n";
			}
		}
	}
	
	return 0;
}