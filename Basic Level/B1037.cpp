/*
*	author:		zhouyuhao
*	created:	2023-03-22 21:30:21
*	modified:	2023-03-22 21:38:06
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>

using namespace std;

int trans(int a, int b, int c) {
	return a * 17 * 29 + b * 29 + c;
}

int main(int argc, char const *argv[]) {

	int a, b, c;
	scanf("%d.%d.%d", &a, &b, &c);
	int pt = trans(a, b, c);
	scanf("%d.%d.%d", &a, &b, &c);
	int at = trans(a, b, c);
	int dif;
	if (pt <= at) {
		dif = at - pt;
	} else {
		cout << "-";
		dif = pt - at;
	}
	cout << dif / 17 / 29 << "." << dif % (17 * 29) / 29 << "." << dif % (17 * 29) % 29 << "\n";
	
	return 0;
}