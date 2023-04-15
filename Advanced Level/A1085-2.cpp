/*
*	author:		zhouyuhao
*	created:	2023-03-27 13:15:10
*	modified:	2023-03-27 13:26:04
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, p;
	cin >> n >> p;
	vector<long long int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	int ans = 1;
	int i = 0, j = 0;
	while (i < n && j < n) {
		while (j < n && d[j] <= d[i] * p) {
			j++;
		}
		ans = max(ans, j - i);
		i++;
	}
	cout << ans << "\n";
	
	return 0;
}

/*
//from two side to middle, 
//every time is shorter, 
//but not is longest.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, p;
	cin >> n >> p;
	vector<long long int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	int ans = 1;
	for (int i = 0, j = n - 1; i < n && j >= 0 && i <= j; i++, j--) {
		if (d[i] * p >= d[j]) {
			ans = max(ans, j - i + 1);
			break;
		} else if (d[i + 1] * p >= d[j]) {
			ans = max(ans, j - i);
			break;
		} else if (d[i] * p >= d[j - 1]) {
			ans = max(ans, j - i);
			break;
		}
	}
	cout << ans << "\n";
	
	return 0;
}
*/