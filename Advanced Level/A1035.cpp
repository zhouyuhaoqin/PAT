/*
*	author:		zhouyuhao
*	created:	2023-03-23 20:07:58
*	modified:	2023-03-23 20:29:59
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<vector<string> > s(n);
	vector<bool> f(n);
	fill(f.begin(), f.end(), false);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		bool flag = false;
		for (int j = 0; j < b.size(); j++) {
			if (b[j] == '1') {
				b[j] = '@';
				flag = true;
			} else if (b[j] == '0') {
				b[j] = '%';
				flag = true;
			} else if (b[j] == 'l') {
				b[j] = 'L';
				flag = true;
			} else if (b[j] == 'O') {
				b[j] = 'o';
				flag = true;
			}
		}
		s[i].push_back(a);
		s[i].push_back(b);
		if (flag) {
			f[i] = true;
			cnt++;
		}
	}
	if (cnt != 0) {
		cout << cnt << "\n";
		for (int i = 0; i < n; i++) {
			if (f[i]) {
				cout << s[i][0] << " " << s[i][1] << "\n";
			}
		}
	} else {
		if (s.size() == 1) {
			cout << "There is 1 account and no account is modified\n";
		} else {
			cout << "There are " << s.size() << " accounts and no account is modified\n";
		}
	}
	
	return 0;
}