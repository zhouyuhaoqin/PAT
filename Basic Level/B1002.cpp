/*
*	author:		zhouyuhao
*	created:	2023-03-22 22:39:47
*	modified:	2023-03-22 22:45:38
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>

using namespace std;

string pinyin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main(int argc, char const *argv[]) {

	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += s[i] - '0';
	}
	s = to_string(sum);
	for (int i = 0; i < s.size(); i++) {
		cout << pinyin[s[i] - '0'];
		if (i < s.size() - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	
	return 0;
}