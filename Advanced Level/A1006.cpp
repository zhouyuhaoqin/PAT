/*
*	author:		zhouyuhao
*	created:	2023-03-22 20:40:55
*	modified:	2023-03-22 20:50:36
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>

using namespace std;

int trans(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}

int main(int argc, char const *argv[]) {

	int m;
	cin >> m;
	string firstid, lastid;
	int firsts = 24 * 3600 + 1;
	int lasts = -1;
	for (int i = 0; i < m; ++i) {
		string id;
		cin >> id;
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int ins = trans(h, m, s);
		scanf("%d:%d:%d", &h, &m, &s);
		int outs = trans(h, m, s);
		if (ins < firsts) {
			firsts = ins;
			firstid = id;
		}
		if (outs > lasts) {
			lasts = outs;
			lastid = id;
		}
	}
	cout << firstid << " " << lastid << "\n";
	
	return 0;
}