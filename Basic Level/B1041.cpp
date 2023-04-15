/*
*	author:		zhouyuhao
*	created:	2023-03-22 19:24:51
*	modified:	2023-03-22 19:42:23
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct stu {
	string id;
	int id2;
};

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<int, stu> s;
	for (int i = 0; i < n; i++) {
		stu temp;
		int id1;
		cin >> temp.id >> id1 >> temp.id2;
		s.insert(make_pair(id1, temp));
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int id1;
		cin >> id1;
		cout << s.find(id1)->second.id << " " << s.find(id1)->second.id2 << "\n";
	}

	return 0;
}