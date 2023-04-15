/*
*	author:		zhouyuhao
*	created:	2023-03-22 16:06:59
*	modified:	2023-03-22 16:13:04
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>

using namespace std;

int trans(char ch, int c) {
	string s;
	for (int i = 0; i < c; i++) {
		s += ch;
	}
	return s.size() == 0 ? 0 : stoi(s);
}

int main(int argc, char const *argv[]) {

	string a, b;
	char da, db;
	cin >> a >> da >> b >> db;
	int ca = 0, cb = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == da) {
			ca++;
		}
	}
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == db) {
			cb++;
		}
	}
	cout << trans(da, ca) + trans(db, cb) << "\n";
	
	return 0;
}