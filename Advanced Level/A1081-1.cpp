/*
*	author:		zhouyuhao
*	created:	2023-04-11 20:35:38
*	modified:	2023-04-11 21:20:11
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>

using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	ll sumnum = 0, sumden = 1;
	for (int i = 0; i < n; i++) {
		ll num, den;
		scanf("%lld/%lld", &num, &den);
		sumnum = sumnum * den + num * sumden;
		sumden *= den;
		int g = gcd(sumnum, sumden);
		sumnum /= g;
		sumden /= g;
	}
	if (sumnum >= sumden) {
		cout << sumnum / sumden;
		if (sumnum % sumden != 0) {
			cout << " " << sumnum - sumnum / sumden * sumden << "/" << sumden;
		}
		cout << "\n";
	} else {
		if (sumnum != 0) {
			cout << sumnum << "/" << sumden << "\n";
		} else {
			cout << "0\n";
		}
	}
	
	return 0;
}