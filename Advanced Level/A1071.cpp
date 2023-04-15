/*
*	author:		zhouyuhao
*	created:	2023-03-26 22:33:18
*	modified:	2023-03-26 23:18:02
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[]) {

	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (isupper(s[i])) {
			s[i] = tolower(s[i]);
		}
	}
	map<string, int> count;
	int i = 0, j = 0, cnt = -1;
	while (i < s.size() && j < s.size()) {
		if (isalnum(s[i])) {
			j = i;
			while (j < s.size() && isalnum(s[j])) {
				j++;
			}
			count[s.substr(i, j - i)]++;
			if (count[s.substr(i, j - i)] > cnt) {
				cnt = count[s.substr(i, j - i)];
			}
			i = j;
		} else {
			i++;
		}
	}
	for (auto it : count) {
		if (it.second == cnt) {
			cout << it.first << " " << cnt << "\n";
			break;
		}
	}
	
	return 0;
}