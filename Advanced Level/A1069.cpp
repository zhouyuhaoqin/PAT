/*
*	author:		zhouyuhao
*	created:	2023-03-22 15:40:39
*	modified:	2023-03-27 10:17:09
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/

//B1019

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string setfill(string s) {
	while (s.size() < 4) {
		s = '0' + s;
	}
	return s;
}

int main(int argc, char const *argv[]) {

	string n;
	cin >> n;
	n = setfill(n);
	do {
		sort(n.begin(), n.end());
		string min = n;
		sort(n.rbegin(), n.rend());
		string max = n;
		int dif = stoi(max) - stoi(min);
		n = setfill(to_string(dif));
		cout << max << " - " << min << " = " << n << "\n";
		if (dif == 0 || dif == 6174) {
			break;
		}
	} while (true);
	
	return 0;
}