/*
*	author:		zhouyuhao
*	created:	2023-03-22 19:19:55
*	modified:	2023-03-23 15:50:56
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	map<int, int, greater<int> > p;
	int a, b;
	while (cin >> a >> b) {
		if (b != 0) {
			p.insert(make_pair(b - 1, a * b));
		}
	}
	if (p.size() == 0) {
		cout << "0 0\n";
	} else {
		int cnt = p.size();
		for (auto it : p) {
			cout << it.second << " " << it.first;
			if (--cnt) {
				cout << " ";
			} else {
				cout << "\n";
			}
		}
	}
	
	return 0;
}