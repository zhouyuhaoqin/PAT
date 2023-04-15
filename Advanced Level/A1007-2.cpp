/*
*	author:		zhouyuhao
*	created:	2023-04-12 08:14:44
*	modified:	2023-04-12 09:56:29
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int k;
	cin >> k;
	vector<int> d(k);
	int sum = -1, temp = 0, l = 0, r = k - 1, tl = 0;
	for (int i = 0; i < k; i++) {
		cin >> d[i];
		temp += d[i];
		if (temp < 0) {
			temp = 0;
			tl = i + 1;
		} else if (temp > sum) {
			sum = temp;
			l = tl;
			r = i;
		}
	}
	if (sum == -1) {
		sum = 0;
	}
	cout << sum  << " " << d[l] << " " << d[r] << "\n";
	
	return 0;
}