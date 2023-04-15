/*
*	author:		zhouyuhao
*	created:	2023-03-22 11:12:31
*	modified:	2023-03-22 11:28:10
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>
#include <climits>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<int, int> list;
	for (int i = 0; i < n; i++) {
		int id, score;
		cin >> id >> score;
		list[id] += score;
	}
	int id = 0, score = INT_MIN;
	for (auto it : list) {
		if (it.second > score) {
			score = it.second;
			id = it.first;
		}
	}
	cout << id << " " << score << "\n";
	
	return 0;
}