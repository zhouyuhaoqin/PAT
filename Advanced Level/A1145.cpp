/*
*	author:		zhouyuhao
*	created:	2023-04-04 14:26:03
*	modified:	2023-04-04 15:08:41
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

bool isprime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 00) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {

	int msize, n, m;
	cin >> msize >> n >> m;
	while (!isprime(msize)) {
		msize++;
	}
	vector<int> hashtable(msize);
	for (int i = 0; i < n; i++) {
		int key;
		cin >> key;
		if (hashtable[key % msize] == 0) {
			hashtable[key % msize] = key;
		} else {
			bool isinserted = false;
			for (int j = 1; j <= msize; j++) {
				int hashkey = (key % msize + (int) pow(j, 2)) % msize;
				if (hashtable[hashkey] == 0) {
					hashtable[hashkey] = key;
					isinserted = true;
					break;
				}
			}
			if (!isinserted) {
				cout << key << " cannot be inserted.\n";
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int key;
		cin >> key;
		cnt++;
		if (hashtable[key % msize] != key && hashtable[key % msize] != 0) {
			for (int j = 1; j <= msize; j++) {
				cnt++;
				int hashkey = (key % msize + (int) pow(j, 2)) % msize;
				if (hashtable[hashkey] == key || hashtable[hashkey] == 0) {
					break;
				}
			}
		}
	}
	cout << fixed << setprecision(1) << (double) cnt / m << "\n";
	
	return 0;
}