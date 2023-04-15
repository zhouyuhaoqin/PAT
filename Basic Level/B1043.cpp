/*
*	author:		zhouyuhao
*	created:	2023-03-25 21:38:38
*	modified:	2023-03-25 21:47:37
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

	string a;
	cin >> a;
	vector<int> count(6);
	for (int i = 0; i < a.size(); i++) {
		switch (a[i]) {
			case 'P':
				count[0]++;
				break;
			case 'A':
				count[1]++;
				break;
			case 'T':
				count[2]++;
				break;
			case 'e':
				count[3]++;
				break;
			case 's':
				count[4]++;
				break;
			case 't':
				count[5]++;
				break;		
		}
	}
	int total = -1;
	for (auto it : count) {
		total = max(it, total);
	}
	char symbol[6] = {'P', 'A', 'T', 'e', 's', 't'};
	for (int i = 0; i < total; i++) {
		for (int j = 0; j < 6; j++) {
			if (count[j] != 0) {
				cout << symbol[j];
				count[j]--;
			}
		}
	}
	cout << "\n";
	
	return 0;
}