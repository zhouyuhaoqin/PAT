/*
*	author:		zhouyuhao
*	created:	2023-03-25 21:30:48
*	modified:	2023-03-25 21:38:09
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[]) {

	string a;
	getline(cin, a);
	map<char, int> count;
	int mc = -1;
	for (int i = 0; i < a.size(); i++) {
		if (isalpha(a[i])) {
			if (isupper(a[i])) {
				a[i] = tolower(a[i]);
			}
			count[a[i]]++;
			if (count[a[i]] > mc) {
				mc = count[a[i]];
			}
		}
	}
	for (auto it : count) {
		if (it.second == mc) {
			cout << it.first << " " << it.second << "\n";
			break;
		}
	}
	
	return 0;
}