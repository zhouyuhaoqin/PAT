/*
*	author:		zhouyuhao
*	created:	2023-03-23 21:50:15
*	modified:	2023-03-23 22:24:38
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>

using namespace std;

string p[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string w[10] = { "", "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};

int main(int argc, char const *argv[]) {

	string s;
	cin >> s;
	if (s[0] == '-') {
		cout << "Fu ";
		s.erase(0, 1);
	}
	if (s.size() == 1) {
		cout << p[s[0] - '0'];
	} else {
		cout << p[s[0] - '0'] << " " << w[s.size()];
		s.erase(0, 1);
	}
	while (s.size() > 1) {
		if (s[0] != '0') {
			cout << " " << p[s[0] - '0'] << " " << w[s.size()];
		} else {
			if (s[1] != '0') {
				cout << " ling";
			}
		}
		if (s.size() == 5 && s[0] == '0') {
			cout << " Wan";
		}
		s.erase(0, 1); 
	}
	if (s[0] != '0') {
		cout << " " << p[s[0] - '0'];
	}
	cout << "\n";
	
	return 0;
}