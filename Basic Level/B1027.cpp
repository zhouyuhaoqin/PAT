/*
*	author:		zhouyuhao
*	created:	2023-03-22 21:04:17
*	modified:	2023-03-22 21:16:40
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	char ch;
	cin >> n >> ch;
	int count = n;
	count--;
	int row = 1, col = 1;
	while (count >= 2 * (col + 2)) {
		col += 2;
		count -= 2 * col;
		row++;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int j = 0; j < col; j++) {
			cout << ch;
		}
		col -= 2;
		cout << "\n";
	}
	col += 2;
	int temp = row;
	row--;
	for (int i = 1; i < temp; i++) {
		col += 2;
		row--;
		for (int j = 0; j < row; j++) {
			cout << " ";
		}
		for (int j = 0; j < col; j++) {
			cout << ch;
		}
		cout << "\n";
	}
	cout << count << "\n";
	
	return 0;
}