/*
*	author:		zhouyuhao
*	created:	2023-04-05 22:22:59
*	modified:	2023-04-05 22:49:18
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[]) {

	vector<vector<string>> l(26, vector<string> (7));
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> l[i][j];
		}
	}
	string t;
	getchar();
	getline(cin, t);
	while (!isupper(t[0])) {
		t.erase(0, 1);
	}
	vector<string> w;
	for (int i = 0; i < t.size(); i++) {
		int j = i;
		while (j < t.size() && isupper(t[j])) {
			j++;
		}
		w.push_back(t.substr(i, j - i));
		while (!isupper(t[j]) && j < t.size()) {
			j++;
		}
		i = j - 1;
	}
	for (int i = 0; i < w.size(); i++) {
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < w[i].size(); k++) {
				cout << l[w[i][k] - 'A'][j];
				if (k < w[i].size() - 1) {
					cout << " ";
				} else {
					cout << "\n";
				}
			}
		}
		if (i < w.size() - 1) {
			cout << "\n";
		}
	}
	
	return 0;
}