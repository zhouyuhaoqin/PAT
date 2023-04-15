/*
*	author:		zhouyuhao
*	created:	2023-03-27 16:18:57
*	modified:	2023-03-27 19:56:45
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string erase0(string s) {
	while (s[0] == '0') {
		if (s[1] == '.') {
			break;
		}
		s.erase(0, 1);
	}
	return s;
}

string erasep(string s) {
	if (s.find('.') != string::npos) {
		s.erase(s.find('.'), 1);
	}
	return s;
}

bool iszero(string s) {
	s = erasep(s);
	bool flag = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '0') {
			flag = false;
			break;
		}
	}
	return flag;
}

string substr(string s, int n) {
	s = erasep(s);
	s = erase0(s);
	while(s.size() < n) {
		s += '0';
	}
	return s.substr(0, n);
}

int magnitude(string s) {
	s = erase0(s);
	int count = 0;
	if (s[0] != '0') {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') {
				break;
			}
			count++;
		}
	} else {
		if (!iszero(s)) {
			for (int i = 2; i < s.size(); i++) {
				if (s[i] != '0') {
					break;
				}
				count--;
			}
		}
	}
	return count;
}

int main(int argc, char const *argv[]) {

	int n;
	vector<string> s(2);
	cin >> n >> s[0] >> s[1];
	vector<int> m(2);
	vector<string> subs(2);
	for (int i = 0; i < 2; i++) {
		m[i] = magnitude(s[i]);
		subs[i] = substr(s[i], n);
	}
	bool issame = false;
	if (m[0] == m[1] && subs[0] == subs[1]) {
		issame = true;
	}
	if (issame) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	for (int i = 0; i < 2; i++) {
		cout << " 0." << subs[i] << "*10^" << m[i];
		if (issame && i == 0) {
			break;
		}
	}
	cout << "\n";

	return 0;
}