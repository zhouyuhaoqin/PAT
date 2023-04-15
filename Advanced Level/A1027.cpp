/*
*	author:		zhouyuhao
*	created:	2023-03-22 21:55:11
*	modified:	2023-03-22 22:01:09
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>

using namespace std;

char trans(int n) {
	switch(n) {
		case 10:
			return 'A';
			break;
		case 11:
			return 'B';
			break;
		case 12:
			return 'C';
			break;
	}
}

int main(int argc, char const *argv[]) {

	cout << "#";
	for (int i = 0; i < 3; i++) {
		int n;
		cin >> n;
		if (n / 13 >= 10) {
			cout << trans(n / 13);
		} else {
			cout << n / 13;
		}
		if (n % 13 >= 10) {
			cout << trans(n % 13);
		} else {
			cout << n % 13;
		}
	}
	cout << "\n";
	
	return 0;
}