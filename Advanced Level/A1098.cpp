/*
*	author:		zhouyuhao
*	created:	2023-03-29 23:46:48
*	modified:	2023-03-30 00:26:53
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void downa(vector<int> &heap, int l, int h) {
	int i = l, j = 2 * i + 1;
	while (j <= h) {
		if (j + 1 <= h && heap[j + 1] > heap[j]) {
			j = j + 1;
		}
		if (heap[j] > heap[i]) {
			swap(heap[i], heap[j]);
			i = j;
			j = 2 * i + 1;
		} else {
			break;
		}
	}
}

void print(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i < v.size() - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> d1(n), d2(n);
	for (int i = 0; i < n; i++) {
		cin >> d1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> d2[i];
	}
	vector<int> d3(d1);
	for (int i = 2; i < n; i++) {
		sort(d3.begin(), d3.begin() + i);
		if (d3 == d2) {
			cout << "Insertion Sort\n";
			sort(d3.begin(), d3.begin() + i + 1);
			print(d3);
			return 0;
		}
	}
	cout << "Heap Sort\n";
	int i = n - 1;
	while (i > 0 && d2[i] > d2[0]) {
		i--;
	}
	swap(d2[0], d2[i]);
	downa(d2, 0, i - 1);
	print(d2);
	
	return 0;
}