/*
*	author:		zhouyuhao
*	created:	2023-04-03 18:39:17
*	modified:	2023-04-03 18:47:09
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct node {
	int dis, num;
};

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		int dis;
		cin >> dis;
		cnt[dis]++;
	}
	vector<node> d;
	for (auto it : cnt) {
		d.push_back({it.first, it.second});
	}
	int sum = 0;
	priority_queue<int, vector<int>, less<int>> q;
	for (int i = 0; i < d.size(); i++) {
		sum += d[i].num;
		if (n - sum >= d[i].dis) {
			q.push(d[i].dis);
		} else {
			sum -= d[i].num;
			if (i > 0) {
				for (int j = d[i - 1].dis + 1; j < d[i].dis; j++) {
					if (n - sum >= j) {
						q.push(j);
					}
				}
			} else {
				for (int j = 0; j < d[i].dis; j++) {
					if (n - sum >= j) {
						q.push(j);
					}
				}
			}
			break; // @important!
		}
	}
	cout << q.top() << "\n";
	
	return 0;
}