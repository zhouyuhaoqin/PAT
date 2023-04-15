/*
*	author:		zhouyuhao
*	created:	2023-03-22 21:47:26
*	modified:	2023-03-22 21:54:28
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, b;
	cin >> n >> b;
	vector<int> s;
	do {
		s.push_back(n % b);
		n /= b;
	} while (n != 0);
	bool flag = true;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		cout << s[i];
		if (i > 0) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	
	return 0;
}