/*
*	author:		zhouyuhao
*	created:	2023-03-22 22:22:26
*	modified:	2023-03-31 16:06:44
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int m[11] = {1, 0, -1, 9, 8, 7, 6, 5, 4, 3, 2};

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int sum = 0;
		bool islaw = true;
		for (int j = 0; j < 17; j++) {
			if (isdigit(s[j])) {
				sum += (s[j] - '0') * w[j];
			} else {
				cout << s << "\n";
				islaw = false;
				break;
			}
		}
		if (!islaw) {
			flag = false;
			continue;
		}
		int z = sum % 11;
		if (z != 2) {
			if (m[z] != s[17] - '0') {
				cout << s << "\n";
				flag = false;
				continue;
			}
		} else {
			if (s[17] != 'X') {
				cout << s << "\n";
				flag = false;
				continue;
			}
		}
	}
	if (flag) {
		cout << "All passed\n";
	}
	
	return 0;
}