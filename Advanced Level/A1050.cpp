/*
*	author:		zhouyuhao
*	created:	2023-03-25 21:59:55
*	modified:	2023-03-25 22:00:08
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

	string a, b;
	getline(cin, a);
	getline(cin, b);
	for (int i = 0; i < a.size(); i++) {
		if (b.find(a[i]) == string::npos) {
			cout << a[i];
		}
	}
	cout << "\n";
	
	return 0;
}