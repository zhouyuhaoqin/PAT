/*
*	author:		zhouyuhao
*	created:	2023-03-23 18:56:59
*	modified:	2023-03-23 18:57:03
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {

	string a;
	cin >> a;
	if (a[0] == '-') {
		cout << a[0];
	}
	a.erase(0, 1);
	int e = stoi(a.substr(a.find('E') + 1));
	a.erase(a.find('E'));
	if (e < 0) {
		cout << "0.";
		e = abs(e);
		for (int i = 0; i < e - 1; i++) {
			cout << "0";
		}
		a.erase(1, 1);
		cout << a << "\n";
	} else if (e > 0) {
		int right = a.size() - 2;
		if (e >= right) {
			a.erase(1, 1);
			cout << a;
			for (int i = 0; i < e - right; i++) {
				cout << "0";
			}
			cout << "\n";
		} else {
			for (int i = 0; i < a.size(); i++) {
				if (a[i] == '.') {
					continue;
				}
				cout << a[i];
				if (i == 1 + e) {
					cout << ".";
				}
			}
			cout << "\n";
		}
	} else {
		cout << a << "\n";
	}
	
	return 0;
}