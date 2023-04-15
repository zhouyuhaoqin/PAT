/*
*	author:		zhouyuhao
*	created:	2023-03-25 21:48:03
*	modified:	2023-03-25 21:52:11
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<int, int> score;
	int h = -1, id = -1;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d-%d %d", &a, &b, &c);
		score[a] += c;
		if (score[a] > h) {
			h = score[a];
			id = a;
		}
	}
	cout << id << " " << h << "\n";
	
	return 0;
}