/*
*	author:		zhouyuhao
*	created:	2023-04-13 17:20:40
*	modified:	2023-04-13 17:44:58
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct per {
	int ent, exi;
};

bool cmp(per a, per b) {
	if (a.ent != b.ent) {
		return a.ent > b.ent;
	} else {
		return a.exi < b.exi;
	}
}

int trans(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<per> p(n);
	for (int i = 0; i < n; i++) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		p[i].ent = trans(h, m, s);
		scanf("%d:%d:%d:", &h, &m, &s);
		p[i].exi = trans(h, m, s);
	}
	sort(p.begin(), p.end(), cmp);
	int cnt = 1, lastent = p[0].ent;
	for (int i = 1; i < n; i++) {
		if (p[i].exi <= lastent) {
			cnt++;
			lastent = p[i].ent;
		}
	}
	cout << cnt << "\n";
	
	return 0;
}