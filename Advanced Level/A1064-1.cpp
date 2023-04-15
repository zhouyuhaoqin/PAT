/*
*	author:		zhouyuhao
*	created:	2023-03-29 19:17:01
*	modified:	2023-03-29 20:17:54
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> in, level;

void leveltra(int s, int e, int i) {
	if (s > e) {
		return;
	}
	int n = e - s + 1;
	int l = log(n + 1) / log(2);
	int ll = n - pow(2, l) + 1;
	int r = s + pow(2, l - 1) - 1;
	r += min(ll, (int)pow(2, l - 1));
	level[i] = in[r];
	leveltra(s, r - 1, 2 * i + 1);
	leveltra(r + 1, e, 2 * i + 2);
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	in.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	sort(in.begin(), in.end());
	level.resize(n);
	leveltra(0, n - 1, 0);
	for (int i = 0; i < n; i++) {
		cout << level[i];
		if (i < n - 1) {
			cout << " ";
		} else {
			cout << "\n";
		} 
	}
	
	return 0;
}