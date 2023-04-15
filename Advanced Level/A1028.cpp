/*
*	author:		zhouyuhao
*	created:	2023-03-25 13:09:11
*	modified:	2023-03-25 13:53:59
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct stu {
	string d[3];
};

vector<stu> s;
int idx;
bool cmp(stu a, stu b) {
	switch (idx) {
		case 2:
			if (a.d[1] != b.d[1]) {
				return a.d[1] < b.d[1];
			}
		default: 
			return a.d[0] < b.d[0];
		case 3:
			if (a.d[2] != b.d[2]) {
				return stoi(a.d[2]) < stoi(b.d[2]);
			}
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n >> idx;
	for (int i = 0; i < n; i++) {
		stu t;
		cin >> t.d[0] >> t.d[1] >> t.d[2];
		s.push_back(t);
	}
	sort(s.begin(), s.end(), cmp);
	for (auto it : s) {
		cout << it.d[0] << " " << it.d[1] << " " << it.d[2] << "\n";
	}
	
	return 0;
}