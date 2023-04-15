/*
*	author:		zhouyuhao
*	created:	2023-03-22 13:56:42
*	modified:	2023-03-22 14:01:26
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n = 10;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 1; i < n; i++) {
		if (num[i] > 0) {
			cout << i;
			num[i]--;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < num[i]; j++) {
			cout << i;
		}
	}
	cout << "\n";
	
	return 0;
}