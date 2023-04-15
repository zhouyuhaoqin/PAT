/*
*	author:		zhouyuhao
*	created:	2023-04-04 21:01:12
*	modified:	2023-04-04 21:34:34
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> t, path;

void dfs(int r, int n) {
	if (2 * r + 1 >= n && 2 * r + 1 >= n) {
		path.push_back(t[r]);
		for (int i = 0; i < path.size(); i++) {
			cout << path[i];
			if (i < path.size() - 1) {
				cout << " ";
			} else {
				cout << "\n";
			}
		}
		path.pop_back();
		return;
	}
	if (2 * r + 2 < n) {
		path.push_back(t[r]);
		dfs(2 * r + 2, n);
		path.pop_back();
	}
	if (2 * r + 1 < n) {
		path.push_back(t[r]);
		dfs(2 * r + 1, n);
		path.pop_back();
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	t.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	dfs(0, n);
	bool ismaxheap = true;
	bool isminheap = true;
	if (t[0] > t[1]) {
		for (int i = 0; i < n / 2; i++) {
			if (2 * i + 1 < n && t[2 * i + 1] > t[i]) {
				ismaxheap = false;
				break;
			}
			if (2 * i + 2 < n && t[2 * i + 2] > t[i]) {
				ismaxheap = false;
				break;
			}
		}
		if (ismaxheap) {
			cout << "Max Heap\n";
		}
	} else {
		for (int i = 0; i < n / 2; i++) {
			if (2 * i + 1 < n && t[2 * i + 1] < t[i]) {
				isminheap = false;
				break;
			}
			if (2 * i + 2 < n && t[2 * i + 2] < t[i]) {
				isminheap = false;
				break;
			}
		}
		if (isminheap) {
			cout << "Min Heap\n";
		}
	}
	if (!(ismaxheap && isminheap)) {
		cout << "Not Heap\n";
	}
	
	return 0;
}