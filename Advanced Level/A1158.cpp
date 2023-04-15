/*
*	author:		zhouyuhao
*	created:	2023-04-05 16:15:13
*	modified:	2023-04-05 16:33:33
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> f;

void init() {
	for (int i = 0; i < f.size(); i++) {
		f[i] = i;
	}
}

int find(int x) {
	int a = x;
	while (x != f[x]) {
		x = f[x];
	}
	while (a != f[a]) {
		int z = a;
		a = f[a];
		f[z] = x;
	}
	return x;
}

void joint(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if (fa != fb) {
		if (fa < fb) {
			swap(fa, fb);
		}
		f[fa] = fb;
	}
}

int main(int argc, char const *argv[]) {

	int k, n, m;
	cin >> k >> n >> m;
	vector<vector<int>> dur(n + 1, vector<int> (n + 1));
	vector<vector<int>> d(m, vector<int> (3));
	for (int i = 0; i < m; i++) {
		cin >> d[i][0] >> d[i][1] >> d[i][2];
		dur[d[i][0]][d[i][1]] += d[i][2];
	}
	vector<set<int>> rec(n + 1);
	for (int i = 0; i < m; i++) {
		if (dur[d[i][0]][d[i][1]] <= 5) {
			rec[d[i][0]].insert(d[i][1]);
		}
	}
	vector<int> sus;
	for (int i = 1; i <= n; i++) {
		if (rec[i].size() > k) {
			int cb = 0;
			for (auto it : rec[i]) {
				if (dur[it][i] > 0) {
					cb++;
				}
			}
			if ((double) cb / rec[i].size() <= 0.2) {
				sus.push_back(i);
			}
		}
	}
	if (sus.size() == 0) {
		cout << "None\n";
	} else {
		f.resize(n + 1);
		init();
		for (auto it : sus) { // two dimension, not one or linear
			for (auto is : sus) {
				if (it != is) {
					if (dur[it][is] > 0 && dur[is][it] > 0) {
						joint(it, is);
					}
				}
			}
		}
		map<int, vector<int>> gang;
		for (auto it : sus) {
			gang[find(it)].push_back(it);
		}
		for (auto it : gang) {
			int size = it.second.size();
			for (auto is : it.second) {
				cout << is;
				if (--size > 0) {
					cout << " ";
				} else {
					cout << "\n";
				}
			}
		}
	}
	
	return 0;
}