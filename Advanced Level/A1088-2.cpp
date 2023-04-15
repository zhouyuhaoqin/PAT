/*
*	author:		zhouyuhao
*	created:	2023-04-11 23:18:35
*	modified:	2023-04-11 23:56:28
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

void func(ll a, ll b) {
	if (a * b == 0) {
		!b ? cout << "Inf" : cout << "0";
		return;
	}
	bool sign = ((a < 0 && b > 0) || (a > 0 && b < 0));
	a = abs(a), b = abs(b);
	ll i = a / b;
	sign ? cout << "(-" : cout << "";
	if (i != 0) {
		cout << i;
	}
	if (a % b == 0) {
		if (sign) {
			cout << ")";
		}
		return;
	}
	if (i != 0) {
		cout << " ";
	}
	a = a - i * b;
	ll g = gcd(a, b);
	a /= g, b /= g;
	cout << a << "/" << b, sign ? cout << ")" : cout << "";
}

int main(int argc, char const *argv[]) {

	ll a, b, c, d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	func(a, b), cout << " + ", func(c, d), cout << " = ", func(a * d + b * c, b * d), cout << "\n";
	func(a, b), cout << " - ", func(c, d), cout << " = ", func(a * d - b * c, b * d), cout << "\n";
	func(a, b), cout << " * ", func(c, d), cout << " = ", func(a * c, b * d), cout << "\n";
	func(a, b), cout << " / ", func(c, d), cout << " = ", func(a * d, b * c), cout << "\n";

	return 0;
}