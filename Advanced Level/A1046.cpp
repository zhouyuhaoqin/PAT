/*
*	author:		zhouyuhao
*	created:	2023-03-22 18:51:28
*	modified:	2023-03-22 19:05:27
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<long> d(n + 1);
	long td = 0;
	for (int i = 1; i < n + 1; i++) {
		int dis;
		cin >> dis;
		td += dis;
		d[i + 1] = td;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		long sd = d[b] - d[a];
		cout << min(sd, td - sd) << "\n";
	}
	
	return 0;
}