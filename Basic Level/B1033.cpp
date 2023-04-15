/*
*	author:		zhouyuhao
*	created:	2023-03-25 21:02:10
*	modified:	2023-03-25 21:18:51
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[]) {

	string a, b;
	getline(cin, a);
	getline(cin, b);
	bool shift = false;
	for (int i = 0; i < a.size(); i++) {
		if (isupper(a[i])) {
			a[i] = tolower(a[i]);
		}
		if (a[i] == '+') {
			shift = true;
		}
	}
	for (int i = 0; i < b.size(); i++) {
		if (isupper(b[i])) {
			if (shift || a.find(tolower(b[i])) != string::npos) {
				continue;
			}
		} else {
			if (a.find(b[i]) != string::npos) {
				continue;
			}
		}
		cout << b[i];
	}
	cout << "\n";
	
	return 0;
}