/*
*	author:		zhouyuhao
*	created:	2023-03-22 20:26:50
*	modified:	2023-03-22 20:40:06
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {

	float o[3][3];
	int buy[3];
	for (int i = 0; i < 3; i++) {
		int id = -1;
		float high = -1;
		for (int j = 0; j < 3; j++) {
			cin >> o[i][j];
			if (o[i][j] > high) {
				high = o[i][j];
				id = j;
			}
		}
		buy[i] = id;
	}
	char ch[3] = {'W', 'T', 'L'};
	float result = 1;
	for (int i = 0; i < 3; i++) {
		cout << ch[buy[i]] << " ";
		result *= o[i][buy[i]];
	}
	result = (result * 0.65 - 1) * 2;
	cout << fixed << setprecision(2) << result << "\n";

	return 0;
}