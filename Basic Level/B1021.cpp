/*
*	author:		zhouyuhao
*	created:	2023-03-22 22:19:04
*	modified:	2023-03-22 22:21:55
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	string s;
	cin >> s;
	map<char, int> count;
	for (int i = 0; i < s.size(); i++) {
		count[s[i]]++;
	}
	for (auto it : count) {
		cout << it.first << ":" << it.second << "\n";
	}
	
	return 0;
}