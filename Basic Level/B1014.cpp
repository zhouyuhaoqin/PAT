/*
*	author:		zhouyuhao
*	created:	2023-03-23 17:37:53
*	modified:	2023-03-23 17:37:56
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {

	string w[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int n = min(a.size(), b.size());
	int flag;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			if (isupper(a[i])) {
				int dif = a[i] - 'A';
				if (dif >= 0 && dif <= 7) {
					cout << w[a[i] - 'A'] << " ";
					flag = i;
					break;;
				}
			}
		}
	}
	for (int i = flag + 1; i < n; i++) {
		if (a[i] == b[i]) {
			if (isdigit(a[i])) {
				cout << setfill('0') << setw(2) << a[i] << ":";
				break;
			} else if (isupper(a[i])) {
				int dif = a[i] - 'A';
				if (dif >= 0 && dif <= 13) {
					cout << dif + 10 << ":";
					break;
				}
			}
		}
	}
	int m = min(c.size(), d.size());
	for (int i = 0; i < m; i++) {
		if (c[i] == d[i]) {
			if (isalpha(c[i])) {
				cout << setfill('0') << setw(2) << i << "\n";
				break;
			}
		}
	}
	
	return 0;
}