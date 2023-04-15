/*
*	author:		zhouyuhao
*	created:	2023-03-28 10:11:09
*	modified:	2023-03-28 11:22:01
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

	int id, n, k;
	cin >> id >> n >> k;
	vector<node> d(n + 1);
	map<int, int> loc;
	for (int i = 1; i <= n; i++) {
		int id;
		cin >> id >> d[i].data >> d[i].next;
		loc[id] = i;
	}
	vector<int> l;
	do {
		l.push_back(id);
		id = d[loc[id]].next;
	} while (id != -1);
	for (int i = 0; i < l.size() / k; i++) {
		reverse(l.begin() + i * k, l.begin() + (i + 1) * k);
	}
	for (int i = 0; i < l.size(); i++) {
		cout << setfill('0') << setw(5) << l[i] << " " << d[loc[l[i]]].data << " ";
		if (i < l.size() - 1) {
			cout << setfill('0') << setw(5) << l[i + 1] << "\n";
		} else {
			cout << "-1\n";
		}
	}
	
	return 0;
}