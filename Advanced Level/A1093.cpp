/*
*	author:		zhouyuhao
*	created:	2023-03-22 14:20:19
*	modified:	2023-03-22 14:20:40
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/

//B1040

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

	string s;
	cin >> s;
	vector<int> cp(s.size());
	int countP = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			cp[i] = countP;
		} else if (s[i] == 'P') {
			countP++;
		}
	}
	vector<int> ct(s.size());
	int countT = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == 'A') {
			ct[i] = countT;
		} else if (s[i] == 'T') {
			countT++;
		}
	}
	long result = 0;
	for (int i = 0; i < s.size(); i++) {
		result += cp[i] * ct[i];
	}
	cout << result % 1000000007 << "\n";
	
	return 0;
}