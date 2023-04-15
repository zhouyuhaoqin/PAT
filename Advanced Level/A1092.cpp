/*
*	author:		zhouyuhao
*	created:	2023-03-25 21:30:16
*	modified:	2023-03-25 21:30:27
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/

//B1039

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

	string a, b;
	cin >> a >> b;
	int count = 0;
	string c = a;
	for (int i = 0; i < b.size(); i++) {
		if (a.find(b[i]) != string::npos) {
			a.erase(a.find(b[i]), 1);
		} else {
			count++;
		}
	}
	if (count == 0) {
		cout << "Yes " << c.size() - b.size() << "\n";
	} else {
		cout << "No " << count << "\n";
	}
	
	return 0;
}