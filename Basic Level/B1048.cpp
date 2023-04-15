/*
*	author:		zhouyuhao
*	created:	2023-03-23 18:58:44
*	modified:	2023-03-23 19:25:11
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.size() > b.size()) {
		for (int i = 0; i < a.size() - b.size(); i++) {
			b += "0";
		}
	} else {
		for (int i = 0; i < b.size() - a.size(); i++) {
			a += "0";
		}
	}
	for (int i = 0; i < a.size(); i++) {
		int ai = a[i] - '0';
		int bi = b[i] - '0';
		if (i % 2 == 0) {
			int ci = ai + bi;
			ci %= 13;
			if (ci > 9) {
				switch(ci) {
					case 10:
						b[i] = 'J';
						break;
					case 11:
						b[i] = 'Q';
						break;
					case 12:
						b[i] = 'K';
						break;
				}
			} else {
				b[i] = ci + '0';
			}
		} else {
			int ci = bi - ai;
			if (ci < 0) {
				ci += 10;
			}
			b[i] = ci + '0';
		}
	}
	reverse(b.begin(), b.end());
	cout << b << "\n";
	
	return 0;
}