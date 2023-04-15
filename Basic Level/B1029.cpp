/*
*	author:		zhouyuhao
*	created:	2023-03-25 20:41:09
*	modified:	2023-03-25 20:57:13
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <set>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[]) {

	string a, b;
	cin >> a >> b;
	set<char> r;
	for (int i = 0; i < a.size(); i++) {
		if (b.find(a[i]) == -1) {
			if (islower(a[i])) {
				a[i] = toupper(a[i]);
			}
			if (r.find(a[i]) == r.end()) {
				r.insert(a[i]);
				cout << a[i];
			}
		}
	}
	cout << "\n";
	
	return 0;
}