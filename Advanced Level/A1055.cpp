/*
*	author:		zhouyuhao
*	created:	2023-03-25 13:58:24
*	modified:	2023-03-25 14:10:39
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct per {
	string name;
	int age, worth;
};

bool cmp(per a, per b) {
	if (a.worth != b.worth) {
		return a.worth > b.worth;
	} else if (a.age != b.age) {
		return a.age < b.age;
	} else {
		return a.name < b.name;
	}
}

int main(int argc, char const *argv[]) {

	int n, k;
	cin >> n >> k;
	vector<per> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].name >> p[i].age >> p[i].worth;
	}
	sort(p.begin(), p.end(), cmp);
	for (int i = 0; i < k; i++) {
		int m, amin, amax;
		cin >> m >> amin >> amax;
		cout << "Case #" << i + 1 << ":\n";
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (p[j].age >= amin && p[j].age <= amax) {
				cout << p[j].name << " " << p[j].age << " " << p[j].worth << "\n";
				count++;
				if (count == m) {
					break;
				}
			}
		}
		if (count == 0) {
			cout << "None\n";
		}
	}
	
	return 0;
}