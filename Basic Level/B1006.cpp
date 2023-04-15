/*
*	author:		zhouyuhao
*	created:	2023-03-22 22:15:00
*	modified:	2023-03-22 22:18:43
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	if (n / 100 != 0) {
		for (int i = 0; i < n / 100; i++) {
			cout << "B";
		}
	}
	if (n % 100 / 10 != 0) {
		for (int i = 0; i < n % 100 / 10 != 0; i++) {
			cout << "S";
		}
	}
	for (int i = 1; i <= n % 10; i++) {
		cout << i;
	}
	cout << "\n";

	return 0;
}