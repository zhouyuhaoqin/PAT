/*
*	author:		zhouyuhao
*	created:	2023-04-04 15:22:47
*	modified:	2023-04-04 15:56:06
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> t, post;

void dfsmaxheap(int r, int n, bool &flag) {
	if (r >= n) {
		return;
	}
	if (2 * r + 1 < n) {
		if (t[r] < t[2 * r + 1]) {
			flag = false;
			// return;
		}
	}
	if (2 * r + 2 < n) {
		if (t[r] < t[2 * r + 2]) {
			flag = false;
			// return;
		}
	}
	dfsmaxheap(2 * r + 1, n, flag);
	dfsmaxheap(2 * r + 2, n, flag);
	post.push_back(t[r]);
}

void dfsminheap(int r, int n, bool &flag) {
	if (r >= n) {
		return;
	}
	if (2 * r + 1 < n) {
		if (t[r] > t[2 * r + 1]) {
			flag = false;
			// return;
		}
	}
	if (2 * r + 2 < n) {
		if (t[r] > t[2 * r + 2]) {
			flag = false;
			// return;
		}
	}
	dfsminheap(2 * r + 1, n, flag);
	dfsminheap(2 * r + 2, n, flag);
	post.push_back(t[r]);
}

int main(int argc, char const *argv[]) {

	int m, n;
	cin >> m >> n;
	for (int q = 0; q < m; q++) {
		t.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> t[i];
		}
		bool ismaxheap = true;
		bool isminheap = true;
		if (t[0] > t[1]) {
			dfsmaxheap(0, n, ismaxheap);
			if (ismaxheap) {
				cout << "Max Heap\n";
			}
		} else {
			dfsminheap(0, n, isminheap);
			if (isminheap) {
				cout << "Min Heap\n";
			}
		}
		if (!isminheap || !ismaxheap) {
			cout << "Not Heap" << "\n";
		}
		for (int i = 0; i < n; i++) {
			cout << post[i];
			if (i < n - 1) {
				cout << " ";
			} else {
				cout << "\n";
			}
		}
		post.clear();
	}
	
	return 0;
}