/*
*	author:		zhouyuhao
*	created:	2023-03-26 11:12:11
*	modified:	2023-03-26 12:37:52
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<int, int> l;
	int match = 0;
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		l[d] = i;
		if (l[d] != i) {
			match = i;
		}
	}
	int count = 0;
	while (true) {
		while (l[0] != 0) {
			int t = l[l[0]];
			l[l[0]] = l[0];
			l[0] = t;
			count++;
		}
		bool sorted = true;
		for (int i = match; i < n; i++) {
			if (l[i] != i) {
				int t = l[i];
				l[0] = t;
				l[i] = 0;
				count++;
				match = i;
				sorted = false;
				break;
			}
		}
		if (sorted) {
			break;
		}
	}
	cout << count << "\n";
	
	return 0;
}