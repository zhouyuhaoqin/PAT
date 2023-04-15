/*
*	author:		zhouyuhao
*	created:	2023-04-13 17:45:05
*	modified:	2023-04-13 17:52:56
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
	if (a.exi != b.exi) {
		return a.exi < b.exi;
	} else {
		return a.ent < b.ent;
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
	int cnt = 1, lastexi = p[0].exi;
	for (int i = 1; i < n; i++) {
		if (p[i].ent >= lastexi) {
			cnt++;
			lastexi = p[i].exi;
		}
	}
	cout << cnt << "\n";
	
	return 0;
}