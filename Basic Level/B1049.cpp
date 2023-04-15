/*
*	author:		zhouyuhao
*	created:	2023-04-11 10:02:16
*	modified:	2023-04-11 10:02:27
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/

//A1104

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	long double sum = 0;
	for (int i = 0; i < n; i++) {
		long double v;
		cin >> v;
		sum += v * (i + 1) * (n - i);
	}
	cout << fixed << setprecision(2) << sum << "\n";
	
	return 0;
}