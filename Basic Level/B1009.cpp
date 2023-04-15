/*
*	author:		zhouyuhao
*	created:	2023-03-22 11:51:38
*	modified:	2023-03-22 11:55:15
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

	stack<string> s;
	string w;
	while (cin >> w) {
		s.push(w);
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
		if (s.size() != 0) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	
	return 0;
}