/*
*	author:		zhouyuhao
*	created:	2023-03-29 22:37:25
*	modified:	2023-03-29 23:36:56
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> f;

int findf(int x) {
	int a = x;
	while (x != f[x]) {
		x = f[x];
	}
	while (a != f[a]) {
		int z = a;
		a = f[a];
		f[z] = x;
		// z = f[x];
	}
	return x;
}

void jointf(int a, int b) {
	int fa = findf(a);
	int fb = findf(b);
	if (fa != fb) {
		f[fa] = fb;
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	f.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	map<int, int> h;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		getchar();
		for (int j = 0; j < k; j++) {
			int id;
			cin >> id;
			if (h[id] == 0) {
				h[id] = i + 1;
			}
			jointf(i + 1, h[id]);
		}
	}
	map<int, int> c;
	for (int i = 1; i <= n; i++) {
		c[findf(i)]++;
	}
	vector<int> clu;
	for (auto it : c) {
		clu.push_back(it.second);
	}
	sort(clu.begin(), clu.end(), greater<int> ());
	cout << clu.size() << "\n";
	for (int i = 0; i < clu.size(); i++) {
		cout << clu[i];
		if (i < clu.size() - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
	
	return 0;
}