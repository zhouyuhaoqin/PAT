/*
*	author:		zhouyuhao
*	created:	2023-03-24 20:05:53
*	modified:	2023-03-24 22:14:14
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct per {
	string name;
	int M, d, h, m;
	string line;
};

bool cmp(per a, per b) {
	if (a.name != b.name) {
		return a.name < b.name;
	} else if (a.d != b.d) {
		return a.d < b.d;
	} else if (a.h != b.h) {
		return a.h < b.h;
	} else {
		return a.m < b.m;
	}
}

vector<int> toll(24);
int cnt = 0;
double calfare(int ad, int ah, int am, int bd, int bh, int bm) {
	double fare = 0;
	while (ad != bd || ah != bh || am != bm) {
		fare += toll[ah];
		am++;
		cnt++;
		if (am == 60) {
			am = 0;
			ah++;
			if (ah == 24) {
				ah = 0;
				ad++;
			}
		}
	}
	return fare;
}

int main(int argc, char const *argv[]) {

	for (int i = 0; i < 24; i++) {
		cin >> toll[i];
	}
	int n;
	cin >> n;
	vector<per> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].name;
		scanf("%d:%d:%d:%d", &p[i].M, &p[i].d, &p[i].h, &p[i].m);
		cin >> p[i].line;
	}
	sort(p.begin(), p.end(), cmp);
	vector<per> b;
	for (int i = 0; i < n; i++) {
		if (p[i].name == p[i + 1].name) {
			if (p[i].line == "on-line" && p[i + 1].line == "off-line") {
				b.push_back(p[i]);
				b.push_back(p[i + 1]);
			}
		}
	}
	double tf = 0;
	for (int i = 0; i < b.size(); i += 2) {
		bool next = false, before = false;
		if (i + 2 < b.size() && b[i + 2].name == b[i].name) {
			next = true;
		}
		if (i - 2 >= 0 && b[i - 2].name == b[i].name) {
			before = true;
		}
		if (!before) {
			cout << b[i].name << " " << setfill('0') << setw(2) << b[i].M << "\n";
		}
		printf("%02d:%02d:%02d ", b[i].d, b[i].h, b[i].m);
		printf("%02d:%02d:%02d ", b[i + 1].d, b[i + 1].h, b[i + 1].m);
		double f = calfare(b[i].d, b[i].h, b[i].m, b[i + 1].d, b[i + 1].h, b[i + 1].m) / 100;
		cout << cnt << " $" << fixed << setprecision(2) << f << "\n";
		cnt = 0;
		tf += f;
		if (!next) {
			cout << "Total amount: $" << fixed << setprecision(2) << tf << "\n";
			tf = 0;
		}
	}
	
	return 0;
}