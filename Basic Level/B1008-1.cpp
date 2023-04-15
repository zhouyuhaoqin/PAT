/*
*	author:		zhouyuhao
*	created:	2023-03-22 16:29:18
*	modified:	2023-03-22 16:38:11
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	m %= n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int c = 0;
	for (int i = n - m; i < n; i++) {
		cout << a[i];
		c++;
		if (c < n) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	for (int i = 0; i < n - m; i++) {
		cout << a[i];
		c++;
		if (c < n) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	
	return 0;
}