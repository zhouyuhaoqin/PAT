/*
*	author:		zhouyuhao
*	created:	2023-03-27 20:25:34
*	modified:	2023-03-27 20:43:03
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {

	int m, n, k;
	cin >> m >> n >> k;
	for (int c = 0; c < k; c++) {
		vector<int> d(n);
		for (int i = 0; i < n; i++) {
			d[i] = i + 1;
		}
		queue<int> q;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			q.push(num);
		}
		stack<int> s;
		for (int i = 0; i < n; i++) {
			s.push(d[i]);
			if (s.size() > m) {
				break;
			}
			while (!s.empty() && s.top() == q.front()) {
				s.pop();
				q.pop();
			}
		}
		if (s.size() != 0) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
	
	return 0;
}