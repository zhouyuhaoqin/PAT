/*
*	author:		zhouyuhao
*	created:	2023-03-22 16:39:26
*	modified:	2023-03-22 16:56:43
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<float> a(5);
	vector<bool> flag(5);
	bool symbol = false;
	int c4 = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		switch(num % 5) {
			case 0:
				if (num % 2 == 0) {
					flag[0] = true;
					a[0] += num;
				}
				break;
			case 1:
				if (symbol == false) {
					a[1] += num;
				} else {
					a[1] -= num;
				}
				symbol = !symbol;
				flag[1] = true;
				break;
			case 2:
				flag[2] = true;
				a[2]++;
				break;
			case 3:
				a[3] += num;
				c4++;
				flag[3] = true;
				break;
			case 4:
				if (num > a[4]) {
					flag[4] = true;
					a[4] = num;
				}
		}
	}
	for (int i = 0; i < 5; i++) {
		if (flag[i] == false) {
			cout << "N";
		} else {
			if (i != 3) {
				cout << (int)a[i];
			} else {
				cout << fixed << setprecision(1) << a[3] / c4;
			}
		}
		if (i < 4) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	
	return 0;
}