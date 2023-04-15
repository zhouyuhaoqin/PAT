/*
*	author:		zhouyuhao
*	created:	2023-03-28 10:54:59
*	modified:	2023-03-28 12:10:27
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct node {
	int data, next;
};

int main(int argc, char const *argv[]) {
	
	int id, n;
	cin >> id >> n;
	vector<node> d(n + 1);
	map<int, int> loc;
	map<int, int> count;
	for (int i = 1; i <= n; i++) {
		int id;
		cin >> id >> d[i].data >> d[i].next;
		loc[id] = i;
		if (count[abs(d[i].data)] == 0) {
			count[abs(d[i].data)] = 1;
		}
	}
	vector<vector<int> > l(2);
	do {
		if (count[abs(d[loc[id]].data)] == 1) {
			l[0].push_back(id);
			count[abs(d[loc[id]].data)] = 0;
		} else {
			l[1].push_back(id);
		}
		id = d[loc[id]].next;
	} while (id != -1);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < l[i].size(); j++) {
			cout << setfill('0') << setw(5) << l[i][j] << " " << d[loc[l[i][j]]].data << " ";
			if (j < l[i].size() - 1) {
				cout << setfill('0') << setw(5) << l[i][j + 1] << "\n";
			} else {
				cout << "-1\n";
			}
		}
	}
	
	return 0;
}